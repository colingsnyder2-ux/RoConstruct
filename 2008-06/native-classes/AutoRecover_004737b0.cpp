// native-flags: /O2 /GS- /EHsc /MD /fp:fast /I{libs}/g3d-6.09/source/include /I{libs}/g3d-6.09/source/boost/include /I{libs}/SDL-1.2.11/include
// native-profile: vendor
#include "GLG3D/glcalls.h"
#include "GLG3D/Texture.h"
#include "GLG3D/GLCaps.h"

extern "C" unsigned int g_0096ef44;
extern "C" bool fn_00471060(const std::string&) throw(...);
extern "C" bool fn_004729d0(void) throw(...);

namespace G3D {

Texture::Settings::Settings() :
    interpolateMode(TRILINEAR_MIPMAP),
    wrapMode(TILE),
    depthReadMode(DEPTH_NORMAL),
    maxAnisotropy(2.0),
    autoMipMap(true),
    minMipMap(-1000),
    maxMipMap(1000) {
}

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

}

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

inline void* __cdecl operator new(size_t, void* p, int) throw() { return p; }

struct Local_4737b0 : public G3D::ReferenceCountedObject {
    GLuint textureID;
    G3D::Texture::DepthReadMode _depthRead;
    float _maxAnisotropy;
    G3D::Texture::InterpolateMode interpolate;
    G3D::Texture::WrapMode wrap;
    G3D::Texture::Settings _settings;
    std::string name;
    G3D::Texture::Dimension dimension;
    bool _opaque;
    const G3D::TextureFormat* format;
    int width;
    int height;
    int depth;
    bool invertY;

    size_t sizeInMemory() const;

    __forceinline Local_4737b0(
        const std::string& _name, GLuint _textureID, G3D::Texture::Dimension _dimension,
        const G3D::TextureFormat* _format, G3D::Texture::InterpolateMode _interpolate,
        G3D::Texture::WrapMode _wrap, bool __opaque, G3D::Texture::DepthReadMode __dr, float _aniso) :
        textureID(_textureID), dimension(_dimension), format(_format),
        _opaque(__opaque), _depthRead(__dr), _maxAnisotropy(_aniso) {
        _settings.interpolateMode = _interpolate;
        _settings.wrapMode = _wrap;
        _settings.maxAnisotropy = _aniso;
        _settings.depthReadMode = __dr;
        _settings.autoMipMap = true;
        G3D::glStatePush();
        GLenum target = G3D::dimensionToTarget(_dimension);
        glBindTexture(target, _textureID);
        name = _name;
        GLenum readbackTarget = target;
        if ((_dimension == G3D::Texture::DIM_CUBE_MAP) || (_dimension == G3D::Texture::DIM_CUBE_MAP_NPOT)) {
            readbackTarget = GL_TEXTURE_CUBE_MAP_POSITIVE_X_ARB;
        }
        glGetTexLevelParameteriv(readbackTarget, 0, GL_TEXTURE_WIDTH, &width);
        glGetTexLevelParameteriv(readbackTarget, 0, GL_TEXTURE_HEIGHT, &height);
        depth = 1;
        invertY = false;
        interpolate = _interpolate;
        wrap = _wrap;
        fn_00472f10(target, _settings);
        G3D::glStatePop();
        g_0096ef44 += sizeInMemory();
    }
    virtual ~Local_4737b0() {}
};

extern "C" Local_4737b0* __fastcall fn_004737b0(
    Local_4737b0* self, int unusedEdx,
    const std::string& _name, unsigned int _textureID,
    G3D::Texture::Dimension _dimension, const G3D::TextureFormat* _format,
    G3D::Texture::InterpolateMode _interpolate, G3D::Texture::WrapMode _wrap,
    bool __opaque, G3D::Texture::DepthReadMode __dr, float _aniso) throw(...)
{
    __assume(self != 0);
    return new (self, 0) Local_4737b0(_name, _textureID, _dimension, _format, _interpolate, _wrap, __opaque, __dr, _aniso);
}
