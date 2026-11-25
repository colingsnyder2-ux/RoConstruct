// native-flags: /O2 /GS- /EHsc /MD /fp:fast /I{libs}/g3d-6.09/source/include /I{libs}/g3d-6.09/source/boost/include /I{libs}/SDL-1.2.11/include
// native-profile: vendor
#include "GLG3D/glcalls.h"
#include "GLG3D/Texture.h"
#include "GLG3D/GLCaps.h"

extern "C" bool fn_00471060(const std::string&) throw(...);
extern "C" bool fn_004729d0(void) throw(...);

extern "C" {
static __declspec(noinline) void fn_00472f10(
    GLenum target,
    const G3D::Texture::Settings& settings) throw(...)
{
    using namespace G3D;

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
            Color4 black(0, 0, 0, 0);
            glTexParameterfv(target, GL_TEXTURE_BORDER_COLOR, black);
        }
        break;
    }
    glTexParameteri(target, GL_TEXTURE_WRAP_S, mode);
    glTexParameteri(target, GL_TEXTURE_WRAP_T, mode);
    if (supports3D) {
        glTexParameteri(target, GL_TEXTURE_WRAP_R, mode);
    }

    if (fn_00471060("GL_EXT_texture_lod")) {
        glTexParameteri(target, GL_TEXTURE_MAX_LOD_SGIS, settings.maxMipMap);
        glTexParameteri(target, GL_TEXTURE_MIN_LOD_SGIS, settings.minMipMap);
    }

    switch (settings.interpolateMode) {
    case Texture::TRILINEAR_MIPMAP:
        glTexParameteri(target, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
        glTexParameteri(target, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
        if (fn_004729d0()) {
            glTexParameteri(target, GL_GENERATE_MIPMAP_SGIS, GL_TRUE);
        }
        break;

    case Texture::BILINEAR_MIPMAP:
        glTexParameteri(target, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
        glTexParameteri(target, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_NEAREST);
        if (fn_004729d0() && settings.autoMipMap) {
            glTexParameteri(target, GL_GENERATE_MIPMAP_SGIS, GL_TRUE);
        }
        break;

    case Texture::NEAREST_MIPMAP:
        glTexParameteri(target, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
        glTexParameteri(target, GL_TEXTURE_MIN_FILTER, GL_NEAREST_MIPMAP_NEAREST);
        if (fn_004729d0() && settings.autoMipMap) {
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
    }

    static const bool anisotropic = fn_00471060("GL_EXT_texture_filter_anisotropic");
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
}
}

// INFERRED: thin caller anchors the static helper's register-passed target (esi) in this TU.
void _anchor_caller(GLenum target, const G3D::Texture::Settings& settings) {
    fn_00472f10(target, settings);
}
