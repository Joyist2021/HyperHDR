#pragma once

#include <utils/PixelFormat.h>
#include <utils/Image.h>
#include <utils/ColorRgb.h>


// some stuff for HDR tone mapping
#define LUT_INDEX(y,u,v) ((y + (u<<8) + (v<<16))*3)

class ImageResampler
{
	public:
		static void processImage(
			int _cropLeft, int _cropRight, int _cropTop, int _cropBottom,			
			const uint8_t * data, int width, int height, int lineLength,
			const PixelFormat pixelFormat, const uint8_t *lutBuffer, Image<ColorRgb>& outputImage);

		static void processQImage(		
			const uint8_t* data, int width, int height, int lineLength,
			const PixelFormat pixelFormat, const uint8_t* lutBuffer, Image<ColorRgb>& outputImage);

		static void processSystemImageBGRA(Image<ColorRgb>& image, int targetSizeX, int targetSizeY,
			int startX, int startY,
			uint8_t* source, int _actualWidth, int _actualHeight,
			int division, uint8_t* _lutBuffer, int lineSize = 0);

		static void applyLUT(uint8_t* _source, unsigned int width, unsigned int height, const uint8_t* lutBuffer, const int _hdrToneMappingEnabled);
};

