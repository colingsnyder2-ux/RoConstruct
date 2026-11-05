// from server: 100% by colin
// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
// roc-lib: rbxgs v8datamodel/roc_unit_d2c06cd8a3e2a3f6.cpp

// Candidate translation unit (score above; library headers required).
#include "v8datamodel/PartInstance.h"
#include "v8datamodel/ModelInstance.h"
#include "v8datamodel/Workspace.h"
#include "v8world/Assembly.h"
#include "v8world/Controller.h"
#include "v8world/World.h"
#include "AppDraw/Draw.h"
#include "AppDraw/DrawAdorn.h"
#include "AppDraw/HitTest.h"
#include "tool/Dragger.h"
#include <G3D/CoordinateFrame.h>
#include "reflection/type.h"
#include "reflection/property.h"
#include "v8xml/XmlElement.h"
#pragma warning (push)
#pragma warning (disable : 4355) // warning C4355: 'this' : used in base member initializer list
#pragma warning (pop)
namespace RBX { static Reflection::BoundFuncDesc<PartInstance, void(void), 0> desc_unjoin(&PartInstance::destroyJoints, "BreakJoints", (RBX::Reflection::FunctionDescriptor::Security)0); }
