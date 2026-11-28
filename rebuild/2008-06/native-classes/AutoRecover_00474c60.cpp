// native-flags: /O2 /GS- /EHsc /MD /fp:fast /I{libs}/g3d-6.09/source/include /I{libs}/g3d-6.09/source/boost/include /I{libs}/SDL-1.2.11/include
// native-profile: vendor
#include "G3D/Log.h"
#include "G3D/Matrix3.h"
#include "G3D/Rect2D.h"
#include "G3D/GImage.h"
#include "G3D/fileutils.h"
#include "GLG3D/glcalls.h"
#include "GLG3D/TextureFormat.h"
#include "G3D/ReferenceCount.h"
#include "G3D/Array.h"
#include "GLG3D/glheaders.h"
#include "G3D/Vector2.h"
#define private public
#include "GLG3D/Texture.h"
#undef private
#include "GLG3D/getOpenGLState.h"
#include "GLG3D/GLCaps.h"

namespace G3D {

static const char* cubeMapString[] = {"ft", "bk", "up", "dn", "rt", "lf"};

static void brightenImage(uint8* byte, int n, double brighten, int skipAlpha) {
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

} // namespace G3D

extern "C" G3D::TextureRef fn_00474c60(
    const std::string               filename[6],
    const G3D::TextureFormat*       desiredFormat,
    G3D::Texture::WrapMode          wrap,
    G3D::Texture::InterpolateMode   interpolate,
    G3D::Texture::Dimension         dimension,
    double                          brighten,
    G3D::Texture::DepthReadMode     depthRead,
    float                           maxAnisotropy,
    float                           sizeFactor) throw(...)
{
    using namespace G3D;

    std::string realFilename[6];

    const TextureFormat* format = TextureFormat::RGB8;
    bool opaque = true;

    GImage image[6];
    const uint8* array[6];
    for (int i = 0; i < 6; ++i) {
        array[i] = NULL;
    }

    const int numFaces = (dimension == Texture::DIM_CUBE_MAP) ?
        6 : (dimension == Texture::DIM_CUBE_MAP_NPOT) ?
        6 : 1;

    std::string ddsExt;

    size_t period = filename[0].rfind('.');

    size_t j = iMax(filename[0].rfind('/'), filename[0].rfind('\\'));
    if ((period != std::string::npos) && (period > j)) {
        ddsExt = filename[0].substr(period + 1, filename[0].size() - period - 1);
    }

    if (G3D::toUpper(ddsExt) == "DDS") {

        debugAssertM(GLCaps::supports_GL_EXT_texture_compression_s3tc(),
            "This device does not support s3tc compression formats.");

        Texture::DDSTexture ddsTexture(filename[0]);
        Array< Array< const void* > > byteMipMapFaces;

        uint8* byteStart = ddsTexture.getBytes();
        debugAssert( byteStart != NULL );

        const TextureFormat* bytesFormat = ddsTexture.getBytesFormat();
        debugAssert( bytesFormat );

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
            mapHeight = iMax(1, iFloor(mapHeight/2));
        }

        return Texture::fromMemory(filename[0], byteMipMapFaces, bytesFormat, ddsTexture.getWidth(), ddsTexture.getHeight(), 1, desiredFormat, wrap, interpolate, dimension, depthRead, maxAnisotropy, sizeFactor);
    }

    if (numFaces == 6) {
        if (filename[1] == "") {
            std::string filenameBase, filenameExt;
            Texture::splitFilenameAtWildCard(filename[0], filenameBase, filenameExt);
            for (int f = 0; f < 6; ++f) {
                realFilename[f] = filenameBase + cubeMapString[f] + filenameExt;
            }
        } else {
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

namespace G3D {

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

}
