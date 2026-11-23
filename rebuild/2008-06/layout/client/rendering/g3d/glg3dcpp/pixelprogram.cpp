// =============================================================================
// pixelprogram.cpp
// =============================================================================
// RoConstruct: matching-decompilation / source recovery of the 2008-06 Roblox client.
//   Project : https://github.com/colingsnyder2-ux/RoConstruct
//   Branch  : layout/2008-06 (organized layout, one file per original source path)
//   Path    : rebuild/2008-06/layout/client/rendering/g3d/glg3dcpp/pixelprogram.cpp
//
// Recovered from the shipped binary and tidied for this layout. Where this file
// is a compiled unit, its object is checked identical to the live recovery source
// (same compiler and flags). Not a source-only client, a server match or a runtime gate.
// Names or fields marked "// INFERRED:" are not in the binary and rest on stated evidence.
// Hex numbers in comments are addresses in the 2008-06 binary; more notes are in
// rebuild/2008-06/layout/evidence.json.
// =============================================================================

#line 1 ".\\glg3dcpp\\PixelProgram.cpp"
/**
  @file PixelProgram.cpp

  @maintainer Morgan McGuire, matrix@graphics3d.com

  @created 2003-04-13
  @edited  2003-09-09
*/

#include "GLG3D/PixelProgram.h"

namespace G3D
{

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
