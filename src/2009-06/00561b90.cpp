// from server: 100% by auto
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: g3d-6.09 GLG3Dcpp/PixelProgram.cpp

// Candidate translation unit (score above; library headers required).
/**
  @file PixelProgram.cpp

  @maintainer Morgan McGuire, matrix@graphics3d.com

  @created 2003-04-13
  @edited  2003-09-09
*/

#include "GLG3D/PixelProgram.h"

namespace G3D {


PixelProgram::PixelProgram(const std::string& name, const std::string& filename) : 
    GPUProgram(name, filename) {
}


PixelProgramRef PixelProgram::fromFile(const std::string& _filename) {
    PixelProgram* v = new PixelProgram(_filename, _filename);
    v->reload(std::string(""));
    return v;
}


PixelProgramRef PixelProgram::fromCode(const std::string& name, const std::string& code) {
    PixelProgram* v = new PixelProgram(name, std::string(""));
    v->reload(code);
    return v;
}

}

