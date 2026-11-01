// from server: 100% by colin
// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
// roc-lib: rbxgs v8datamodel/roc_unit_f9f663a5f02ecf2c.cpp

// Candidate translation unit (score above; library headers required).
#include "v8datamodel/ModelInstance.h"
#include "v8datamodel/PartInstance.h"
#include "humanoid/Humanoid.h"
#include "v8world/Primitive.h"
#include "tool/DragUtilities.h"
#include "AppDraw/Draw.h"
#pragma warning (push)
#pragma warning (disable : 4355) // warning C4355: 'this' : used in base member initializer list
#pragma warning (pop)
namespace RBX { static Reflection::BoundFuncDesc<ModelInstance, void(), 0> desc_makeJoints(&ModelInstance::makeJoints, "MakeJoints", (RBX::Reflection::FunctionDescriptor::Security)0); }
