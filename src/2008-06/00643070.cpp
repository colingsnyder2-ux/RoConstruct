// from server: 100% by colin
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
// roc-lang: cpp
// roc-lib: rbxgs-dll roc_unit_89a79706adcece50.cpp

// Candidate translation unit (score above; library headers required).
#undef _RELEASEASSERT
#pragma include_alias("util/IRenderable.h", "roc_unit_b8671ae8d3010f90.cpp")
#pragma include_alias("v8tree/Instance.h", "roc_unit_b34763c2f3d3f398.cpp")
#include "v8datamodel/ScriptMouseCommand.h"
#include "v8datamodel/Mouse.h"
namespace RBX {
TextureId ScriptMouseCommand::getCursorId() const {
 return (*reinterpret_cast<const boost::shared_ptr<Mouse>*>(reinterpret_cast<const char*>(this)+0x1c))->getIcon();
}
}
