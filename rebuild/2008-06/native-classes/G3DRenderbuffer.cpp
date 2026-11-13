// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /fp:fast
// 2008-06 native G3DRenderbuffer (inactive): upstream tools/libs/g3d-6.09/source/GLG3Dcpp/Renderbuffer.cpp, verbatim.
// >>> native-status (generated) -- do not edit >>>
// G3DRenderbuffer | 2008-06 | draft (no current byte proof)
// no original address mapped to this file yet | by -
// <<< native-status | src e75f6fb2 | roc native-status --write
#line 1 ".\\glg3dcpp\\Renderbuffer.cpp"
/**
@file Renderbuffer.cpp

@maintainer Daniel Hilferty, djhilferty@users.sourceforge.net

@cite http://oss.sgi.com/projects/ogl-sample/registry/EXT/framebuffer_object.txt

@created 2006-01-07
@edited  2006-02-14
*/

#include "GLG3D/Renderbuffer.h"
#include "GLG3D/glcalls.h"
#include "GLG3D/TextureFormat.h"

namespace G3D {


/////////////////////////////////////////////////////////////////////////////

Renderbuffer::Renderbuffer (	
    const std::string&			_name, 
    const GLuint				_imageID,
    const G3D::TextureFormat*	_format, 
    const int					_width, 
    const int					_height) : 
    mName(_name),
    mImageID(_imageID),
    mFormat(_format),
    mWidth(_width),
    mHeight(_height) {

    // Intentionally empty
}


Renderbuffer::~Renderbuffer () {
    glDeleteRenderbuffersEXT(1, &mImageID);
}


RenderbufferRef Renderbuffer::fromGLRenderbuffer(
    const std::string&			_name, 
    const GLuint				_imageID,
    const G3D::TextureFormat	*_format) {

    GLint w, h;

    // Extract the width and height
    glGetRenderbufferParameterivEXT (GL_RENDERBUFFER_EXT, GL_RENDERBUFFER_WIDTH_EXT, &w);
    glGetRenderbufferParameterivEXT (GL_RENDERBUFFER_EXT, GL_RENDERBUFFER_WIDTH_EXT, &h);
    debugAssertGLOk();

    // Create new renderbuffer
    return new Renderbuffer(_name, _imageID, _format, w, h);
}


RenderbufferRef Renderbuffer::createEmpty(
    const std::string&			_name, 
    const G3D::TextureFormat*   _format, 
    const int					_width, 
    const int					_height) {
    // New Renderbuffer ID
    GLuint _imageID;

    // Save old renderbuffer state
    GLint origBuffer;
    glGetIntegerv(GL_RENDERBUFFER_BINDING_EXT, &origBuffer);

    // Generate buffer
    glGenRenderbuffersEXT (1, &_imageID);
    debugAssertGLOk();

    // Bind the buffer
    glBindRenderbufferEXT (GL_RENDERBUFFER_EXT, _imageID);
    debugAssertGLOk();

    // Allocate storage for it
    glRenderbufferStorageEXT(GL_RENDERBUFFER_EXT, _format->OpenGLFormat, _width, _height);

    // Check for successful generation (ie, no INVALID_OPERATION)
    debugAssertGLOk();

    // Restore renderbuffer state
    glBindRenderbufferEXT (GL_RENDERBUFFER_EXT, origBuffer);
    debugAssertGLOk();

    // Create new renderbuffer
    return new Renderbuffer(_name, _imageID, _format, _width, _height);
}

} // End Namespace G3D
