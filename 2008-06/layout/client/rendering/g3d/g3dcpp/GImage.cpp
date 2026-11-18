// 2008-06 native G3DGImage (inactive): upstream tools/libs/g3d-6.09/source/G3Dcpp/GImage.cpp, verbatim.
#line 1 ".\\G3Dcpp\\GImage.cpp"
/**
  @file GImage.cpp
  @author Morgan McGuire, morgan@graphics3d.com
  @created 2002-05-27
  @edited  2006-02-10
 */
#include "G3D/platform.h"
#include "G3D/GImage.h"
#include "G3D/debug.h"
#include "G3D/stringutils.h"
#include "G3D/TextInput.h"
#include "G3D/TextOutput.h"
#include "G3D/BinaryInput.h"
#include "G3D/BinaryOutput.h"
#include "G3D/Log.h"

#include "../png/png.h"
#include <sys/stat.h>
#include <assert.h>
#include <sys/types.h>

//////////////////////////////////////////////////////////////////////////////////////////////

namespace G3D {
   
void GImage::RGBtoRGBA(
    const uint8*    in,
    uint8*          out,
    int                     numPixels) {

    for (int i = 0; i < numPixels; ++i) {
        int i3 = i * 3;
        int i4 = i3 + i;

        out[i4 + 0] = in[i3 + 0]; 
        out[i4 + 1] = in[i3 + 1]; 
        out[i4 + 2] = in[i3 + 2]; 
        out[i4 + 3] = 255; 
    }
}


void GImage::RGBtoBGRA(
    const uint8*    in,
    uint8*          out,
    int                     numPixels) {

    for (int i = 0; i < numPixels; ++i) {
        int i3 = i * 3;
        int i4 = i3 + i;

        out[i4 + 2] = in[i3 + 0]; 
        out[i4 + 1] = in[i3 + 1]; 
        out[i4 + 0] = in[i3 + 2]; 
        out[i4 + 3] = 255; 
    }
}


void GImage::RGBtoBGR(
    const uint8*    in,
    uint8*          out,
    int             numPixels) {

    for (int i = 0; i < numPixels; ++i) {
        int i3 = i * 3;

        int r = in[i3 + 0];
        int g = in[i3 + 1];
        int b = in[i3 + 2];

        out[i3 + 2] = r; 
        out[i3 + 1] = g; 
        out[i3 + 0] = b;
    }
}


void GImage::RGBxRGBtoRGBA(
    const uint8*            colorRGB,
    const uint8*            alphaRGB,
    uint8*                  out,
    int                     numPixels) {

    for (int i = numPixels - 1; i >= 0; --i) {
        int i3 = i * 3;
        int i4 = i3 + i;

        out[i4 + 0] = colorRGB[i3 + 0];
        out[i4 + 1] = colorRGB[i3 + 1];
        out[i4 + 2] = colorRGB[i3 + 2];
        out[i4 + 3] = alphaRGB[i3 + 0];
    }
}


void GImage::RGBtoARGB(
    const uint8*            in,
    uint8*                  out,
    int                     numPixels) {

    for (int i = 0; i < numPixels; ++i) {
        int i3 = i * 3;
        int i4 = i3 + i;

        out[i4 + 0] = 255; 
        out[i4 + 1] = in[i3 + 0]; 
        out[i4 + 2] = in[i3 + 1]; 
        out[i4 + 3] = in[i3 + 2];
    }
}


void GImage::flipRGBVertical(
    const uint8*            in,
    uint8*                  out,
    int                     width,
    int                     height) {

    
    // Allocate a temp row so the operation
    // is still safe if in == out
    uint8* temp = (uint8*)System::malloc(width * 3);
    alwaysAssertM(temp != NULL, "Out of memory"); 

    int oneRow = width * 3;
    int N = height / 2;

    // if height is an odd value, don't swap odd middle row
    for (int i = 0; i < N; ++i) {
        int topOff = i * oneRow;
        int botOff = (height - i - 1) * oneRow;
        System::memcpy(temp,         in + topOff, oneRow);
        System::memcpy(out + topOff, in + botOff, oneRow);
        System::memcpy(out + botOff, temp,        oneRow);
    }

    System::free(temp);
}


void GImage::flipRGBAVertical(
    const uint8*            in,
    uint8*                  out,
    int                     width,
    int                     height) {

    
    // Allocate a temp row so the operation
    // is still safe if in == out
    uint8* temp = (uint8*)System::malloc(width * 4);
    alwaysAssertM(temp != NULL, "Out of memory");

    int oneRow = width * 4;

    // if height is an odd value, don't swap odd middle row
    for (int i = 0; i < height / 2; ++i) {
        int topOff = i * oneRow;
        int botOff = (height - i - 1) * oneRow;
        System::memcpy(temp,         in + topOff, oneRow);
        System::memcpy(out + topOff, in + botOff, oneRow);
        System::memcpy(out + botOff, temp,        oneRow);
    }

    System::free(temp);
}

////////////////////////////////////////////////////////////////////////////////////////

void GImage::decode(
    BinaryInput&        input,
    Format              format) {

    switch (format) {
    case PPM_ASCII:
        decodePPMASCII(input);
        break;

    case PPM:
        decodePPM(input);
        break;

    case PNG:
        decodePNG(input);
        break;

    case JPEG:
        decodeJPEG(input);
        break;

    case TGA:
        decodeTGA(input);
        break;

    case BMP:
        decodeBMP(input);
        break;

    case ICO:
        decodeICO(input);
        break;

    case PCX:
        decodePCX(input);
        break;

    default:
        // INFERRED: 0051041f constructs this error for an invalid format.
        throw Error("invalid format", input.getFilename());
    }

    debugAssert(width >= 0);
    debugAssert(height >= 0);
    debugAssert(channels == 1 || channels == 3 || channels == 4);
    debugAssert(_byte != NULL);
}


void GImage::decodePCX(
    BinaryInput&                input) {

    uint8  manufacturer = input.readUInt8();
    uint8  version      = input.readUInt8();
    uint8  encoding     = input.readUInt8();
    uint8  bitsPerPixel = input.readUInt8();

    uint16 xmin         = input.readUInt16();
    uint16 ymin         = input.readUInt16();
    uint16 xmax         = input.readUInt16();
    uint16 ymax         = input.readUInt16();

    uint16 horizDPI     = input.readUInt16();
    uint16 vertDPI      = input.readUInt16();

    Color3uint8 colorMap[16];
    input.readBytes(48, colorMap);

    input.skip(1);

    uint8  planes       = input.readUInt8();
    uint16 bytesPerLine = input.readUInt16();
    uint16 paletteType  = input.readUInt16();
    input.skip(4 + 54);

    (void)bytesPerLine;

    width  = xmax - xmin + 1;
    height = ymax - ymin + 1;
    channels = 3;

    if ((manufacturer != 0x0A) || (encoding != 0x01)) {
        throw GImage::Error("PCX file is corrupted", input.getFilename());
    }

    (void)version;
    (void)vertDPI;
    (void)horizDPI;

    if ((bitsPerPixel != 8) || ((planes != 1) && (planes != 3))) {
        throw GImage::Error("Only 8-bit paletted and 24-bit PCX files supported.", input.getFilename());
    }

	// Prepare the pointer object for the pixel data
    _byte = (uint8*)System::malloc(width * height * 3);

    if ((paletteType == 1) && (planes == 3)) {

        Color3uint8* pixel = pixel3();

        // Iterate over each scan line
        for (int row = 0; row < height; ++row) {
            // Read each scan line once per plane
            for (int plane = 0; plane < planes; ++plane) {
                int p = row * width;
                int p1 = p + width;
                while (p < p1) {
                    uint8 value = input.readUInt8();
                    int length = 1;
            
                    if (value >= 192) {
                        // This is the length, not the value.  Mask off
                        // the two high bits and read the true index.
                        length = value & 0x3F;
                        value = input.readUInt8();
                    }

                    // Set the whole run
                    for (int i = length - 1; i >= 0; --i, ++p) {
                        debugAssert(p < width * height);
                        pixel[p][plane] = value;
                    }
                }
            }
        }

    } else if (planes == 1) {

        Color3uint8 palette[256];

        int imageBeginning   = input.getPosition();
        int paletteBeginning = input.getLength() - 769;

        input.setPosition(paletteBeginning);

        uint8 dummy = input.readUInt8();

        if (dummy != 12) {
            Log::common()->println("\n*********************");
            Log::common()->printf("Warning: Corrupted PCX file (palette marker byte was missing) \"%s\"\nLoading anyway\n\n", input.getFilename().c_str());
        }

        input.readBytes(sizeof(palette), palette);
        input.setPosition(imageBeginning);
        

        Color3uint8* pixel = pixel3();
        
        // The palette indices are run length encoded.
        int p = 0;
        while (p < width * height) {
            uint8 index  = input.readUInt8();
            uint8 length = 1;

            if (index >= 192) {
                // This is the length, not the index.  Mask off
                // the two high bits and read the true index.
                length = index & 0x3F;
                index  = input.readUInt8();
            }

            Color3uint8 color = palette[index];

            // Set the whole run
            for (int i = length - 1; i >= 0; --i, ++p) {
                debugAssert(p < width * height);
                pixel[p] = color;
            }

        }

    } else {
        throw GImage::Error("Unsupported PCX file type.", input.getFilename());
    }
}


GImage::Format GImage::resolveFormat(const std::string&  filename) {
    BinaryInput b(filename, G3D_LITTLE_ENDIAN);
    if (b.size() <= 0) {
        throw Error("File not found.", filename);
    }

    return resolveFormat(filename, b.getCArray(), b.size(), AUTODETECT);
}


GImage::Format GImage::resolveFormat(
    const std::string&  filename,
    const uint8*        data,
    int                 dataLen,
    Format              maybeFormat) {

    // Return the provided format if it is specified.
    if (maybeFormat != AUTODETECT) {
        return maybeFormat;
    }

    std::string extension;

    // Try to detect from the filename's extension
    if (filename.size() >= 5) {
        int n = iMax(filename.size() - 1, 5);
        // Search backwards for the "."
        for (int i = 1; i <= n; ++i) {
            if (filename[filename.size() - i] == '.') {
                // Upper case
                extension = toUpper(filename.substr(filename.size() - i + 1));
                break;
            }
        }
    }

    if (extension == "PPM") {
        // There are two PPM formats; we handle them differently
        if (dataLen > 3) {
            if (!memcmp(data, "P6", 2)) {
                return PPM;
            } else {
                return PPM_ASCII;
            }
        }
    }

    Format tmp = stringToFormat(extension);
    if ((tmp != AUTODETECT) && (tmp != UNKNOWN)) {
        return tmp;
    }

    // Try and autodetect from the file itself by looking at the first
    // character.

    // We can't look at the character if it is null.
    debugAssert(data != NULL);              

    if ((dataLen > 3) && (!memcmp(data, "P3", 2) || !memcmp(data, "P2", 2) || !memcmp(data, "P1", 2))) {
        return PPM_ASCII;
    }

    if ((dataLen > 3) && !memcmp(data, "P6", 2)) {
        return PPM;
    }

    if (dataLen > 8) {
        if (!png_sig_cmp((png_bytep)data, 0, 8))
            return PNG;
    }

    if ((dataLen > 0) && (data[0] == 'B')) {
        return BMP;
    }

    if (dataLen > 10) {
        // INFERRED: 2008 code at 0050e02d checks the JPEG marker bytes.
        if ((dataLen > 11) && (data[0] == 0xFF) &&
            (data[1] == 0xD8) && (data[2] == 0xFF)) {
            return JPEG;
        }
    }

    if (dataLen > 40) {
        if (memcmp(&data[dataLen - 18], "TRUEVISION-XFILE", 16) == 0) {
            return TGA;
        }
    }

    if ((dataLen > 4) && (data[0] == 0) && (data[1] == 0) && (data[2] == 0) && (data[3] == 1)) {
        return ICO;
    }

    if ((dataLen > 0) && (data[0] == 10)) {
        return PCX;
    }

    return UNKNOWN;
}


GImage::GImage(
    const std::string&  filename,
    Format              format) : 
    _byte(NULL), 
    width(0),
    height(0), 
    channels(0){
    
    load(filename, format);
}


void GImage::load(
    const std::string&  filename,
    Format              format) {

    clear();

    try {
        BinaryInput b(filename, G3D_LITTLE_ENDIAN);
        if (b.size() <= 0) {
            throw Error("File not found.", filename);
        }

        decode(b, resolveFormat(filename, b.getCArray(), b.size(), format));
    } catch (const std::string& error) {
        throw Error(error, filename);
    }
}


GImage::GImage(
    const uint8*        data,
    int                 length,
    Format              format) {

    BinaryInput b(data, length, G3D_LITTLE_ENDIAN);
    // It is safe to cast away the const because we
    // know we don't corrupt the data.

    decode(b, resolveFormat("", data, length, format));
}


GImage::GImage(
    int                 width,
    int                 height,
    int                 channels) {
    
    _byte = NULL;
    resize(width, height, channels);
}


void GImage::resize(
    int                 width,
    int                 height,
    int                 channels) {
    debugAssert(width >= 0);
    debugAssert(height >= 0);
    debugAssert(channels >= 1);

    clear();

    this->width = width;
    this->height = height;
    this->channels = channels;
    size_t sz = width * height * channels;

    _byte = (uint8*)System::calloc(sz, sizeof(uint8));
    debugAssert(isValidHeapPointer(_byte));
}


void GImage::_copy(
    const GImage&       other) {

    clear();

    width  = other.width;
    height = other.height;
    channels = other.channels;
    int s  = width * height * channels * sizeof(uint8);
    _byte  = (uint8*)System::malloc(s);
    debugAssert(isValidHeapPointer(_byte));
    memcpy(_byte, other._byte, s);
}


GImage::GImage(
    const GImage&        other) : _byte(NULL) {

    _copy(other);
}


GImage::~GImage() {
    clear();
}


void GImage::clear() {
    width = 0;
    height = 0;
    System::free(_byte);
    _byte = NULL;
}


GImage& GImage::operator=(const GImage& other) {
    _copy(other);
    return *this;
}


bool GImage::copySubImage(
    GImage & dest, const GImage & src,
    int srcX, int srcY, int srcWidth, int srcHeight) {
    if ((src.width < srcX + srcWidth) ||
        (src.height < srcY + srcHeight) ||
        (srcY < 0) ||
        (srcX < 0)) {

        return false;
    }

    dest.resize(srcWidth, srcHeight, src.channels);
    
    bool ret;
    ret = pasteSubImage(dest, src, 0, 0, srcX, srcY, srcWidth, srcHeight);
    debugAssert(ret);

    return true;
}


bool GImage::pasteSubImage(
    GImage & dest, const GImage & src,
    int destX, int destY,
    int srcX, int srcY, int srcWidth, int srcHeight) {
    if ((src.width < srcX + srcWidth) ||
        (src.height < srcY + srcHeight) ||
        (dest.width < destX + srcWidth) ||
        (dest.height < destY + srcHeight) ||
        (srcY < 0) ||
        (srcX < 0) ||
        (destY < 0) ||
        (destX < 0) ||
        (src.channels != dest.channels)) {

        return false;
    }

    for (int i = 0; i < srcHeight; i++) {
        const uint8* srcRow = src.byte() +
            ((i + srcY) * src.width + srcX) * src.channels;
        uint8* destRow = dest.byte() +
            ((i + destY) * dest.width + destX) * dest.channels;
        memcpy(destRow, srcRow, srcWidth * src.channels);
    }

    return true;
}


bool GImage::supportedFormat(
    const std::string& format) {

    return (stringToFormat(format) != UNKNOWN);
}


GImage::Format GImage::stringToFormat(
    const std::string& format) {

    std::string extension = toUpper(format);

    if ((extension == "JPG") || (extension == "JPEG")) {
        return JPEG;
    } else if (extension == "TGA") {
        return TGA;
    } else if (extension == "BMP") {
        return BMP;
    } else if (extension == "PCX") {
        return PCX;
    } else if (extension == "ICO") {
        return ICO;
    } else if (extension == "PNG") {
        return PNG;
    } else if (extension == "PPM") {
        return PPM;
    } else {
        return UNKNOWN;
    }
}


void GImage::save(
    const std::string& filename,
    Format             format) const {

    BinaryOutput b(filename, G3D_LITTLE_ENDIAN);
    encode(resolveFormat(filename, NULL, 0, format), b);
    b.commit(false);
}


void GImage::encode(
    Format              format,
    uint8*&             outData,
    int&                outLength) const {

    BinaryOutput out;

    encode(format, out);

    outData = (uint8*)System::malloc(out.size());
    debugAssert(outData);
    outLength = out.size();

    out.commit(outData);
}


void GImage::encode(
    Format              format,
    BinaryOutput&       out) const {

    switch (format) {
    case PPM_ASCII:
        encodePPMASCII(out);
        break;

    case PPM:
        encodePPM(out);
        break;

    case PNG:
        encodePNG(out);
        break;

    case JPEG:
        encodeJPEG(out);
        break;

    case BMP:
        encodeBMP(out);
        break;

    case TGA:
        encodeTGA(out);
        break;

    default:
        debugAssert(false);
    }
}

GImage GImage::insertRedAsAlpha(const GImage& alpha) const {
    debugAssert(alpha.width == width);
    debugAssert(alpha.height == height);

    GImage out(width, height, 4);

    for (int i = 0; i < width * height; ++i) {
        out.byte()[i * 4 + 0] = byte()[i * channels + 0];
        out.byte()[i * 4 + 1] = byte()[i * channels + 1];
        out.byte()[i * 4 + 2] = byte()[i * channels + 2];
        out.byte()[i * 4 + 3] = alpha.byte()[i * alpha.channels];
    }

    return out;
}


GImage GImage::stripAlpha() const {
    GImage out(width, height, 3);

    for (int i = 0; i < width * height; ++i) {
        out.byte()[i * 3 + 0] = byte()[i * channels + 0];
        out.byte()[i * 3 + 1] = byte()[i * channels + 1];
        out.byte()[i * 3 + 2] = byte()[i * channels + 2];
    }

    return out;
}


int GImage::sizeInMemory() const {
	return sizeof(GImage) + width * height * channels;
}


void GImage::computeNormalMap(
    const GImage&       bump,
    GImage&             normal,
    bool                lowPassBump,
    bool                scaleHeightByNz) {

    const int w = bump.width;
    const int h = bump.height;
    const int stride = bump.channels;

    normal.resize(w, h, 4);

    const uint8* const B = bump.byte();
    Color4uint8* const N = normal.pixel4();

    for (int y = 0; y < h; ++y) {
        for (int x = 0; x < w; ++x) {
            // Index into normal map pixel
            int i = x + y * w;

            // Index into bump map *byte*
            int j = stride * i;


            Vector3 delta;

            // Get a value from B (with wrapping lookup) relative to (x, y)
            // and divide by 255
            #define height(DX, DY) ((B[(((DX + x + w) % w) + \
                                        ((DY + y + h) % h) * w) * stride]) / 255.0)


            // Sobel filter to compute the normal.  
            //
            // Y Filter (X filter is the transpose)
            //  [ -1 -2 -1 ]
            //  [  0  0  0 ]
            //  [  1  2  1 ]

            // Write the Y value directly into the x-component so we don't have
            // to explicitly compute a cross product at the end.
            delta.y = -(height(-1, -1) *  1 + height( 0, -1) *  2 + height( 1, -1) *  1 +
                        height(-1,  1) * -1 + height( 0,  1) * -2 + height( 1,  1) * -1);

            delta.x = -(height(-1, -1) * -1 + height( 1, -1) * 1 + 
                        height(-1,  0) * -2 + height( 1,  0) * 2 + 
                        height(-1,  1) * -1 + height( 1,  1) * 1);

            delta.z = 1.0;


            delta = delta.direction();

            // Copy over the bump value into the alpha channel.
            float H = B[j] / 255.0;

            if (lowPassBump) {
                H = (height(-1, -1) + height( 0, -1) + height(1, -1) +
                        height(-1,  0) + height( 0,  0) + height(1,  0) +
                        height(-1,  1) + height( 0,  1) + height(1,  1)) / 9.0;
            }
            #undef height

            if (scaleHeightByNz) {
                // delta.z can't possibly be negative, so we avoid actually
                // computing the absolute value.
                H *= delta.z;
            }

            N[i].a = iRound(H * 255.0);

            // Pack into byte range
            delta = delta * 127.5 + Vector3(127.5, 127.5, 127.5);
            N[i].r = iClamp(iRound(delta.x), 0, 255);
            N[i].g = iClamp(iRound(delta.y), 0, 255);
            N[i].b = iClamp(iRound(delta.z), 0, 255);
        }
    }
}



/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void GImage::convertToL8() {
    switch(channels) {
    case 1:
        return;

    case 3:
        {            
            // Average
            Color3uint8* src = (Color3uint8*)_byte;
            _byte = NULL;
            resize(width, height, 1);
            for (int i = width * height - 1; i >= 0; --i) {
                const Color3uint8   s = src[i];
                uint8&              d = _byte[i]; 
                d = ((int)s.r + (int)s.g + (int)s.b) / 3;
            }
            System::free(src);
        }
        break;

    case 4:
        {            
            // Average
            Color4uint8* src = (Color4uint8*)_byte;
            _byte = NULL;
            resize(width, height, 1);
            for (int i = width * height - 1; i >= 0; --i) {
                const Color4uint8   s = src[i];
                uint8&              d = _byte[i]; 
                d = ((int)s.r + (int)s.g + (int)s.b) / 3;
            }
            System::free(src);
        }
        return;

    default:
        alwaysAssertM(false, "Bad number of channels in input image");
    }
}


void GImage::convertToRGBA() {
    switch(channels) {
    case 1:
        {            
            // Spread
            uint8* old = _byte;
            _byte = NULL;
            resize(width, height, 4);
            for (int i = width * height - 1; i >= 0; --i) {
                const uint8  s = old[i];
                Color4uint8& d = ((Color4uint8*)_byte)[i]; 
                d.r = d.g = d.b = s;
                d.a = 255;
            }
            System::free(_byte);
        }
        break;

    case 3:
        {            
            // Add alpha
            Color3uint8* old = (Color3uint8*)_byte;
            _byte = NULL;
            resize(width, height, 4);
            for (int i = width * height - 1; i >= 0; --i) {
                const Color3uint8   s = old[i];
                Color4uint8&        d = ((Color4uint8*)_byte)[i]; 
                d.r = s.r;
                d.g = s.g;
                d.b = s.b;
                d.a = 255;
            }
            System::free(old);
        }
        break;

    case 4:
        // Already RGBA
        return;

    default:
        alwaysAssertM(false, "Bad number of channels in input image");
    }
}


void GImage::convertToRGB() {
    switch(channels) {
    case 1:
        {            
            // Spread
            uint8* old = _byte;
            _byte = NULL;
            resize(width, height, 3);
            for (int i = width * height - 1; i >= 0; --i) {
                const uint8  s = old[i];
                Color3uint8& d = ((Color3uint8*)_byte)[i]; 
                d.r = d.g = d.b = s;
            }
            System::free(old);
        }
        break;

    case 3:
		return;

    case 4:
		// Strip alpha
        {            
            Color4uint8* old = (Color4uint8*)_byte;
            _byte = NULL;
            resize(width, height, 3);
            for (int i = width * height - 1; i >= 0; --i) {
                const Color4uint8   s = old[i];
                Color3uint8&        d = ((Color3uint8*)_byte)[i]; 
                d.r = s.r;
                d.g = s.g;
                d.b = s.b;
            }
            System::free(old);
        }
        break;

    default:
        alwaysAssertM(false, "Bad number of channels in input image");
    }
}


void GImage::R8G8B8_to_Y8U8V8(int width, int height, const uint8* _in, uint8* _out) {
    const Color3uint8* in = reinterpret_cast<const Color3uint8*>(_in);
    Color3uint8* out = reinterpret_cast<Color3uint8*>(_out);

    Color3uint8 p;
    for (int i = width * height - 1; i >= 0; --i) {
        p.r = iClamp(iRound(in->r *  0.229 + in->g *  0.587 + in->b *  0.114), 0, 255);
        p.g = iClamp(iRound(in->r * -0.147 + in->g * -0.289 + in->b *  0.436) + 127, 0, 255);
        p.b = iClamp(iRound(in->r *  0.615 + in->g * -0.515 + in->b * -0.100) + 127, 0, 255);
        *out = p;
        ++in;
        ++out;
    }
}



void GImage::Y8U8V8_to_R8G8B8(int width, int height, const uint8* _in, uint8* _out) {
    const Color3uint8* in = reinterpret_cast<const Color3uint8*>(_in);
    Color3uint8* out = reinterpret_cast<Color3uint8*>(_out);

    Color3uint8 p;
    for (int i = width * height - 1; i >= 0; --i) {
        p.r = iClamp(iRound(in->r *  1.0753 +                   (in->b - 127) *  1.2256), 0, 255);
        p.g = iClamp(iRound(in->r *  1.0753 + (in->g - 127) * -0.3946 + (in->b - 127) * -0.4947), 0, 255);
        p.b = iClamp(iRound(in->r *  1.0753 + (in->g - 127) *  2.0320 + (in->b - 127) *  0.0853), 0, 255);
        *out = p;
        ++in;
        ++out;
    }
}


void GImage::makeCheckerboard(GImage& im, int checkerSize, const Color4uint8& A, const Color4uint8& B) {
    for (int y = 0; y < im.height; ++y) {
        for (int x = 0; x < im.width; ++x) {
            bool checker = isOdd((x / checkerSize) + (y / checkerSize));
            const Color4uint8& color = checker ? A : B;
            for (int c = 0; c < im.channels; ++c) {
                uint8* v = im.byte() + (x + y * im.width) * im.channels + c;
                *v = color[c];
            }
        }
    }
}

}

// 2008-06 native G3DGImage_png (inactive): upstream tools/libs/g3d-6.09/source/G3Dcpp/GImage_png.cpp, verbatim.
#line 1 ".\\G3Dcpp\\GImage_png.cpp"
/**
  @file GImage_png.cpp
  @author Morgan McGuire, morgan@graphics3d.com
  @created 2002-05-27
  @edited  2006-05-10
 */

namespace G3D {


//libpng required function signature
static void png_read_data(
    png_structp png_ptr,
    png_bytep data,
    png_size_t length) {


    debugAssert( png_ptr->io_ptr != NULL );
    debugAssert( length >= 0 );
    debugAssert( data != NULL );

    ((BinaryInput*)png_ptr->io_ptr)->readBytes(length, data);
}

//libpng required function signature
static void png_write_data(png_structp png_ptr,
    png_bytep data,
    png_size_t length) {

    debugAssert( png_ptr->io_ptr != NULL );
    debugAssert( data != NULL );

    ((BinaryOutput*)png_ptr->io_ptr)->writeBytes(data, length);
}

//libpng required function signature
static void png_flush_data(
    png_structp png_ptr) {
    (void)png_ptr;
    //Do nothing.
}

//libpng required function signature
static void png_error(
    png_structp png_ptr,
    png_const_charp error_msg) {
    
    (void)png_ptr;
    debugAssert( error_msg != NULL );
    throw GImage::Error(error_msg, "PNG"); 
}

//libpng required function signature
void png_warning(
    png_structp png_ptr,
    png_const_charp warning_msg) {

    (void)png_ptr;
    debugAssert( warning_msg != NULL );
    Log::common()->println(warning_msg);
}

void GImage::encodePNG(
    BinaryOutput&           out) const {

    debugAssert( channels == 1 || channels == 3 || channels == 4 );

    if (this->height > (int)(PNG_UINT_32_MAX/png_sizeof(png_bytep)))
        throw GImage::Error("Unsupported PNG height.", out.getFilename());

    out.setEndian(G3D_LITTLE_ENDIAN);

    png_structp png_ptr = png_create_write_struct(PNG_LIBPNG_VER_STRING, NULL, png_error, png_warning);
    if (!png_ptr)
        throw GImage::Error("Unable to initialize PNG encoder.", out.getFilename());

    png_infop info_ptr = png_create_info_struct(png_ptr);
    if (!info_ptr) {
        png_destroy_write_struct(&png_ptr, &info_ptr);
        throw GImage::Error("Unable to initialize PNG encoder.", out.getFilename());
    }

    //setup libpng write handler so can use BinaryOutput
    png_set_write_fn(png_ptr, (void*)&out, png_write_data, png_flush_data);

    if (channels == 3) {
        png_set_IHDR(png_ptr, info_ptr, this->width, this->height, 8, PNG_COLOR_TYPE_RGB,
            PNG_INTERLACE_NONE, PNG_COMPRESSION_TYPE_BASE, PNG_FILTER_TYPE_BASE);
    }
    else if (channels == 4) {
        png_set_IHDR(png_ptr, info_ptr, this->width, this->height, 8, PNG_COLOR_TYPE_RGBA,
            PNG_INTERLACE_NONE, PNG_COMPRESSION_TYPE_BASE, PNG_FILTER_TYPE_BASE);
    }
    else if (channels == 1) {
        png_set_IHDR(png_ptr, info_ptr, this->width, this->height, 8, PNG_COLOR_TYPE_GRAY,
            PNG_INTERLACE_NONE, PNG_COMPRESSION_TYPE_BASE, PNG_FILTER_TYPE_BASE);
    }
    else {
        png_destroy_write_struct(&png_ptr, &info_ptr);
        throw GImage::Error("Unsupported number of channels for PNG.", out.getFilename());
    }

    png_color_8_struct sig_bit;
    sig_bit.red = 8;
    sig_bit.green = 8;
    sig_bit.blue = 8;
    if (channels == 4)
        sig_bit.alpha = 8;
    else
        sig_bit.alpha = 0;
    png_set_sBIT(png_ptr, info_ptr, &sig_bit);

    //write the png header
    png_write_info(png_ptr, info_ptr);

    png_bytepp row_pointers = new png_bytep[this->height];

    for (int i=0; i < this->height; ++i) {
        row_pointers[i] = (png_bytep)&this->_byte[(this->width * this->channels * i)];
    }

    png_write_image(png_ptr, row_pointers);

    png_write_end(png_ptr, info_ptr);

    delete[] row_pointers;

    png_destroy_write_struct(&png_ptr, &info_ptr);
}


void GImage::decodePNG(
    BinaryInput&        input) {

    png_structp png_ptr = png_create_read_struct(PNG_LIBPNG_VER_STRING, NULL, png_error, png_warning);
    if (!png_ptr)
        throw GImage::Error("Unable to initialize PNG decoder.", input.getFilename());

    png_infop info_ptr = png_create_info_struct(png_ptr);
    if (!info_ptr) {
        png_destroy_read_struct(&png_ptr, (png_infopp)NULL, (png_infopp)NULL);
        throw GImage::Error("Unable to initialize PNG decoder.", input.getFilename());
    }

    png_infop end_info = png_create_info_struct(png_ptr);
    if (!end_info) {
        png_destroy_read_struct(&png_ptr, &info_ptr, (png_infopp)NULL);
        throw GImage::Error("Unable to initialize PNG decoder.", input.getFilename());
    }

    //now that the libpng structures are setup, change the error handlers and read routines
    //to use G3D functions so that BinaryInput can be used.

    png_set_read_fn(png_ptr, (png_voidp)&input, png_read_data);
    
    //read in sequentially so that three copies of the file are not in memory at once
    png_read_info(png_ptr, info_ptr);

    uint32 png_width, png_height;
    int bit_depth, color_type, interlace_type;
    //this will validate the data it extracts from info_ptr
    png_get_IHDR(png_ptr, info_ptr, (png_uint_32*)&png_width, (png_uint_32*)&png_height, &bit_depth, &color_type,
       &interlace_type, int_p_NULL, int_p_NULL);

    if (color_type == PNG_COLOR_TYPE_GRAY_ALPHA) {
        png_destroy_read_struct(&png_ptr, &info_ptr, &end_info);
        throw GImage::Error("Unsupported PNG color type - PNG_COLOR_TYPE_GRAY_ALPHA.", input.getFilename());
    }

    this->width = png_width;
    this->height = png_height;

    //swap bytes of 16 bit files to least significant byte first
    png_set_swap(png_ptr);

    png_set_strip_16(png_ptr);

    //Expand paletted colors into true RGB triplets
    if (color_type == PNG_COLOR_TYPE_PALETTE) {
        png_set_palette_to_rgb(png_ptr);
    }

    //Expand grayscale images to the full 8 bits from 1, 2, or 4 bits/pixel
    if (color_type == PNG_COLOR_TYPE_GRAY && bit_depth < 8) {
        png_set_gray_1_2_4_to_8(png_ptr);
    }

    //Expand paletted or RGB images with transparency to full alpha channels
    //so the data will be available as RGBA quartets.
    if (png_get_valid(png_ptr, info_ptr, PNG_INFO_tRNS)) {
        png_set_tRNS_to_alpha(png_ptr);
    }

    // Fix sub-8 bit_depth to 8bit
    if (bit_depth < 8) {
        png_set_packing(png_ptr);
    }

    if (color_type == PNG_COLOR_TYPE_RGBA) {
        this->channels = 4;
        this->_byte = (uint8*)System::malloc(width * height * 4);
    } else if ((color_type == PNG_COLOR_TYPE_RGB) || 
               (color_type == PNG_COLOR_TYPE_PALETTE)) {
        this->channels = 3;
        this->_byte = (uint8*)System::malloc(width * height * 3);
    } else if (color_type == PNG_COLOR_TYPE_GRAY) {
        this->channels = 1;
        this->_byte = (uint8*)System::malloc(width * height);
    } else {
        throw GImage::Error("Unsupported PNG bit-depth or type.", input.getFilename());
    }

    //since we are reading row by row, required to handle interlacing
    uint32 number_passes = png_set_interlace_handling(png_ptr);

    png_read_update_info(png_ptr, info_ptr);

    for (uint32 pass = 0; pass < number_passes; ++pass) {
        for (uint32 y = 0; y < (uint32)height; ++y) {
            png_bytep rowPointer = &this->_byte[width * this->channels * y]; 
            png_read_rows(png_ptr, &rowPointer, png_bytepp_NULL, 1);
        }
    }

    png_read_end(png_ptr, info_ptr);

    png_destroy_read_struct(&png_ptr, &info_ptr, &end_info);
}


}

// 2008-06 native G3DGImage_ppm (inactive): upstream tools/libs/g3d-6.09/source/G3Dcpp/GImage_ppm.cpp, verbatim.
#line 1 ".\\G3Dcpp\\GImage_ppm.cpp"
/**
  @file GImage_ppm.cpp
  @author Morgan McGuire, morgan@graphics3d.com
  @created 2002-05-27
  @edited  2006-05-10
 */

namespace G3D {

void GImage::encodePPMASCII(
    BinaryOutput&       out) const {

    debugAssert(channels == 3);

    TextOutput::Options ppmOptions;
    ppmOptions.convertNewlines = false;
    ppmOptions.numColumns = 70;
    ppmOptions.wordWrap = TextOutput::Options::WRAP_WITHOUT_BREAKING;
    TextOutput ppm(ppmOptions);
    // Always write out a full-color ppm
    ppm.printf("P3\n%d %d\n255\n", width, height);
    
    const Color3uint8* c = this->pixel3();
    for (uint32 i = 0; i < (uint32)(width * height); ++i) {
        ppm.printf("%d %d %d%c", c[i].r, c[i].g, c[i].b, 
            ((i % ((width * 3) - 1)) == 0) ?
            '\n' : ' '); 
    }

    out.writeString(ppm.commitString());
}


void GImage::encodePPM(
    BinaryOutput&       out) const {

    // http://netpbm.sourceforge.net/doc/ppm.html
    debugAssert(channels == 3);

    std::string header = format("P6 %d %d 255 ", width, height);

    out.writeBytes(header.c_str(), header.size());

    out.writeBytes(this->pixel3(), width * height * 3);
}

void GImage::decodePPMASCII(
    BinaryInput&        input) {

    int ppmWidth;
    int ppmHeight;

    double maxColor;

    // Create a TextInput object to parse ascii format
    // Mixed binary/ascii formats will require more 

    const std::string inputStr = input.readString();

    TextInput::Options ppmOptions;
    ppmOptions.cppComments = false;
    ppmOptions.otherCommentCharacter = '#';
    ppmOptions.signedNumbers = true;
    ppmOptions.singleQuotedStrings = false;

    TextInput ppmInput(TextInput::FROM_STRING, inputStr, ppmOptions);

    //Skip first line in header P#
    std::string ppmType = ppmInput.readSymbol();

    ppmWidth = (int)ppmInput.readNumber();
    ppmHeight = (int)ppmInput.readNumber();

    // Everything but a PBM will have a max color value
    if (ppmType != "P2") {
        maxColor = ppmInput.readNumber();
    } else {
        maxColor = 255;
    }

    if ((ppmWidth < 0) ||
        (ppmHeight < 0) ||
        (maxColor <= 0)) {
        throw GImage::Error("Invalid PPM Header.", input.getFilename());
    }

    // I don't think it's proper to scale values less than 255
    if (maxColor <= 255.0) {
        maxColor = 255.0;
    }

    this->width = ppmWidth;
    this->height = ppmHeight;
    this->channels = 3;
    // always scale down to 1 byte per channel
    this->_byte = (uint8*)System::malloc(width * height * 3);

    // Read in the image data.  I am not validating if the values match the maxColor
    // requirements.  I only scale if needed to fit within the byte available.
    for (uint32 i = 0; i < (uint32)(width * height); ++i) {
        // read in color and scale to max pixel defined in header
        // A max color less than 255 might need to be left alone and not scaled.
        Color3uint8& curPixel = *(this->pixel3() + i);

        if (ppmType == "P3") {
            curPixel.r = (uint8)(ppmInput.readNumber() * (255.0 / maxColor));
            curPixel.g = (uint8)(ppmInput.readNumber() * (255.0 / maxColor));
            curPixel.b = (uint8)(ppmInput.readNumber() * (255.0 / maxColor));
        } else if (ppmType == "P2") {
            uint8 pixel = (uint8)(ppmInput.readNumber() * (255.0 / maxColor));
            curPixel.r = pixel;
            curPixel.g = pixel;
            curPixel.b = pixel;
        } else if (ppmType == "P1") {
            int pixel = (uint8)(ppmInput.readNumber() * maxColor);
            curPixel.r = pixel;
            curPixel.g = pixel;
            curPixel.b = pixel;
        }
    }
}

/** Consumes whitespace up to and including a number, but not the following character */
static int scanUInt(BinaryInput& input) {
    char c = input.readUInt8();
    while (isWhiteSpace(c)) {
        c = input.readUInt8();
    }

    std::string s;
    s += c;
    c = input.readUInt8();
    while (!isWhiteSpace(c)) {
        s += c;
        c = input.readUInt8();
    }

    // Back up one to avoid consuming the last character
    input.setPosition(input.getPosition() - 1);

    int x;
    sscanf(s.c_str(), "%d", &x);
    return x;
}

void GImage::decodePPM(
    BinaryInput&        input) {

    char head[2];
    int w, h;

    input.readBytes(head, 2);
    if (head[0] != 'P' || head[1] != '6') {
        throw GImage::Error("Invalid PPM Header.", input.getFilename());
    }

    w = scanUInt(input);
    h = scanUInt(input);

    // Skip the max color specifier
    scanUInt(input);

    if ((w < 0) ||
        (h < 0) ||
        (w > 100000) ||
        (h > 100000)) {
        throw GImage::Error("Invalid PPM size in header.", input.getFilename());
    }

    // Trailing whitespace
    input.readUInt8();

    resize(w, h, 3);

    input.readBytes(_byte, width * height * 3);
}

}

// 2008-06 native G3DGImage_tga (inactive): upstream tools/libs/g3d-6.09/source/G3Dcpp/GImage_tga.cpp, verbatim.
#line 1 ".\\G3Dcpp\\GImage_tga.cpp"
/**
  @file GImage_tga.cpp
  @author Morgan McGuire, morgan@graphics3d.com
  @created 2002-05-27
  @edited  2006-05-10
 */

namespace G3D {

void GImage::encodeTGA(
    BinaryOutput&       out) const {

    out.setEndian(G3D_LITTLE_ENDIAN);

    // ID length
    out.writeUInt8(0);

    // Color map Type
    out.writeUInt8(0);

    // Type
    out.writeUInt8(2);

    // Color map
    out.skip(5);

    // x, y offsets
    out.writeUInt16(0);
    out.writeUInt16(0);

    // Width & height
    out.writeUInt16(width);
    out.writeUInt16(height);

    // Color depth
    out.writeUInt8(8 * channels);

    // Image descriptor
    if (channels == 3) {
        // 0 alpha bits
        out.writeUInt8(0);
    }
    else {
        // 8 alpha bits
        out.writeUInt8(8);
    }

    // Image ID (zero length)

    if (channels == 3) {
        // Pixels are upside down in BGR format.
        for (int y = height - 1; y >= 0; y--) {
            for (int x = 0; x < width; x++) {
                uint8* p = &(_byte[3 * (y * width + x)]);
                out.writeUInt8(p[2]);
                out.writeUInt8(p[1]);
                out.writeUInt8(p[0]);
            }
        }
    } else {
        // Pixels are upside down in BGRA format.
        for (int y = height - 1; y >= 0; y--) {
            for (int x = 0; x < width; x++) {
                uint8* p = &(_byte[4 * (y * width + x)]);
                out.writeUInt8(p[2]);
                out.writeUInt8(p[1]);
                out.writeUInt8(p[0]);
                out.writeUInt8(p[3]);
            }
        }
    }

    // Write "TRUEVISION-XFILE " 18 bytes from the end 
    // (with null termination)
    out.writeString("TRUEVISION-XFILE ");
}


void GImage::decodeTGA(
    BinaryInput&        input) {

    // This is a simple TGA loader that can handle uncompressed
    // truecolor TGA files (TGA type 2). 
    // Verify this is a TGA file by looking for the TRUEVISION tag.
    input.setPosition(input.size() - 18);
    std::string tag = input.readString(16);
    if (tag != "TRUEVISION-XFILE") {
        throw Error("Not a TGA file", input.getFilename());
    }

    input.reset();

    int IDLength     = input.readUInt8();
    int colorMapType = input.readUInt8();
    int imageType    = input.readUInt8();

    (void)colorMapType;
	
    // 2 is the type supported by this routine.
    if (imageType != 2) {
        throw Error("TGA images must be type 2 (Uncompressed truecolor)", input.getFilename());
    }
	
    // Color map specification
    input.skip(5);

    // Image specification

    // Skip x and y offsets
    input.skip(4); 

    width = input.readInt16();
    height = input.readInt16();

    int colorDepth = input.readUInt8();

    if ((colorDepth != 24) && (colorDepth != 32)) {
        throw Error("TGA files must be 24 or 32 bit.", input.getFilename());
    }

    if (colorDepth == 32) {
        channels = 4;
    } else {
        channels = 3;
    }

    // Image descriptor contains overlay data as well
    // as data indicating where the origin is
    int imageDescriptor = input.readUInt8();
    (void)imageDescriptor;
	
    // Image ID
    input.skip(IDLength);

    _byte = (uint8*)System::malloc(width * height * channels);
    debugAssert(_byte);
	
    // Pixel data
    int x;
    int y;

    if (channels == 3) {
        for (y = height - 1; y >= 0; y--) {
          for (x = 0; x < width; x++) {
            int b = input.readUInt8();
            int g = input.readUInt8();
            int r = input.readUInt8();
		    
            int i = (x + y * width) * 3;
            _byte[i + 0] = r;
            _byte[i + 1] = g;
            _byte[i + 2] = b;
          }
        }
    } else {
        for (y = height - 1; y >= 0; y--) {
          for (x = 0; x < width; x++) {
            int b = input.readUInt8();
            int g = input.readUInt8();
            int r = input.readUInt8();
            int a = input.readUInt8();
		    
            int i = (x + y * width) * 4;
            _byte[i + 0] = r;
            _byte[i + 1] = g;
            _byte[i + 2] = b;
            _byte[i + 3] = a;
          }
        }
    }
}

}
