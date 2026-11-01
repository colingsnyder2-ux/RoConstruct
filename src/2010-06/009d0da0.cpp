// from server: 100% by colin
// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
// roc-lib: rbxgs v8datamodel/roc_unit_1620d28c8e4ce7dd.cpp

// Candidate translation unit (score above; library headers required).
#include "v8datamodel/Visit.h"
#include "util/Http.h"
#include "util/standardout.h"
#include <G3D/format.h>
#include <boost/thread.hpp>
static RBX::Reflection::BoundFuncDesc<RBX::Visit, void(std::string, int), 2> desc_setPing(&RBX::Visit::setPing, "SetPing", "pingUrl", "interval", (RBX::Reflection::FunctionDescriptor::Security)4);
