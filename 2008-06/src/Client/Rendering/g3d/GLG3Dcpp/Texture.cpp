/**
 @file Texture.cpp

 @author Morgan McGuire, morgan3d@graphics3d.com

 Notes:
 <UL>
 <LI>http://developer.apple.com/opengl/extensions/ext_texture_rectangle.html
 </UL>

 @created 2001-02-28
 @edited  2005-04-05
*/

#include "G3D/Log.h"
#include "G3D/Matrix3.h"
#include "G3D/Rect2D.h"
#include "G3D/GImage.h"
#include "G3D/fileutils.h"
#include "GLG3D/glcalls.h"
#include "GLG3D/TextureFormat.h"
#include "GLG3D/Texture.h"
#include "GLG3D/getOpenGLState.h"
#include "GLG3D/GLCaps.h"

G3D::uint32 hashCode(const G3D::Texture::Settings& p) {
    return p.hashCode();
}

namespace G3D {

static const char* cubeMapString[] = {"ft", "bk", "up", "dn", "rt", "lf"};

size_t Texture::_sizeOfAllTexturesInMemory = 0;

/**
 Returns true if the system supports automatic MIP-map generation.
 */
static bool hasAutoMipMap() {
    static bool initialized = false;
    static bool ham = false;

    if (! initialized) {
        initialized = true;
        std::string ext = (char*)glGetString(GL_EXTENSIONS);
        ham = (ext.find("GL_SGIS_generate_mipmap") != std::string::npos) &&
            ! GLCaps::hasBug_mipmapGeneration() &&
            ! GLCaps::hasBug_redBlueMipmapSwap();
    }

    return ham;
}


Texture::Settings::Settings() : 
    interpolateMode(TRILINEAR_MIPMAP),
    wrapMode(TILE),
    depthReadMode(DEPTH_NORMAL),
    maxAnisotropy(2.0),
    autoMipMap(true),
    minMipMap(-1000),
    maxMipMap(1000) {
}


const Texture::Settings& Texture::Settings::defaults() {
    static Settings param;
    return param;
}


const Texture::Settings& Texture::Settings::video() {

    static bool initialized = false;
    static Settings param;

    if (! initialized) {
        initialized = true;
        param.interpolateMode = BILINEAR_NO_MIPMAP;
        param.wrapMode = CLAMP;
        param.depthReadMode = DEPTH_NORMAL;
        param.maxAnisotropy = 1.0;
        param.autoMipMap = false;
    }

    return param;
}


const Texture::Settings& Texture::Settings::shadow() {

    static bool initialized = false;
    static Settings param;

    if (! initialized) {
        initialized = true;
        param.interpolateMode = BILINEAR_NO_MIPMAP;
        param.wrapMode = CLAMP;
        param.depthReadMode = DEPTH_LEQUAL;
        param.maxAnisotropy = 1.0;
        param.autoMipMap = false;
    }

    return param;
}

/*
void Texture::Settings::serialize(class BinaryOutput& b) {
    // TODO: use chunk format

}

void Texture::Settings::deserialize(class BinaryInput& b) {

}

void Texture::Settings::serialize(class TextOutput& t) {
    // TODO: ini-like format
}

void Texture::Settings::deserialize(class TextInput& t) {
}
*/

uint32 Texture::Settings::hashCode() const {
    return 
        (uint32)interpolateMode + 
        16 * (uint32)wrapMode + 
        256 * (uint32)depthReadMode + 
        (autoMipMap ? 512 : 0) +
        (uint32)(1024 * maxAnisotropy) +
        (minMipMap ^ (maxMipMap << 16));
}



/**
 Pushes all OpenGL texture state.
 */
// TODO: this is slow; push only absolutely necessary state
// or back up state that will be corrupted.
static void glStatePush() {
    glPushAttrib(GL_ALL_ATTRIB_BITS);
    glPushClientAttrib(GL_ALL_CLIENT_ATTRIB_BITS);

    if (GLCaps::supports_GL_ARB_multitexture()) {
        glActiveTextureARB(GL_TEXTURE0_ARB);
    }
}

/**
 Pops all OpenGL texture state.
 */
static void glStatePop() {
    glPopClientAttrib();
    glPopAttrib();
}


static GLenum dimensionToTarget(Texture::Dimension d) {
    switch (d) {
    case Texture::DIM_CUBE_MAP_NPOT:
    case Texture::DIM_CUBE_MAP:
        return GL_TEXTURE_CUBE_MAP_ARB;

    case Texture::DIM_2D_NPOT:
    case Texture::DIM_2D:
        return GL_TEXTURE_2D;

    case Texture::DIM_2D_RECT:
        return GL_TEXTURE_RECTANGLE_EXT;

    default:
        debugAssert(false);
        return GL_TEXTURE_2D;
    }
}


static void createTexture(
    GLenum          target,
    const uint8*    rawBytes,
    GLenum          bytesFormat,
    GLenum          bytesActualFormat,
    int             width,
    int             height,
    GLenum          textureFormat,
    int             bytesPerPixel,
    int             mipLevel = 0,
    bool            compressed = false,
    bool            useNPOT = false,
    float           rescaleFactor = 1.0f) {

    uint8* bytes = const_cast<uint8*>(rawBytes);

    // If true, we're supposed to free the byte array at the end of
    // the function.
    bool   freeBytes = false; 

    switch (target) {
    case GL_TEXTURE_CUBE_MAP_POSITIVE_X_ARB:
    case GL_TEXTURE_CUBE_MAP_NEGATIVE_X_ARB:
    case GL_TEXTURE_CUBE_MAP_POSITIVE_Y_ARB:
    case GL_TEXTURE_CUBE_MAP_NEGATIVE_Y_ARB:
    case GL_TEXTURE_CUBE_MAP_POSITIVE_Z_ARB:
    case GL_TEXTURE_CUBE_MAP_NEGATIVE_Z_ARB:
    case GL_TEXTURE_2D:
        if ((! isPow2(width) || ! isPow2(height)) &&
            (! useNPOT || ! GLCaps::supports_GL_ARB_texture_non_power_of_two())) {
            // NPOT texture with useNPOT disabled: resize to a power of two

            debugAssertM(! compressed,
                "This device does not support NPOT compressed textures.");

            int oldWidth = width;
            int oldHeight = height;
            width  = ceilPow2(static_cast<unsigned int>(width * rescaleFactor));
            height = ceilPow2(static_cast<unsigned int>(height * rescaleFactor));

            bytes = new uint8[width * height * bytesPerPixel];
            freeBytes = true;

            // Rescale the image to a power of 2
            gluScaleImage(
                bytesFormat,
                oldWidth,
                oldHeight,
                GL_UNSIGNED_BYTE,
                rawBytes,
                width,
                height,
                GL_UNSIGNED_BYTE,
                bytes);

        }

        // Intentionally fall through for power of 2 case

    case GL_TEXTURE_RECTANGLE_EXT:

        // Note code falling through from above

        if (compressed) {
            
            debugAssertM((target != GL_TEXTURE_RECTANGLE_EXT),
                "Compressed textures must be DIM_2D.");

            glCompressedTexImage2DARB(target, mipLevel, bytesActualFormat, width, 
                height, 0, (bytesPerPixel * ((width + 3) / 4) * ((height + 3) / 4)), rawBytes);

        } else {

            // 2D texture, level of detail 0 (normal), internal format, x size from image, y size from image, 
            // border 0 (normal), rgb color data, unsigned byte data, and finally the data itself.
            glTexImage2D(target, mipLevel, textureFormat, width, height, 0, bytesFormat, GL_UNSIGNED_BYTE, bytes);
        }
        break;

    default:
        debugAssertM(false, "Fell through switch");
    }

    if (freeBytes) {
        // Texture was resized; free the temporary.
        delete[] bytes;
    }
}


static void createMipMapTexture(    
    GLenum          target,
    const uint8*    _bytes,
    int             bytesFormat,
    int             width,
    int             height,
    GLenum          textureFormat,
    size_t          bytesFormatBytesPerPixel,
    float           rescaleFactor) {

    switch (target) {
    case GL_TEXTURE_2D:
    case GL_TEXTURE_CUBE_MAP_POSITIVE_X_ARB:
    case GL_TEXTURE_CUBE_MAP_NEGATIVE_X_ARB:
    case GL_TEXTURE_CUBE_MAP_POSITIVE_Y_ARB:
    case GL_TEXTURE_CUBE_MAP_NEGATIVE_Y_ARB:
    case GL_TEXTURE_CUBE_MAP_POSITIVE_Z_ARB:
    case GL_TEXTURE_CUBE_MAP_NEGATIVE_Z_ARB:
        {
            bool freeBytes = false;
            const uint8* bytes = _bytes;

            if (rescaleFactor != 1.0f) {
                int oldWidth = width;
                int oldHeight = height;
                width  = ceilPow2(static_cast<unsigned int>(width * rescaleFactor));
                height = ceilPow2(static_cast<unsigned int>(height * rescaleFactor));

                bytes = new uint8[width * height * bytesFormatBytesPerPixel];
                freeBytes = true;

                // Rescale the image to a power of 2
                gluScaleImage(
                    bytesFormat,
                    oldWidth,
                    oldHeight,
                    GL_UNSIGNED_BYTE,
                    _bytes,
                    width,
                    height,
                    GL_UNSIGNED_BYTE,
                    (void*)bytes);
            }

            int r = gluBuild2DMipmaps(target, textureFormat, width, height, bytesFormat, GL_UNSIGNED_BYTE, bytes);
            debugAssertM(r == 0, (const char*)gluErrorString(r)); (void)r;

            if (freeBytes) {
                delete[] const_cast<uint8*>(bytes);
            }
            break;
        }

    default:
        debugAssertM(false, "Mipmaps not supported for this texture target");
    }
}



/**
 Overrides the current wrap and interpolation parameters for the
 current texture.
 */
static void setTexParameters(
    GLenum                          target,
    const Texture::Settings&        settings) {

    debugAssert(
        target == GL_TEXTURE_2D ||
        target == GL_TEXTURE_RECTANGLE_EXT ||
        target == GL_TEXTURE_CUBE_MAP_ARB);

    debugAssertGLOk();

    // Set the wrap and interpolate state

    bool supports3D = GLCaps::supports_GL_EXT_texture_3D();
    GLenum mode = GL_NONE;
    
    switch (settings.wrapMode) {
    case Texture::TILE:
      mode = GL_REPEAT;
      break;

    case Texture::CLAMP:  
      if (GLCaps::supports_GL_EXT_texture_edge_clamp())
        mode = GL_CLAMP_TO_EDGE;
      else
        mode = GL_CLAMP;
      break;

    case Texture::TRANSPARENT_BORDER:
      if (GLCaps::supports_GL_ARB_texture_border_clamp())
        mode = GL_CLAMP_TO_BORDER_ARB;
      else
        mode = GL_CLAMP;
      {
        Color4 black(0,0,0,0);
        glTexParameterfv(target, GL_TEXTURE_BORDER_COLOR, black);
        debugAssertGLOk();
      }
      break;

    default:
        debugAssert(false);
    }
    glTexParameteri(target, GL_TEXTURE_WRAP_S, mode);
    glTexParameteri(target, GL_TEXTURE_WRAP_T, mode);
    if (supports3D) {
        glTexParameteri(target, GL_TEXTURE_WRAP_R, mode);
    }

    debugAssertGLOk();

    if (GLCaps::supports("GL_EXT_texture_lod")) {
        glTexParameteri(target, GL_TEXTURE_MAX_LOD_SGIS, settings.maxMipMap);
        glTexParameteri(target, GL_TEXTURE_MIN_LOD_SGIS, settings.minMipMap);
    }


    switch (settings.interpolateMode) {
    case Texture::TRILINEAR_MIPMAP:
        glTexParameteri(target, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
        glTexParameteri(target, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);

        if (hasAutoMipMap()) {  
            glTexParameteri(target, GL_GENERATE_MIPMAP_SGIS, GL_TRUE);
        }
        break;

    case Texture::BILINEAR_MIPMAP:
        glTexParameteri(target, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
        glTexParameteri(target, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_NEAREST);

        if (hasAutoMipMap() && settings.autoMipMap) {  
            glTexParameteri(target, GL_GENERATE_MIPMAP_SGIS, GL_TRUE);
        }
        break;

    case Texture::NEAREST_MIPMAP:
        glTexParameteri(target, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
        glTexParameteri(target, GL_TEXTURE_MIN_FILTER, GL_NEAREST_MIPMAP_NEAREST);

        if (hasAutoMipMap() && settings.autoMipMap) {  
            glTexParameteri(target, GL_GENERATE_MIPMAP_SGIS, GL_TRUE);
        }
        break;

    case Texture::BILINEAR_NO_MIPMAP:
        glTexParameteri(target, GL_TEXTURE_MAG_FILTER, GL_LINEAR); 
        glTexParameteri(target, GL_TEXTURE_MIN_FILTER, GL_LINEAR); 
        break;

    case Texture::NO_INTERPOLATION:
    case Texture::NEAREST_NO_MIPMAP:
        glTexParameteri(target, GL_TEXTURE_MAG_FILTER, GL_NEAREST); 
        glTexParameteri(target, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
        break;

    default:
        debugAssert(false);
    }
    debugAssertGLOk();


    static const bool anisotropic = GLCaps::supports("GL_EXT_texture_filter_anisotropic");

    if (anisotropic) {
        glTexParameterf(target, GL_TEXTURE_MAX_ANISOTROPY_EXT, settings.maxAnisotropy);
    }

    if (GLCaps::supports_GL_ARB_shadow()) {
        if (settings.depthReadMode == Texture::DEPTH_NORMAL) {
            glTexParameteri(target, GL_TEXTURE_COMPARE_MODE_ARB, GL_NONE);
        } else {
            glTexParameteri(target, GL_TEXTURE_COMPARE_MODE_ARB, GL_COMPARE_R_TO_TEXTURE_ARB);

            glTexParameteri(target, GL_TEXTURE_COMPARE_FUNC_ARB, 
                (settings.depthReadMode == Texture::DEPTH_LEQUAL) ? GL_LEQUAL : GL_GEQUAL);
        }

    }
    debugAssertGLOk();
}

/////////////////////////////////////////////////////////////////////////////

const Texture::Settings& Texture::parameters() const {
    return _settings;
}

const Texture::Settings& Texture::settings() const {
    return _settings;
}


void Texture::getImage(GImage& dst, const TextureFormat* outFormat) const {
    alwaysAssertM(outFormat == TextureFormat::AUTO ||
                  outFormat == TextureFormat::RGB8 ||
                  outFormat == TextureFormat::RGBA8 ||
                  outFormat == TextureFormat::L8 ||
                  outFormat == TextureFormat::A8, "Illegal texture format.");

    if (outFormat == TextureFormat::AUTO) {
        switch(format->OpenGLBaseFormat) { 
        case GL_ALPHA:
            outFormat = TextureFormat::A8;
            break;

        case GL_LUMINANCE:
            outFormat = TextureFormat::L8;
            break;

        case GL_RGB:
            outFormat = TextureFormat::RGB8;
            break;

        case GL_RGBA:
            // Fall through intentionally
        default:
            outFormat = TextureFormat::RGBA8;
            break;
        }
    }

    int channels = 0;


    switch(outFormat->OpenGLBaseFormat) {
    case GL_LUMINANCE:
    case GL_ALPHA:
        channels = 1;
        break;

    case GL_RGB:
        channels = 3;
        break;

    case GL_RGBA:
        channels = 4;
        break;

    default:
        alwaysAssertM(false, "This texture format is not appropriate for reading to an image.");
    }

    dst.resize(width, height, channels);

    GLenum target = dimensionToTarget(dimension);

    glPushAttrib(GL_TEXTURE_BIT);
    glBindTexture(target, textureID);

    glGetTexImage(
       target,
       0,
       outFormat->OpenGLBaseFormat,
       GL_UNSIGNED_BYTE,
       dst.byte());

    glPopAttrib();
}

Texture::Texture(
    const std::string&      _name,
    GLuint                  _textureID,
    Dimension               _dimension,
    const TextureFormat*    _format,
    InterpolateMode         _interpolate,
    WrapMode                _wrap,
    bool                    __opaque,
    DepthReadMode           __dr,
    float                   _aniso) :
    
    textureID(_textureID),
    dimension(_dimension),
    format(_format),
    _opaque(__opaque),
    _depthRead(__dr),
    _maxAnisotropy(_aniso) {

    debugAssert(_format);
    debugAssertGLOk();

    _settings.interpolateMode = _interpolate;
    _settings.wrapMode = _wrap;
    _settings.maxAnisotropy = _aniso;
    _settings.depthReadMode = __dr;
    _settings.autoMipMap = true;

    glStatePush();

        GLenum target = dimensionToTarget(_dimension);
        glBindTexture(target, _textureID);

        name = _name;

		// For cube map, we can't read "cube map" but must choose a face
		GLenum readbackTarget = target;
		if ((_dimension == DIM_CUBE_MAP) || (_dimension == DIM_CUBE_MAP_NPOT)) {
			readbackTarget = GL_TEXTURE_CUBE_MAP_POSITIVE_X_ARB;
		}

        glGetTexLevelParameteriv(readbackTarget, 0, GL_TEXTURE_WIDTH, &width);
        glGetTexLevelParameteriv(readbackTarget, 0, GL_TEXTURE_HEIGHT, &height);

        depth = 1;
        invertY = false;
        
        interpolate         = _interpolate;
        wrap                = _wrap;
        debugAssertGLOk();
        setTexParameters(target, _settings);
        debugAssertGLOk();
    glStatePop();
    debugAssertGLOk();

    _sizeOfAllTexturesInMemory += sizeInMemory();
}


TextureRef Texture::fromMemory(
    const std::string&              name,
    const uint8*                    bytes,
    const class TextureFormat*      bytesFormat,
    int                             width,
    int                             height,
    const class TextureFormat*      desiredFormat,
    Dimension                       dimension,
    const Settings&               param) {

	const uint8* b[6] = {NULL, NULL, NULL, NULL, NULL, NULL};
	b[0] = bytes;

	return Texture::fromMemory(name, b, bytesFormat, width, height, 1, 
		desiredFormat, param.wrapMode, param.interpolateMode, dimension, param.depthReadMode, param.maxAnisotropy);
}


TextureRef Texture::fromMemory(
    const std::string&              name,
    const uint8*                    bytes,
    const class TextureFormat*      bytesFormat,
    int                             width,
    int                             height,
    const class TextureFormat*      desiredFormat,
    WrapMode                        wrap,
    InterpolateMode                 interpolate,
    Dimension                       dimension,
    DepthReadMode                   depthRead,
    float                           maxAnisotropy,
    float                           scale) {

	const uint8* b[6] = {NULL, NULL, NULL, NULL, NULL, NULL};
	b[0] = bytes;

	return Texture::fromMemory(name, b, bytesFormat, width, height, 1, 
		desiredFormat, wrap, interpolate, dimension, depthRead, maxAnisotropy,
        scale);
}


void Texture::setAutoMipMap(bool b) {
    _settings.autoMipMap = b;

    // Update the OpenGL state
    GLenum target = dimensionToTarget(dimension);

    glPushAttrib(GL_TEXTURE_BIT);
    glBindTexture(target, textureID);

    if (hasAutoMipMap()) {
        glTexParameteri(target, GL_GENERATE_MIPMAP_SGIS, b ? GL_TRUE : GL_FALSE);
    }

    // Restore the old texture
    glPopAttrib();
}


TextureRef Texture::fromGLTexture(
    const std::string&      name,
    GLuint                  textureID,
    const TextureFormat*    textureFormat,
    WrapMode                wrap,
    InterpolateMode         interpolate,
    Dimension               dimension,
    DepthReadMode           depthRead,
    float                   aniso) {

    debugAssert(textureFormat);

    return new Texture(name, textureID, dimension, textureFormat, interpolate, wrap, 
        textureFormat->opaque, depthRead, aniso);
}


/**
 Scales the intensity up or down of an entire image.
 @param skipAlpha 0 if there is no alpha channel, 1 if there is 
 */
static void brightenImage(uint8* byte, int n, double brighten, int skipAlpha) {

    // Make a lookup table
    uint8 bright[256];
    for (int i = 0; i < 256; ++i) {
        bright[i] = iClamp(iRound(i * brighten), 0, 255);
    }

    for (int i = 0; i < n; i += skipAlpha) {
        for (int c = 0; c < 3; ++c, ++i) {
            byte[i] = bright[byte[i]];
        }
    }
}


Rect2D Texture::rect2DBounds() const {
    return Rect2D::xywh(0, 0, (float)width, (float)height);
}


TextureRef Texture::fromFile(
    const std::string               filename[6],
    const class TextureFormat*      desiredFormat,
    WrapMode                        wrap,
    InterpolateMode                 interpolate,
    Dimension                       dimension,
    double                          brighten,
    DepthReadMode                   depthRead,
    float                           maxAnisotropy,
    float                           sizeFactor) {

    std::string realFilename[6];

    const TextureFormat* format = TextureFormat::RGB8;
    bool opaque = true;

    // The six cube map faces, or the one texture and 5 dummys.
    GImage image[6];
    const uint8* array[6];
    for (int i = 0; i < 6; ++i) {
        array[i] = NULL;
    }

    const int numFaces = (dimension == DIM_CUBE_MAP) ?
        6 : (dimension == DIM_CUBE_MAP_NPOT) ? 
        6 : 1;

    // Check for DDS file and load separately.
    std::string ddsExt;

    // Find the period
    size_t period = filename[0].rfind('.');

    // Make sure it is before a slash!
    size_t j = iMax(filename[0].rfind('/'), filename[0].rfind('\\'));
    if ((period != std::string::npos) && (period > j)) {
        ddsExt = filename[0].substr(period + 1, filename[0].size() - period - 1);
    }

    if (G3D::toUpper(ddsExt) == "DDS") {

        debugAssertM(GLCaps::supports_GL_EXT_texture_compression_s3tc(),
            "This device does not support s3tc compression formats.");

        DDSTexture ddsTexture(filename[0]);
        Array< Array< const void* > > byteMipMapFaces;

        uint8* byteStart = ddsTexture.getBytes();
        debugAssert( byteStart != NULL );

        const TextureFormat* bytesFormat = ddsTexture.getBytesFormat();
        debugAssert( bytesFormat );

        // Assert that we are loading a cubemap DDS
        debugAssert( numFaces == ddsTexture.getNumFaces() );

        int numMipMaps = ddsTexture.getNumMipMaps();
        int mapWidth = ddsTexture.getWidth();
        int mapHeight = ddsTexture.getHeight();

        byteMipMapFaces.resize(numMipMaps);

        for (int i = 0; i < numMipMaps; ++i) {
            
            byteMipMapFaces[i].resize(numFaces);

            for (int face = 0; face < numFaces; ++face) {
                byteMipMapFaces[i][face] = byteStart;
                byteStart += ((bytesFormat->packedBitsPerTexel / 8) * ((mapWidth + 3) / 4) * ((mapHeight + 3) / 4));
            }
            mapWidth = iMax(1, iFloor(mapWidth/2));
            mapHeight = iMax(1,iFloor(mapHeight/2));
        }

        return Texture::fromMemory(filename[0], byteMipMapFaces, bytesFormat, ddsTexture.getWidth(), ddsTexture.getHeight(), 1, desiredFormat, wrap, interpolate, dimension, depthRead, maxAnisotropy, sizeFactor);
    }

    // Test for both DIM_CUBE_MAP and DIM_CUBE_MAP_NPOT
    if (numFaces == 6) {
        if (filename[1] == "") {
            // Wildcard format
            // Parse the filename into a base name and extension
            std::string filenameBase, filenameExt;
            splitFilenameAtWildCard(filename[0], filenameBase, filenameExt);
            for (int f = 0; f < 6; ++f) {
                realFilename[f] = filenameBase + cubeMapString[f] + filenameExt;
            }
        } else {
            // Separate filenames have been provided
            realFilename[0] = filename[0];
            for (int f = 1; f < 6; ++f) {
                debugAssert(filename[f] != "");
                realFilename[f] = filename[f];
            }
        }
    } else {
        debugAssertM(filename[1] == "",
            "Can't specify more than one filename unless loading a cube map");
        realFilename[0] = filename[0];
    }

    for (int f = 0; f < numFaces; ++f) {

        image[f].load(realFilename[f]);

        if (image[f].channels == 4) {
            format = TextureFormat::RGBA8;
            opaque = false;
        }

        if (desiredFormat == NULL) {
            desiredFormat = format;
        }

        array[f] = image[f].byte();
    }


    if (brighten != 1.0) {
        for (int f = 0; f < numFaces; ++f) {
            brightenImage(
                image[f].byte(),
                image[f].width * image[f].height * image[f].channels,
                brighten,
                image[f].channels - 3);
        }
    }

    TextureRef t =
        Texture::fromMemory(filename[0], array, format,
            image[0].width, image[0].height, 1,
            desiredFormat, wrap, interpolate, dimension,
            depthRead, maxAnisotropy, sizeFactor);

    return t;
}


TextureRef Texture::fromFile(
    const std::string&      filename,
    const TextureFormat*    desiredFormat,
    WrapMode                wrap,
    InterpolateMode         interpolate,
    Dimension               dimension,
    double                  brighten,
    DepthReadMode           depthRead,
    float                   maxAnisotropy,
    float                   scale) {

    std::string f[6];
    f[0] = filename;
    f[1] = "";
    f[2] = "";
    f[3] = "";
    f[4] = "";
    f[5] = "";

    return fromFile(f, desiredFormat, wrap, interpolate, dimension, brighten, depthRead, maxAnisotropy, scale);
}


TextureRef Texture::fromTwoFiles(
    const std::string&      filename,
    const std::string&      alphaFilename,
    const TextureFormat*    desiredFormat,
    WrapMode                wrap,
    InterpolateMode         interpolate,
    Dimension               dimension,
    DepthReadMode           depthRead,
    float                   maxAnisotropy) {

    debugAssert(desiredFormat);

    // The six cube map faces, or the one texture and 5 dummys.
    const uint8* array[6];
    for (int i = 0; i < 6; ++i) {
        array[i] = NULL;
    }

    const int numFaces = (dimension == DIM_CUBE_MAP) ?
        6 : (dimension == DIM_CUBE_MAP_NPOT) ? 
        6 : 1;

    // Parse the filename into a base name and extension
    std::string filenameBase = filename;
    std::string filenameExt;
    std::string alphaFilenameBase = alphaFilename;
    std::string alphaFilenameExt;

    // Test for both DIM_CUBE_MAP and DIM_CUBE_MAP_NPOT
    if (numFaces == 6) {
        splitFilenameAtWildCard(filename, filenameBase, filenameExt);
    }
    
    GImage color[6];
    GImage alpha[6];
    TextureRef t;

    try {
    for (int f = 0; f < numFaces; ++f) {

        std::string fn = filename;
        std::string an = alphaFilename;

        // Test for both DIM_CUBE_MAP and DIM_CUBE_MAP_NPOT
        if (numFaces == 6) {
            fn = filenameBase + cubeMapString[f] + filenameExt;
            an = alphaFilenameBase + cubeMapString[f] + alphaFilenameExt;
        }

        // Compose the two images to a single RGBA
        color[f].load(fn);
        alpha[f].load(an);
        uint8* data = NULL;

        if (color[f].channels == 4) {
            data = color[f].byte();
            // Write the data inline
            for (int i = 0; i < color[f].width * color[f].height; ++i) {
                data[i * 4 + 3] = alpha[f].byte()[i * alpha[f].channels];
            }
        } else {
            debugAssert(color[f].channels == 3);
            data = new uint8[color[f].width * color[f].height * 4];
            // Write the data inline
            for (int i = 0; i < color[f].width * color[f].height; ++i) {
                data[i * 4 + 0] = color[f].byte()[i * 3 + 0];
                data[i * 4 + 1] = color[f].byte()[i * 3 + 1];
                data[i * 4 + 2] = color[f].byte()[i * 3 + 2];
                data[i * 4 + 3] = alpha[f].byte()[i * alpha[f].channels];
            }
        }

        array[f] = data;
    }

    t = Texture::fromMemory(filename, array, TextureFormat::RGBA8,
            color[0].width, color[0].height, 1, 
            desiredFormat, wrap, interpolate, dimension, depthRead, maxAnisotropy);

    if (color[0].channels == 3) {
        // Delete the data if it was dynamically allocated
        for (int f = 0; f < numFaces; ++f) {
            delete[] const_cast<unsigned char*>(array[f]);
        }
    }

    } catch (const GImage::Error& e) {
        Log::common()->printf("\n**************************\n\n"
            "Loading \"%s\" failed. %s\n", e.filename.c_str(),
            e.reason.c_str());
    }

    return t;
}

static const GLenum cubeFaceTarget[] =
    {GL_TEXTURE_CUBE_MAP_POSITIVE_X_ARB,
     GL_TEXTURE_CUBE_MAP_NEGATIVE_X_ARB,
     GL_TEXTURE_CUBE_MAP_POSITIVE_Y_ARB,
     GL_TEXTURE_CUBE_MAP_NEGATIVE_Y_ARB,
     GL_TEXTURE_CUBE_MAP_POSITIVE_Z_ARB,
     GL_TEXTURE_CUBE_MAP_NEGATIVE_Z_ARB};


static bool isMipMapformat(Texture::InterpolateMode i) {
    switch (i) {
    case Texture::TRILINEAR_MIPMAP:
    case Texture::BILINEAR_MIPMAP:
    case Texture::NEAREST_MIPMAP:
        return true;

    case Texture::BILINEAR_NO_MIPMAP:
    case Texture::NEAREST_NO_MIPMAP:
    case Texture::NO_INTERPOLATION:
        return false;
    }

    alwaysAssertM(false, "Illegal interpolate mode");
    return false;
}


TextureRef Texture::fromMemory(
    const std::string&                  name,
    const Array< Array<const void*> >&  bytes,
    const TextureFormat*                bytesFormat,
    int                                 width,
    int                                 height,
    int                                 depth,
    const TextureFormat*                desiredFormat,
    WrapMode                            wrap,
    InterpolateMode                     interpolate,
    Dimension                           dimension,
    DepthReadMode                       depthRead,
    float                               maxAnisotropy,
    float                               rescaleFactor) {
        
    debugAssert(bytesFormat);
    (void)depth;
    
    // Check for at least one miplevel on the incoming data
    int numMipMaps = bytes.length();
    debugAssert( numMipMaps > 0 );

    // Create the texture
    GLuint textureID = newGLTextureID();
    GLenum target = dimensionToTarget(dimension);

    if ((desiredFormat == TextureFormat::AUTO) || (bytesFormat->compressed)) {
        desiredFormat = bytesFormat;
    }

    if (GLCaps::hasBug_redBlueMipmapSwap() && (desiredFormat == TextureFormat::RGB8)) {
        desiredFormat = TextureFormat::RGBA8;
    }

    debugAssertM(GLCaps::supports(desiredFormat), "Unsupported texture format.");

    glStatePush();

		// Set unpacking alignment
		glPixelStorei(GL_UNPACK_ALIGNMENT, 1);

        glEnable(target);
        glBindTexture(target, textureID);
        debugAssertGLOk();
        if (isMipMapformat(interpolate) && hasAutoMipMap() && (numMipMaps == 1)) {
            // Enable hardware MIP-map generation.
            // Must enable before setting the level 0 image (we'll set it again
            // in setTexParameters, but that is intended primarily for 
            // the case where that function is called for a pre-existing GL texture ID).
            glTexParameteri(target, GL_GENERATE_MIPMAP_SGIS, GL_TRUE);
        }

        int mipWidth = width;
        int mipHeight = height;
        for (int mipLevel = 0; mipLevel < numMipMaps; ++mipLevel) {

            const int numFaces = bytes[mipLevel].length();
            
            debugAssert(
                ((dimension == DIM_CUBE_MAP) ? 
                6 : (dimension == DIM_CUBE_MAP_NPOT) ? 
                6 : 1) == numFaces);
        
            for (int f = 0; f < numFaces; ++f) {
        
                // Test for both DIM_CUBE_MAP and DIM_CUBE_MAP_NPOT
                if (numFaces == 6) {
                    // Choose the appropriate face target
                    target = cubeFaceTarget[f];
                }

                if (isMipMapformat(interpolate) && ! hasAutoMipMap() && (numMipMaps == 1)) {

                    debugAssertM((bytesFormat->compressed == false), "Cannot manually generate Mip-Maps for compressed textures.");

                    createMipMapTexture(target, reinterpret_cast<const uint8*>(bytes[mipLevel][f]),
                                  bytesFormat->OpenGLBaseFormat,
                                  mipWidth, mipHeight, desiredFormat->OpenGLFormat,
                                  desiredFormat->packedBitsPerTexel / 8, rescaleFactor);
                } else {
                    const bool useNPOT = (dimension == DIM_2D_NPOT) ?
                        true : (dimension == DIM_CUBE_MAP_NPOT) ?
                        true : false;

                    createTexture(target, reinterpret_cast<const uint8*>(bytes[mipLevel][f]), bytesFormat->OpenGLBaseFormat,
                                  bytesFormat->OpenGLFormat, mipWidth, mipHeight, desiredFormat->OpenGLFormat, 
                                  bytesFormat->packedBitsPerTexel / 8, mipLevel, bytesFormat->compressed, useNPOT, 
                                  rescaleFactor);
                }

                debugAssertGLOk();
            }

            mipWidth = iMax(1, mipWidth / 2);
            mipHeight = iMax(1, mipHeight / 2);
        }
    glStatePop();

    if ((dimension != DIM_2D_RECT) &&
        ((dimension != DIM_2D_NPOT && dimension != DIM_CUBE_MAP_NPOT))) {
        width  = ceilPow2(width);
        height = ceilPow2(height);
    }

    debugAssertGLOk();
    TextureRef t = fromGLTexture(name, textureID, desiredFormat, wrap, interpolate, dimension, depthRead, maxAnisotropy);
    debugAssertGLOk();

    t->width = width;
    t->height = height;
    return t;
}


TextureRef Texture::fromMemory(
    const std::string&      name,
    const uint8**           bytes,
    const TextureFormat*    bytesFormat,
    int                     width,
    int                     height,
    int                     depth,
    const TextureFormat*    desiredFormat,
    WrapMode                wrap,
    InterpolateMode         interpolate,
    Dimension               dimension,
    DepthReadMode           depthRead,
    float                   maxAnisotropy,
    float                   rescaleFactor) {

    Array< Array<const void* > > arrayMipMapFaces(1);

    const int numFaces = (dimension == DIM_CUBE_MAP) ?
        6 : (dimension == DIM_CUBE_MAP_NPOT) ? 
        6 : 1;        

    for (int f = 0; f < numFaces; ++f) {
        arrayMipMapFaces[0].append(bytes[f]);
    }

    return Texture::fromMemory(name, arrayMipMapFaces, bytesFormat, width, height, 
        depth, desiredFormat, wrap, interpolate, dimension, depthRead, maxAnisotropy,
        rescaleFactor);
}


TextureRef Texture::fromGImage(
    const std::string&              name,
    const GImage&                   image,
    const class TextureFormat*      desiredFormat,
    WrapMode                        wrap,
    InterpolateMode                 interpolate,
    Dimension                       dimension,
    DepthReadMode                   depthRead,
    float                           maxAnisotropy) {

    const TextureFormat* format = TextureFormat::RGB8;
    bool opaque = true;

    // The six cube map faces, or the one texture and 5 dummys.
    const uint8* array[1];

    switch (image.channels) {
    case 4:
        format = TextureFormat::RGBA8;
        opaque = false;
        break;

    case 3:
        format = TextureFormat::RGB8;
        opaque = true;
        break;

    case 1:
        format = TextureFormat::L8;
        opaque = true;
        break;

    default:
        alwaysAssertM(
            false,
            G3D::format("GImage has an unexpected number of channels (%d)", image.channels));
    }

    if (desiredFormat == NULL) {
        desiredFormat = format;
    }

    array[0] = image.byte();

    TextureRef t =
        Texture::fromMemory(name, array, format,
            image.width, image.height, 1,
            desiredFormat, wrap, interpolate, 
            dimension, depthRead, maxAnisotropy);

    return t;
}


TextureRef Texture::createEmpty(
    int                              w,
    int                              h,
    const std::string&               name,
    const TextureFormat*             desiredFormat,
    Texture::WrapMode                wrap,
    Texture::InterpolateMode         interpolate,
    Texture::Dimension               dimension,
    Texture::DepthReadMode           depthRead,
    float                            maxAnisotropy) {

    debugAssertGLOk();
    debugAssertM(desiredFormat, "desiredFormat may not be TextureFormat::AUTO");

    // We must pretend the input is in the desired format otherwise 
    // OpenGL might refuse to negotiate formats for us.
    Array<uint8> data(w * h * desiredFormat->packedBitsPerTexel / 8);
    const uint8* bytes[6];
    for (int i = 0; i < 6; ++i) {
        bytes[i] = data.getCArray();
    }

    TextureRef t = Texture::fromMemory(name, bytes, desiredFormat, w, h, 1, desiredFormat, 
        wrap, interpolate, dimension, depthRead, maxAnisotropy);

    debugAssertGLOk();
    return t;
}


void Texture::splitFilenameAtWildCard(
    const std::string&  filename,
    std::string&        filenameBase,
    std::string&        filenameExt) {

    const std::string splitter = "*";

    int i = filename.rfind(splitter);
    if (i != -1) {
        filenameBase = filename.substr(0, i);
        filenameExt  = filename.substr(i + 1, filename.size() - i - splitter.length()); 
    } else {
        throw GImage::Error("Cube map filenames must contain \"*\" as a "
                            "placeholder for up/lf/rt/bk/ft/dn", filename);
    }
}


Texture::~Texture() {
    _sizeOfAllTexturesInMemory -= sizeInMemory();
	glDeleteTextures(1, &textureID);
	textureID = 0;
}


unsigned int Texture::newGLTextureID() {
    unsigned int t;

    // Clear the OpenGL error flag
    glGetError();

    glGenTextures(1, &t);

    alwaysAssertM(glGetError() != GL_INVALID_OPERATION, 
         "GL_INVALID_OPERATION: Probably caused by invoking "
         "glGenTextures between glBegin and glEnd.");

    return t;
}


/** Returns the buffer constant that matches the current draw buffer (left vs. right) */
static GLenum getCurrentBuffer(bool useBack) {
    GLenum draw = glGetInteger(GL_DRAW_BUFFER);

    if (useBack) {
        switch (draw) {
        case GL_FRONT_LEFT:
        case GL_BACK_LEFT:
            return GL_BACK_LEFT;

        case GL_FRONT_RIGHT:
        case GL_BACK_RIGHT:
            return GL_BACK_RIGHT;

        default:
			// FBO goes here
            return draw;
        }
    } else {
        switch (draw) {
        case GL_FRONT_LEFT:
        case GL_BACK_LEFT:
            return GL_FRONT_LEFT;

        case GL_FRONT_RIGHT:
        case GL_BACK_RIGHT:
            return GL_FRONT_RIGHT;

        default:
			// FBO goes here
            return draw;
        }
    }
}


void Texture::copyFromScreen(
    const Rect2D& rect,
    bool useBackBuffer) {

    glStatePush();

    glReadBuffer(getCurrentBuffer(useBackBuffer));

    _sizeOfAllTexturesInMemory -= sizeInMemory();

    // Set up new state
    this->width   = (int)rect.width();
    this->height  = (int)rect.height();
    this->depth   = 1;
    debugAssert(this->dimension == DIM_2D || this->dimension == DIM_2D_RECT || this->dimension == DIM_2D_NPOT);

    if (GLCaps::supports_GL_ARB_multitexture()) {
        glActiveTextureARB(GL_TEXTURE0_ARB);
    }
    glDisableAllTextures();
    GLenum target = dimensionToTarget(dimension);
    glEnable(target);

    glBindTexture(target, textureID);
    int e = glGetError();
    alwaysAssertM(e == GL_NONE, 
        std::string("Error encountered during glBindTexture: ") + GLenumToString(e));

    double viewport[4];
    glGetDoublev(GL_VIEWPORT, viewport);
    double viewportHeight = viewport[3];
    debugAssertGLOk();
    
    glCopyTexImage2D(target, 0, format->OpenGLFormat,
                     iRound(rect.x0()), 
                     iRound(viewportHeight - rect.y1()), 
                     iRound(rect.width()), iRound(rect.height()), 
                     0);

    debugAssertGLOk();
    // Reset the original properties
    setTexParameters(target, _settings);

    debugAssertGLOk();
    glDisable(target);

    // Once copied from the screen, the direction will be reversed.
    invertY = true;

    glStatePop();

    _sizeOfAllTexturesInMemory += sizeInMemory();
}


void Texture::copyFromScreen(
    const Rect2D&       rect,
    CubeFace            face,
    bool                useBackBuffer) {

    glStatePush();

    glReadBuffer(getCurrentBuffer(useBackBuffer));

    // Set up new state
    debugAssertM(width == rect.width(), "Cube maps require all six faces to have the same dimensions");
    debugAssertM(height == rect.height(), "Cube maps require all six faces to have the same dimensions");
    debugAssert(this->dimension == DIM_CUBE_MAP || this->dimension == DIM_CUBE_MAP_NPOT);
    debugAssert(face >= 0);
    debugAssert(face < 6);

    if (GLCaps::supports_GL_ARB_multitexture()) {
        glActiveTextureARB(GL_TEXTURE0_ARB);
    }
    glDisableAllTextures();

    glEnable(GL_TEXTURE_CUBE_MAP_ARB);
    glBindTexture(GL_TEXTURE_CUBE_MAP_ARB, textureID);

    GLenum target = cubeFaceTarget[(int)face];

    int e = glGetError();
    alwaysAssertM(e == GL_NONE, 
        std::string("Error encountered during glBindTexture: ") + GLenumToString(e));

    double viewport[4];
    glGetDoublev(GL_VIEWPORT, viewport);
    double viewportHeight = viewport[3];
    debugAssertGLOk();

    glCopyTexImage2D(target, 0, format->OpenGLFormat,
                     iRound(rect.x0()), 
                     iRound(viewportHeight - rect.y1()), 
                     iRound(rect.width()), 
                     iRound(rect.height()), 0);

    debugAssertGLOk();
    glDisable(GL_TEXTURE_CUBE_MAP_ARB);
    glStatePop();
}


void Texture::getCameraRotation(CubeFace face, Matrix3& outMatrix) {
    switch (face) {
    case CUBE_POS_X:
        outMatrix = Matrix3::fromEulerAnglesYXZ((float)G3D_HALF_PI, (float)G3D_PI, 0);
        break;

    case CUBE_NEG_X:
        outMatrix = Matrix3::fromEulerAnglesYXZ(-(float)G3D_HALF_PI, (float)G3D_PI, 0);
        break;

    case CUBE_POS_Y:
        outMatrix = Matrix3::fromEulerAnglesXYZ((float)G3D_HALF_PI, 0, 0);
        break;

    case CUBE_NEG_Y:
        outMatrix = Matrix3::fromEulerAnglesXYZ(-(float)G3D_HALF_PI, 0, 0);
        break;

    case CUBE_POS_Z:
        outMatrix = Matrix3::fromEulerAnglesYZX((float)G3D_PI, (float)G3D_PI, 0);
        break;

    case CUBE_NEG_Z:
        outMatrix = Matrix3::fromAxisAngle(Vector3::unitZ(), (float)G3D_PI);
        break;
    }
}


size_t Texture::sizeInMemory() const {

	if (!TextureFormat::valid)
		return 0;

    int base = (width * height * depth * format->hardwareBitsPerTexel) / 8;

    int total = 0;

    if (interpolate == TRILINEAR_MIPMAP) {
        int w = width;
        int h = height;

        while ((w > 2) && (h > 2)) {
            total += base;
            base /= 4;
            w /= 2;
            h /= 2;
        }

    } else {
        total = base;
    }

    if (dimension == DIM_CUBE_MAP) {
        total *= 6;
    }

    return total;
}


unsigned int Texture::getOpenGLTextureTarget() const {
    switch (dimension) {
    case DIM_CUBE_MAP_NPOT:
    case DIM_CUBE_MAP:
        return GL_TEXTURE_CUBE_MAP_ARB;

    case DIM_2D_NPOT:
    case DIM_2D:
        return GL_TEXTURE_2D;

    case Texture::DIM_2D_RECT:
        return GL_TEXTURE_RECTANGLE_EXT;

    default:
        debugAssertM(false, "Fell through switch");
    }
    return 0;
}


TextureRef Texture::alphaOnlyVersion() const {
    if (opaque()) {
        return NULL;
    }

    debugAssert(_depthRead == DEPTH_NORMAL);
    debugAssertM(
        dimension == DIM_2D ||
        dimension == DIM_2D_RECT ||
        dimension == DIM_2D_NPOT,
        "alphaOnlyVersion only supported for 2D textures");

    int numFaces = 1;

    uint8** bytes = (uint8**)System::malloc(numFaces * sizeof(uint8*));
    const TextureFormat* bytesFormat = TextureFormat::A8;

    glStatePush();
    // Setup to later implement cube faces
    for (int f = 0; f < numFaces; ++f) {
        GLenum target = dimensionToTarget(dimension);
        glBindTexture(target, textureID);
        bytes[f] = (uint8*)System::malloc(width * height);
        glGetTexImage(target, 0, GL_ALPHA, GL_UNSIGNED_BYTE, bytes[f]);
    }

    glStatePop();

    TextureRef ret = 
        fromMemory(name + " Alpha", (const uint8**)bytes, bytesFormat,
            width, height, 1, TextureFormat::A8, wrap, interpolate,
            dimension); 

    for (int f = 0; f < numFaces; ++f) {
        System::free(bytes[f]);
    }
    System::free(bytes);

    return ret;
}

} // G3D
