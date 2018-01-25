#include "SpriteSheet.h"

SpriteSheet::SpriteSheet(wchar_t const *filename, Graphics* gfx)
{
	this->gfx = gfx;
	bmp = NULL;
	HRESULT hr;

	IWICImagingFactory* wicFactory = NULL;
	hr = CoCreateInstance(
		CLSID_WICImagingFactory,
		NULL,
		CLSCTX_INPROC_SERVER,
		IID_IWICImagingFactory,
		(LPVOID*)&wicFactory);

	IWICBitmapDecoder* wicDecoder = NULL;
	hr = wicFactory->CreateDecoderFromFilename(
		filename,
		NULL,
		GENERIC_READ,
		WICDecodeMetadataCacheOnLoad,
		&wicDecoder);

	IWICBitmapFrameDecode* wicFrame = NULL;
	hr = wicDecoder->GetFrame(0, &wicFrame);

	IWICFormatConverter *wicConverter = NULL;
	hr = wicFactory->CreateFormatConverter(&wicConverter);


	hr = wicConverter->Initialize(
		wicFrame,
		GUID_WICPixelFormat32bppPBGRA,
		WICBitmapDitherTypeNone,
		NULL,
		0.0,
		WICBitmapPaletteTypeCustom);

	gfx->getRenderTarget()->CreateBitmapFromWicBitmap(
		wicConverter,
		NULL,
		&bmp);

	if (wicFactory) wicFactory->Release();
	if (wicDecoder) wicDecoder->Release();
	if (wicConverter) wicConverter->Release();
	if (wicFrame) wicFrame->Release();

	spriteWidth = bmp->GetSize().width;
	spriteHeight = bmp->GetSize().height;
	spritesAccross = 1;
}

SpriteSheet::SpriteSheet(wchar_t const* filename, Graphics* gfx, int spriteWidth, int spriteHeight) :
SpriteSheet(filename, gfx)
{
	this->spriteWidth = spriteWidth;
	this->spriteHeight = spriteHeight;
	this->spritesAccross = (int)bmp->GetSize().width / spriteWidth;
}


SpriteSheet::~SpriteSheet()
{
	if (bmp) bmp->Release();
}

void SpriteSheet::draw(float opacity)
{
	

	gfx->getRenderTarget()->DrawBitmap(
		bmp,
		D2D1::RectF(0.0f, 0.0f,							//destination rectangle
		bmp->GetSize().width, bmp->GetSize().height),
		opacity,											//opacity
		D2D1_BITMAP_INTERPOLATION_MODE::D2D1_BITMAP_INTERPOLATION_MODE_LINEAR,
		D2D1::RectF(0.0f, 0.0f,							//source rectangle
		bmp->GetSize().width, bmp->GetSize().height));

}
void SpriteSheet::draw(int index, float x, float y, float opacity)
{

	D2D_RECT_F src = D2D1::RectF(
		(float)((index % spritesAccross)*spriteWidth),
		(float)((index / spritesAccross)*spriteHeight),
		(float)((index % spritesAccross)*spriteWidth) + spriteWidth,
		(float)((index / spritesAccross)*spriteHeight) + spriteHeight);

	D2D1_RECT_F dest;

	dest = D2D1::RectF(
	x, y,
	x + spriteWidth * 2,
	y + spriteHeight * 2);
	
	gfx->getRenderTarget()->DrawBitmap(
		bmp,
		dest,
		opacity,											//opacity
		D2D1_BITMAP_INTERPOLATION_MODE::D2D1_BITMAP_INTERPOLATION_MODE_NEAREST_NEIGHBOR,
		src);
}

void SpriteSheet::flip()
{

}