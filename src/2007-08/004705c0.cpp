// from server: 61% by EspClaude
// from server: 52% by Intel
// from server: 50% by colin
// roc-lang: cpp
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: g3d-6.09 roc_claude_f39bba4674992196.cpp

// Candidate translation unit (score above; library headers required).
/**
 @file Texture.cpp (destructor only; sizeInMemory is an out-of-line call at 0x470390 in the target)
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

namespace G3D {

Texture::~Texture() {
    _sizeOfAllTexturesInMemory -= sizeInMemory();
	glDeleteTextures(1, &textureID);
	textureID = 0;
}

}
