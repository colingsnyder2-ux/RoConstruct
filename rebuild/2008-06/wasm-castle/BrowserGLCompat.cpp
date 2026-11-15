#include "OgreException.h"
#include "OgreGLPrerequisites.h"
#include <emscripten.h>
#include <emscripten/html5_webgl.h>

static void unsupported(const char* operation)
{
    OGRE_EXCEPT(Ogre::Exception::ERR_NOT_IMPLEMENTED,
        Ogre::String(operation) + " is unavailable in the WebGL 2 demo backend", "BrowserGLCompat");
}

extern "C" {
void glColorMaterial(GLenum face, GLenum mode)
{
    if (face != GL_FRONT_AND_BACK && face != GL_FRONT) unsupported("Back-face-only colour material");
    EM_ASM({ GLImmediate.lastRenderer?.cleanup(); GLImmediate.currentRenderer = null;
             GLEmulation.colorMaterialMode = $0; }, mode);
}
const GLubyte* gluErrorString(GLenum error)
{
    const char* message = "Unknown GL error";
    switch (error) {
        case GL_NO_ERROR: message = "No error"; break;
        case GL_INVALID_ENUM: message = "Invalid enum"; break;
        case GL_INVALID_VALUE: message = "Invalid value"; break;
        case GL_INVALID_OPERATION: message = "Invalid operation"; break;
        case GL_OUT_OF_MEMORY: message = "Out of memory"; break;
        case GL_INVALID_FRAMEBUFFER_OPERATION_EXT: message = "Incomplete framebuffer"; break;
    }
    return reinterpret_cast<const GLubyte*>(message);
}
void glLightf(GLenum, GLenum parameter, GLfloat value)
{
    // The castle has a directional sun. These state values cannot affect a
    // directional source; reject positional/spot settings rather than hide them.
    if ((parameter == GL_SPOT_CUTOFF && value == 180) ||
        (parameter == GL_SPOT_EXPONENT && value == 0) ||
        (parameter == GL_CONSTANT_ATTENUATION && value == 1) ||
        ((parameter == GL_LINEAR_ATTENUATION || parameter == GL_QUADRATIC_ATTENUATION) && value == 0)) return;
    unsupported("Positional/spot light attenuation");
}
void glLightModeli(GLenum parameter, GLint value)
{
    // Shader generation in port_patches.py implements these two Ogre settings.
    if (parameter == GL_LIGHT_MODEL_COLOR_CONTROL && value == GL_SEPARATE_SPECULAR_COLOR) return;
    if (parameter == GL_LIGHT_MODEL_LOCAL_VIEWER && value == 1) return;
    if (parameter == GL_LIGHT_MODEL_TWO_SIDE) { glLightModelf(parameter, float(value)); return; }
    unsupported("Light model setting");
}
void glMaterialf(GLenum face, GLenum parameter, GLfloat value) { glMaterialfv(face, parameter, &value); }
void glTexImage1D(GLenum, GLint, GLint, GLsizei, GLint, GLenum, GLenum, const GLvoid*) { unsupported("1D texture allocation"); }
void glTexSubImage1D(GLenum, GLint, GLint, GLsizei, GLenum, GLenum, const GLvoid*) { unsupported("1D texture upload"); }
void glCopyTexSubImage1D(GLenum, GLint, GLint, GLint, GLint, GLsizei) { unsupported("1D texture framebuffer copy"); }
GLint gluBuild1DMipmaps(GLenum, GLint, GLsizei, GLenum, GLenum, const void*) { unsupported("1D mipmaps"); return 0; }
GLint gluBuild2DMipmaps(GLenum target, GLint internalFormat, GLsizei width, GLsizei height,
                      GLenum format, GLenum type, const void* pixels)
{
    glTexImage2D(target, 0, internalFormat, width, height, 0, format, type, pixels);
    typedef void (*GenerateMipmap)(GLenum);
    GenerateMipmap generate = reinterpret_cast<GenerateMipmap>(emscripten_webgl_get_proc_address("glGenerateMipmap"));
    if (!generate) unsupported("Mipmap generation");
    // GLU receives one cube face at a time. WebGL generates the complete cube
    // chain only after the last face has been uploaded.
    if (target >= GL_TEXTURE_CUBE_MAP_POSITIVE_X && target <= GL_TEXTURE_CUBE_MAP_NEGATIVE_Z) {
        if (target != GL_TEXTURE_CUBE_MAP_NEGATIVE_Z) return 0;
        target = GL_TEXTURE_CUBE_MAP;
    }
    generate(target);
    return glGetError() == GL_NO_ERROR ? 0 : GLU_INVALID_OPERATION;
}
}

EM_JS(void, browserReadTexture, (unsigned texture, unsigned face, int level,
    unsigned width, unsigned height, void* output), {
    var draw = GLctx.getParameter(GLctx.DRAW_FRAMEBUFFER_BINDING);
    var read = GLctx.getParameter(GLctx.READ_FRAMEBUFFER_BINDING);
    var fbo = GLctx.createFramebuffer();
    GLctx.bindFramebuffer(GLctx.FRAMEBUFFER, fbo);
    GLctx.framebufferTexture2D(GLctx.FRAMEBUFFER, GLctx.COLOR_ATTACHMENT0, face, GL.textures[texture], level);
    if (GLctx.checkFramebufferStatus(GLctx.FRAMEBUFFER) !== GLctx.FRAMEBUFFER_COMPLETE)
        abort('Texture readback framebuffer incomplete');
    GLctx.readPixels(0, 0, width, height, GLctx.RGBA, GLctx.UNSIGNED_BYTE,
        HEAPU8.subarray(output, output + width * height * 4));
    GLctx.bindFramebuffer(GLctx.DRAW_FRAMEBUFFER, draw);
    GLctx.bindFramebuffer(GLctx.READ_FRAMEBUFFER, read);
    GLctx.deleteFramebuffer(fbo);
});
