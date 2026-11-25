// native-flags: /O2 /GS- /EHsc /MD /fp:fast /I{libs}/g3d-6.09/source/include /I{libs}/g3d-6.09/source/boost/include /I{libs}/SDL-1.2.11/include
// native-profile: vendor
#include "G3D/Log.h"
#include "G3D/Matrix3.h"
#include "G3D/Rect2D.h"
#include "G3D/GImage.h"
#include "G3D/fileutils.h"
#include "GLG3D/glcalls.h"
#include "GLG3D/TextureFormat.h"
#define private public
#include "GLG3D/Texture.h"
#undef private
#include "GLG3D/getOpenGLState.h"
#include "GLG3D/GLCaps.h"

namespace G3D {

static void glStatePush() {
    glPushAttrib(GL_ALL_ATTRIB_BITS);
    glPushClientAttrib(GL_ALL_CLIENT_ATTRIB_BITS);

    if (GLCaps::supports_GL_ARB_multitexture()) {
        glActiveTextureARB(GL_TEXTURE0_ARB);
    }
}

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

} // namespace G3D

extern "C" {

static __declspec(noinline) G3D::TextureRef __stdcall fn_00474a50(
    const G3D::Texture* self) throw(...)
{
    using namespace G3D;

    if (self->opaque()) {
        return NULL;
    }

    int numFaces = 1;

    uint8** bytes = (uint8**)System::malloc(numFaces * sizeof(uint8*));
    const TextureFormat* bytesFormat = TextureFormat::A8;

    glStatePush();
    for (int f = 0; f < numFaces; ++f) {
        GLenum target = dimensionToTarget(self->dimension);
        glBindTexture(target, self->textureID);
        bytes[f] = (uint8*)System::malloc(self->width * self->height);
        glGetTexImage(target, 0, GL_ALPHA, GL_UNSIGNED_BYTE, bytes[f]);
    }

    glStatePop();

    TextureRef ret =
        Texture::fromMemory(self->name + " Alpha", (const uint8**)bytes, bytesFormat,
            self->width, self->height, 1, TextureFormat::A8,
            self->wrap, self->interpolate, self->dimension);

    for (int f = 0; f < numFaces; ++f) {
        System::free(bytes[f]);
    }
    System::free(bytes);

    return ret;
}

}

extern "C" G3D::TextureRef __stdcall anchor_caller(const G3D::Texture* t) {
    return fn_00474a50(t);
}
