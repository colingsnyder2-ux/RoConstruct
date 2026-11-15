// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /fp:fast
// 2008-06 native G3DPixelProgram (inactive): upstream tools/libs/g3d-6.09/source/GLG3Dcpp/PixelProgram.cpp, verbatim.
#line 1 ".\\glg3dcpp\\PixelProgram.cpp"
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

