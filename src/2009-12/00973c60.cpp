// from server: 100% by colin
// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
// roc-lib: rbxgs v8datamodel/roc_unit_99621a3c05a20ec7.cpp

// Candidate translation unit (score above; library headers required).
#include "v8datamodel/Workspace.h"
#include "v8datamodel/PartInstance.h"
#include "v8datamodel/MouseCommand.h"
#include "v8datamodel/Flag.h"
#include "v8datamodel/Camera.h"
#include "v8datamodel/Hopper.h"
#include "v8datamodel/Selection.h"
#include "script/ScriptContext.h"
#include "humanoid/Humanoid.h"
#include "v8world/World.h"
#include "tool/NullTool.h"
#include "tool/ToolsArrow.h"
#include "Network/Players.h"
namespace RBX { static Reflection::BoundFuncDesc<Workspace, void(boost::shared_ptr<const std::vector<boost::shared_ptr<Instance>>>), 1> workspace_breakJoints(&Workspace::breakJoints, "BreakJoints", "objects", (RBX::Reflection::FunctionDescriptor::Security)1); }
