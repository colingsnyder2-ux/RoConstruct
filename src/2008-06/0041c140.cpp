// from server: 100% by Espeon
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: rbxgs-dll roc_espeon_functionrefdescriptor623715f68971b019.cpp

// Candidate translation unit (score above; library headers required).
#include "script/ThreadRef.h"
#pragma include_alias("util/IRenderable.h", "roc_unit_b8671ae8d3010f90.cpp")
#include "v8datamodel/DataModel.h"
#include "reflection/function.h"

class DHTMLWindowAbiBase
{
};

class DHTMLWindow : public RBX::Reflection::DescribedBase, public DHTMLWindowAbiBase
{
public:
    void navigate(RBX::Lua::FunctionRef url);
};

static RBX::Reflection::BoundFuncDesc<DHTMLWindow, void(RBX::Lua::FunctionRef), 1> roc_navigateFunction(&DHTMLWindow::navigate, "Navigate", "url", RBX::Reflection::FunctionDescriptor::NeedTrustedCaller);
