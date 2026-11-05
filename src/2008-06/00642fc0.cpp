// from server: 100% by colin
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
// roc-lang: cpp
// roc-lib: rbxgs roc_unit_6cd9126405bfe274.cpp

// Candidate translation unit (score above; library headers required).
#undef _RELEASEASSERT
#pragma include_alias("util/IRenderable.h", "roc_unit_b8671ae8d3010f90.cpp")
#pragma include_alias("v8tree/Instance.h", "roc_unit_b34763c2f3d3f398.cpp")
#pragma include_alias("v8datamodel/MouseCommand.h", "roc_unit_9958a7131e20354c.cpp")
#include "v8datamodel/ScriptMouseCommand.h"
#include "v8datamodel/Mouse.h"
namespace RBX {
ScriptMouseCommand::~ScriptMouseCommand() { mouse->setCommand(NULL); mouse->disconnect_all_slots(); }
TextureId ScriptMouseCommand::getCursorId() const { return mouse->getIcon(); }
}
