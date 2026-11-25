// native-flags: /O2 /GS- /EHsc /MD /fp:fast /I{libs}/g3d-6.09/source/include /I{libs}/g3d-6.09/source/boost/include /I{libs}/SDL-1.2.11/include
// native-profile: vendor
#include "GLG3D/Texture.h"

namespace G3D {

size_t Texture::_sizeOfAllTexturesInMemory = 0;

__forceinline Texture::~Texture() {
    _sizeOfAllTexturesInMemory -= sizeInMemory();
    glDeleteTextures(1, &textureID);
    textureID = 0;
}

}

extern "C" void __fastcall fn_00473980(G3D::Texture* self, int unusedEdx) throw(...) {
    self->G3D::Texture::~Texture();
}

namespace G3D {

size_t Texture::sizeInMemory() const {
    if (!TextureFormat::valid) {
        return 0;
    }

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

}
