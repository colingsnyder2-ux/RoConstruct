// from server: 100% by colin
// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
// roc-lib: rbxgs v8datamodel/roc_unit_35038cc06402fe11.cpp

// Candidate translation unit (score above; library headers required).
#include "v8datamodel/DebrisService.h"
#include "v8datamodel/TimerService.h"
#include "util/standardout.h"
static RBX::Reflection::BoundFuncDesc<RBX::DebrisService, void(boost::shared_ptr<RBX::Instance>, double), 2> func_AddItem(&RBX::DebrisService::addItem, "AddItem", "item", "lifetime", 10.0, (RBX::Reflection::FunctionDescriptor::Security)0);
