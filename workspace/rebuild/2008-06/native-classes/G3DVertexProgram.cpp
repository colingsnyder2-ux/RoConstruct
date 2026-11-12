// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /fp:fast
// 2008-06 native G3DVertexProgram (inactive): upstream tools/libs/g3d-6.09/source/GLG3Dcpp/VertexProgram.cpp, verbatim.
// >>> native-status (generated) -- do not edit >>>
// G3DVertexProgram | 2008-06 | draft (no current byte proof)
// no original address mapped to this file yet | by -
// <<< native-status | src f1b73698 | roc native-status --write
#line 1 ".\\glg3dcpp\\VertexProgram.cpp"
/**
  @file VertexProgram.cpp

  @maintainer Morgan McGuire, matrix@graphics3d.com

  @created 2003-04-10
  @edited  2003-09-09
*/

#include "GLG3D/VertexProgram.h"

namespace G3D {

VertexProgram::VertexProgram(const std::string& name, const std::string& filename) : 
    GPUProgram(name, filename) {
}

VertexProgramRef VertexProgram::fromFile(const std::string& _filename) {
    VertexProgram* v = new VertexProgram(_filename, _filename);
    v->reload(std::string(""));
    return v;
}


VertexProgramRef VertexProgram::fromCode(const std::string& name, const std::string& code) {
    VertexProgram* v = new VertexProgram(name, std::string(""));
    v->reload(code);
    return v;
}

}

