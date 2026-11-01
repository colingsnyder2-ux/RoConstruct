// from server: 100% by colin
// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
// roc-lib: rbxgs v8datamodel/roc_unit_7e66b2e2914ede10.cpp

// Candidate translation unit (score above; library headers required).
#include "v8datamodel/Lighting.h"
#include "v8datamodel/DataModel.h"
#include "v8datamodel/TimeState.h"
#include "v8datamodel/Workspace.h"
#include "v8datamodel/Hopper.h"
#include "v8datamodel/Teams.h"
#include "v8datamodel/JointsService.h"
#include "v8datamodel/LocalBackpack.h"
#include "v8datamodel/GuiBuilder.h"
#include "script/ScriptContext.h"
#include "gui/GUI.h"
#include "util/Log.h"
#include "util/IMetric.h"
#include "util/standardout.h"
#include "util/Http.h"
#include "util/Sound.h"
#pragma warning (push)
#pragma warning (disable : 4355) // warning C4355: 'this' : used in base member initializer list
#pragma warning (pop)
namespace RBX { static Reflection::BoundFuncDesc<DataModel, std::string(std::string, bool), 2> httpGetFunction(&DataModel::httpGet, "HttpGet", "url", "synchronous", false, (RBX::Reflection::FunctionDescriptor::Security)4); }
