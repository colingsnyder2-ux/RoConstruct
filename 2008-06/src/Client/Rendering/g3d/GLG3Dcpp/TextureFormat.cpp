/**
 @file TextureFormat.cpp
 
 @maintainer Morgan McGuire, morgan@graphics3d.com
 
 @created 2003-05-23
 @edited  2006-01-11
 */

#include "GLG3D/TextureFormat.h"
#include "GLG3D/glheaders.h"
#include "GLG3D/glcalls.h"

namespace G3D {
static bool INT = false;
static bool FLOAT = true;
static bool OPAQUEx = true;
 
const TextureFormat* TextureFormat::L8        = new TextureFormat(1, false, GL_LUMINANCE8, GL_LUMINANCE, 8, 0, 0, 0, 0, 0, 0, 8, 8, OPAQUEx, INT, TextureFormat::CODE_L8, TextureFormat::COLOR_SPACE_NONE);

const TextureFormat* TextureFormat::L16       = new TextureFormat(1, false, GL_LUMINANCE16, GL_LUMINANCE, 16, 0, 0, 0, 0, 0, 0, 16, 16, OPAQUEx, INT, TextureFormat::CODE_L16, TextureFormat::COLOR_SPACE_NONE);

const TextureFormat* TextureFormat::L16F      = new TextureFormat(1, false, GL_LUMINANCE16F_ARB, GL_LUMINANCE, 16, 0, 0, 0, 0, 0, 0, 16, 16, OPAQUEx, FLOAT, TextureFormat::CODE_L16F, TextureFormat::COLOR_SPACE_NONE);

const TextureFormat* TextureFormat::L32F      = new TextureFormat(1, false, GL_LUMINANCE32F_ARB, GL_LUMINANCE, 32, 0, 0, 0, 0, 0, 0, 32, 32, OPAQUEx, FLOAT, TextureFormat::CODE_L32F, TextureFormat::COLOR_SPACE_NONE);

const TextureFormat* TextureFormat::A8        = new TextureFormat(1, false, GL_ALPHA8, GL_ALPHA, 0, 8, 0, 0, 0, 0, 0, 8, 8, !OPAQUEx, INT, TextureFormat::CODE_A8, TextureFormat::COLOR_SPACE_NONE);

const TextureFormat* TextureFormat::A16       = new TextureFormat(1, false, GL_ALPHA16, GL_ALPHA, 0, 16, 0, 0, 0, 0, 0, 16, 16, !OPAQUEx, INT, TextureFormat::CODE_A16, TextureFormat::COLOR_SPACE_NONE);

const TextureFormat* TextureFormat::A16F      = new TextureFormat(1, false, GL_ALPHA16F_ARB, GL_ALPHA, 0, 16, 0, 0, 0, 0, 0, 16, 16, !OPAQUEx, FLOAT, TextureFormat::CODE_A16F, TextureFormat::COLOR_SPACE_NONE);

const TextureFormat* TextureFormat::A32F      = new TextureFormat(1, false, GL_ALPHA32F_ARB, GL_ALPHA, 0, 32, 0, 0, 0, 0, 0, 32, 32, !OPAQUEx, FLOAT, TextureFormat::CODE_A32F, TextureFormat::COLOR_SPACE_NONE);

const TextureFormat* TextureFormat::LA4       = new TextureFormat(2, false, GL_LUMINANCE4_ALPHA4, GL_LUMINANCE_ALPHA, 4, 4, 0, 0, 0, 0, 0, 8, 8, !OPAQUEx, INT, TextureFormat::CODE_LA4, TextureFormat::COLOR_SPACE_NONE);
 
const TextureFormat* TextureFormat::LA8       = new TextureFormat(2, false, GL_LUMINANCE8_ALPHA8, GL_LUMINANCE_ALPHA, 8, 8, 0, 0, 0, 0, 0, 16, 16, !OPAQUEx, INT, TextureFormat::CODE_LA8, TextureFormat::COLOR_SPACE_NONE);

const TextureFormat* TextureFormat::LA16      = new TextureFormat(2, false, GL_LUMINANCE16_ALPHA16, GL_LUMINANCE_ALPHA, 16, 16, 0, 0, 0, 0, 0, 16*2, 16*2, !OPAQUEx, INT, TextureFormat::CODE_LA16, TextureFormat::COLOR_SPACE_NONE);

const TextureFormat* TextureFormat::LA16F     = new TextureFormat(2, false, GL_LUMINANCE_ALPHA16F_ARB, GL_LUMINANCE_ALPHA, 16, 16, 0, 0, 0, 0, 0, 16*2, 16*2, !OPAQUEx, FLOAT, TextureFormat::CODE_LA16F, TextureFormat::COLOR_SPACE_NONE);

const TextureFormat* TextureFormat::LA32F     = new TextureFormat(2, false, GL_LUMINANCE_ALPHA32F_ARB, GL_LUMINANCE_ALPHA, 32, 32, 0, 0, 0, 0, 0, 32*2, 32*2, !OPAQUEx, FLOAT, TextureFormat::CODE_LA32F, TextureFormat::COLOR_SPACE_NONE);

const TextureFormat* TextureFormat::RGB5      = new TextureFormat(3, false, GL_RGB5, GL_RGBA, 0, 0, 5, 5, 5, 0, 0, 16, 16, OPAQUEx, INT, TextureFormat::CODE_RGB5, TextureFormat::COLOR_SPACE_RGB);

const TextureFormat* TextureFormat::RGB5A1    = new TextureFormat(4, false, GL_RGB5_A1, GL_RGBA, 0, 1, 5, 5, 5, 0, 0, 16, 16, OPAQUEx, INT, TextureFormat::CODE_RGB5A1, TextureFormat::COLOR_SPACE_RGB);

const TextureFormat* TextureFormat::RGB8      = new TextureFormat(3, false, GL_RGB8, GL_RGB, 0, 0, 8, 8, 8, 0, 0, 24, 32, OPAQUEx, INT, TextureFormat::CODE_RGB8, TextureFormat::COLOR_SPACE_RGB);

const TextureFormat* TextureFormat::RGB16     = new TextureFormat(3, false, GL_RGB16, GL_RGB, 0, 0, 16, 16, 16, 0, 0, 16*3, 16*3, OPAQUEx, INT, TextureFormat::CODE_RGB16, TextureFormat::COLOR_SPACE_RGB);

const TextureFormat* TextureFormat::RGB16F    = new TextureFormat(3, false, GL_RGB16F_ARB, GL_RGB, 0, 0, 16, 16, 16, 0, 0, 16*3, 16*3, OPAQUEx, FLOAT, TextureFormat::CODE_RGB16F, TextureFormat::COLOR_SPACE_RGB);

const TextureFormat* TextureFormat::RGB32F    = new TextureFormat(3, false, GL_RGB32F_ARB, GL_RGB, 0, 0, 32, 32, 32, 0, 0, 32*3, 32*3, OPAQUEx, FLOAT, TextureFormat::CODE_RGB32F, TextureFormat::COLOR_SPACE_RGB);

const TextureFormat* TextureFormat::RGBA8     = new TextureFormat(4, false, GL_RGBA8, GL_RGBA, 0, 8, 8, 8, 8, 0, 0, 32, 32, false, INT, TextureFormat::CODE_RGBA8, TextureFormat::COLOR_SPACE_RGB);

const TextureFormat* TextureFormat::RGBA16    = new TextureFormat(4, false, GL_RGBA16, GL_RGBA, 0, 16, 16, 16, 16, 0, 0, 16*4, 16*4, false, INT, TextureFormat::CODE_RGBA16, TextureFormat::COLOR_SPACE_RGB);

const TextureFormat* TextureFormat::RGBA16F   = new TextureFormat(4, false, GL_RGBA16F_ARB, GL_RGBA, 0, 16, 16, 16, 16, 0, 0, 16*4, 16*4, false, FLOAT, TextureFormat::CODE_RGB16F, TextureFormat::COLOR_SPACE_RGB);

const TextureFormat* TextureFormat::RGBA32F   = new TextureFormat(4, false, GL_RGBA32F_ARB, GL_RGBA, 0, 32, 32, 32, 32, 0, 0, 32*4, 32*4, false, FLOAT, TextureFormat::CODE_RGBA32F, TextureFormat::COLOR_SPACE_RGB);

const TextureFormat* TextureFormat::RGB_DXT1  = new TextureFormat(3, true, GL_COMPRESSED_RGB_S3TC_DXT1_EXT, GL_RGB, 0, 0, 0, 0, 0, 0, 0, 64, 64, OPAQUEx, INT, TextureFormat::CODE_RGB_DXT1, TextureFormat::COLOR_SPACE_RGB);

const TextureFormat* TextureFormat::RGBA_DXT1 = new TextureFormat(4, true, GL_COMPRESSED_RGBA_S3TC_DXT1_EXT, GL_RGBA, 0, 0, 0, 0, 0, 0, 0, 64, 64, !OPAQUEx, INT, TextureFormat::CODE_RGBA_DXT1, TextureFormat::COLOR_SPACE_RGB);

const TextureFormat* TextureFormat::RGBA_DXT3 = new TextureFormat(4, true, GL_COMPRESSED_RGBA_S3TC_DXT3_EXT, GL_RGBA, 0, 0, 0, 0, 0, 0, 0, 128, 128, !OPAQUEx, INT, TextureFormat::CODE_RGBA_DXT3, TextureFormat::COLOR_SPACE_RGB);

const TextureFormat* TextureFormat::RGBA_DXT5 = new TextureFormat(4, true, GL_COMPRESSED_RGBA_S3TC_DXT5_EXT, GL_RGBA, 0, 0, 0, 0, 0, 0, 0, 128, 128, !OPAQUEx, INT, TextureFormat::CODE_RGBA_DXT5, TextureFormat::COLOR_SPACE_RGB);

const TextureFormat* TextureFormat::DEPTH16   = new TextureFormat(1, false, GL_DEPTH_COMPONENT16_ARB, GL_DEPTH_COMPONENT, 0, 0, 0, 0, 0, 0, 16, 16, 16, !OPAQUEx, INT, TextureFormat::CODE_DEPTH16, TextureFormat::COLOR_SPACE_NONE);

const TextureFormat* TextureFormat::DEPTH24   = new TextureFormat(1, false, GL_DEPTH_COMPONENT24_ARB, GL_DEPTH_COMPONENT, 0, 0, 0, 0, 0, 0, 24, 32, 24, !OPAQUEx, INT, TextureFormat::CODE_DEPTH24, TextureFormat::COLOR_SPACE_NONE);

const TextureFormat* TextureFormat::DEPTH32   = new TextureFormat(1, false, GL_DEPTH_COMPONENT32_ARB, GL_DEPTH_COMPONENT, 0, 0, 0, 0, 0, 0, 32, 32, 32, !OPAQUEx, INT, TextureFormat::CODE_DEPTH32, TextureFormat::COLOR_SPACE_NONE);

// These formats are for use with Renderbuffers only!
const TextureFormat* TextureFormat::STENCIL1 = new TextureFormat(1, false, GL_STENCIL_INDEX1_EXT, GL_STENCIL_INDEX_EXT, 0, 0, 0, 0, 0, 0, 1, 1, 1, !OPAQUEx, INT, TextureFormat::CODE_STENCIL1, TextureFormat::COLOR_SPACE_NONE);
	
const TextureFormat* TextureFormat::STENCIL4 = new TextureFormat(1, false, GL_STENCIL_INDEX4_EXT, GL_STENCIL_INDEX_EXT, 0, 0, 0, 0, 0, 0, 4, 4, 4, !OPAQUEx, INT, TextureFormat::CODE_STENCIL4, TextureFormat::COLOR_SPACE_NONE);
	
const TextureFormat* TextureFormat::STENCIL8 = new TextureFormat(1, false, GL_STENCIL_INDEX8_EXT, GL_STENCIL_INDEX_EXT, 0, 0, 0, 0, 0, 0, 8, 8, 8, !OPAQUEx, INT, TextureFormat::CODE_STENCIL8, TextureFormat::COLOR_SPACE_NONE);
	
const TextureFormat* TextureFormat::STENCIL16 = new TextureFormat(1, false, GL_STENCIL_INDEX16_EXT, GL_STENCIL_INDEX_EXT, 0, 0, 0, 0, 0, 0, 16, 16, 16, !OPAQUEx, INT, TextureFormat::CODE_STENCIL16, TextureFormat::COLOR_SPACE_NONE);

const TextureFormat* TextureFormat::AUTO      = NULL;

bool TextureFormat::valid = true;

const TextureFormat* TextureFormat::depth(int depthBits) {

    if (depthBits == SAME_AS_SCREEN) {
        // Detect screen depth
        depthBits = glGetInteger(GL_DEPTH_BITS);
    }

    switch (depthBits) {
    case 16:
        return DEPTH16;

    case 24:
        return DEPTH24;

    case 32:
        return DEPTH32;

    default:
        debugAssertM(false, "Depth must be 16, 24, or 32.");
        return DEPTH32;
    }
}

const TextureFormat* TextureFormat::stencil(int bits) {

    if (bits == SAME_AS_SCREEN) {
        // Detect screen depth
        bits = glGetInteger(GL_STENCIL_BITS);
    }

    switch (bits) {
    case 1:
        return STENCIL1;

    case 4:
        return STENCIL4;

    case 8:
        return STENCIL8;

    case 16:
        return STENCIL16;

    default:
        debugAssertM(false, "Stencil must be 1, 4, 8 or 16.");
        return STENCIL16;
    }
}

const TextureFormat* fromCode(TextureFormat::Code code) {
    switch (code) {
    case TextureFormat::CODE_L8:
        return TextureFormat::L8;
        break;
    case TextureFormat::CODE_L16:
        return TextureFormat::L16;
        break;
    case TextureFormat::CODE_L16F:
        return TextureFormat::L16F;
        break;
    case TextureFormat::CODE_L32F:
        return TextureFormat::L32F;
        break;

    case TextureFormat::CODE_A8:
        return TextureFormat::A8;
        break;
    case TextureFormat::CODE_A16:
        return TextureFormat::A16;
        break;
    case TextureFormat::CODE_A16F:
        return TextureFormat::A16F;
        break;
    case TextureFormat::CODE_A32F:
        return TextureFormat::A32F;
        break;

    case TextureFormat::CODE_LA4:
        return TextureFormat::LA4;
        break;
    case TextureFormat::CODE_LA8:
        return TextureFormat::LA8;
        break;
    case TextureFormat::CODE_LA16:
        return TextureFormat::LA16;
        break;
    case TextureFormat::CODE_LA16F:
        return TextureFormat::LA16F;
        break;
    case TextureFormat::CODE_LA32F:
        return TextureFormat::LA32F;
        break;

    case TextureFormat::CODE_RGB5:
        return TextureFormat::RGB5;
        break;
    case TextureFormat::CODE_RGB5A1:
        return TextureFormat::RGB5A1;
        break;
    case TextureFormat::CODE_RGB8:
        return TextureFormat::RGB8;
        break;
    case TextureFormat::CODE_RGB16:
        return TextureFormat::RGB16;
        break;
    case TextureFormat::CODE_RGB16F:
        return TextureFormat::RGB16F;
        break;
    case TextureFormat::CODE_RGB32F:
        return TextureFormat::RGB32F;
        break;

    case TextureFormat::CODE_ARGB8:
        debugAssertM(TextureFormat::AUTO, "Unsupported TextureFormat at decoding.");
        return TextureFormat::AUTO;
        break;
    case TextureFormat::CODE_BGR8:
        debugAssertM(TextureFormat::AUTO, "Unsupported TextureFormat at decoding.");
        return TextureFormat::AUTO;
        break;

    case TextureFormat::CODE_RGBA8:
        return TextureFormat::RGBA8;
        break;
    case TextureFormat::CODE_RGBA16:
        return TextureFormat::RGBA16;
        break;
    case TextureFormat::CODE_RGBA16F:
        return TextureFormat::RGBA16F;
        break;
    case TextureFormat::CODE_RGBA32F:
        return TextureFormat::RGBA32F;
        break;

    case TextureFormat::CODE_BAYER_RGGB8:
    case TextureFormat::CODE_BAYER_GRBG8:
    case TextureFormat::CODE_BAYER_GBRG8:
    case TextureFormat::CODE_BAYER_BGGR8:
    case TextureFormat::CODE_BAYER_RGGB32F:
    case TextureFormat::CODE_BAYER_GRBG32F:
    case TextureFormat::CODE_BAYER_GBRG32F:
    case TextureFormat::CODE_BAYER_BGGR32F:

    case TextureFormat::CODE_HSV8:
    case TextureFormat::CODE_HSV32F:

    case TextureFormat::CODE_YUV8:
    case TextureFormat::CODE_YUV32F:
        debugAssertM(TextureFormat::AUTO, "Unsupported TextureFormat at decoding.");
        return TextureFormat::AUTO;
        break;

    case TextureFormat::CODE_RGB_DXT1:
        return TextureFormat::RGB_DXT1;
        break;
    case TextureFormat::CODE_RGBA_DXT1:
        return TextureFormat::RGBA_DXT1;
        break;
    case TextureFormat::CODE_RGBA_DXT3:
        return TextureFormat::RGBA_DXT3;
        break;
    case TextureFormat::CODE_RGBA_DXT5:
        return TextureFormat::RGBA_DXT5;
        break;

    case TextureFormat::CODE_DEPTH16:
        return TextureFormat::DEPTH16;
        break;
    case TextureFormat::CODE_DEPTH24:
        return TextureFormat::DEPTH24;
        break;
    case TextureFormat::CODE_DEPTH32:
        return TextureFormat::DEPTH32;
        break;

    case TextureFormat::CODE_STENCIL1:
        return TextureFormat::STENCIL1;
        break;
    case TextureFormat::CODE_STENCIL4:
        return TextureFormat::STENCIL4;
        break;
    case TextureFormat::CODE_STENCIL8:
        return TextureFormat::STENCIL8;
        break;
    case TextureFormat::CODE_STENCIL16:
        return TextureFormat::STENCIL16;
        break;

    default:
        return NULL;
    }
}


static class TextureFormatCleanup {
public:

	~TextureFormatCleanup() {
		TextureFormat::valid = false;

        delete const_cast<TextureFormat*>(TextureFormat::L8);

        delete const_cast<TextureFormat*>(TextureFormat::L16);

        delete const_cast<TextureFormat*>(TextureFormat::L16F);
    
        delete const_cast<TextureFormat*>(TextureFormat::L32F);

        delete const_cast<TextureFormat*>(TextureFormat::A8);

        delete const_cast<TextureFormat*>(TextureFormat::A16);

        delete const_cast<TextureFormat*>(TextureFormat::A16F);
    
        delete const_cast<TextureFormat*>(TextureFormat::A32F);

        delete const_cast<TextureFormat*>(TextureFormat::LA4);

        delete const_cast<TextureFormat*>(TextureFormat::LA8);

        delete const_cast<TextureFormat*>(TextureFormat::LA16);

        delete const_cast<TextureFormat*>(TextureFormat::LA16F);
    
        delete const_cast<TextureFormat*>(TextureFormat::LA32F);

        delete const_cast<TextureFormat*>(TextureFormat::RGB5);

        delete const_cast<TextureFormat*>(TextureFormat::RGB5A1);

        delete const_cast<TextureFormat*>(TextureFormat::RGB8);

        delete const_cast<TextureFormat*>(TextureFormat::RGB16);

        delete const_cast<TextureFormat*>(TextureFormat::RGB16F);

        delete const_cast<TextureFormat*>(TextureFormat::RGB32F);

        delete const_cast<TextureFormat*>(TextureFormat::RGBA8);

        delete const_cast<TextureFormat*>(TextureFormat::RGBA16);

        delete const_cast<TextureFormat*>(TextureFormat::RGBA16F);
    
        delete const_cast<TextureFormat*>(TextureFormat::RGBA32F);
    
        delete const_cast<TextureFormat*>(TextureFormat::RGB_DXT1);

        delete const_cast<TextureFormat*>(TextureFormat::RGBA_DXT1);

        delete const_cast<TextureFormat*>(TextureFormat::RGBA_DXT3);

        delete const_cast<TextureFormat*>(TextureFormat::RGBA_DXT5);

        delete const_cast<TextureFormat*>(TextureFormat::DEPTH16);

        delete const_cast<TextureFormat*>(TextureFormat::DEPTH24);

        delete const_cast<TextureFormat*>(TextureFormat::DEPTH32);

        delete const_cast<TextureFormat*>(TextureFormat::STENCIL1);

        delete const_cast<TextureFormat*>(TextureFormat::STENCIL4);

        delete const_cast<TextureFormat*>(TextureFormat::STENCIL8);

        delete const_cast<TextureFormat*>(TextureFormat::STENCIL16);
	}
} _textureFormatCleanup;

}
