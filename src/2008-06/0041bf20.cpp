// from server: 100% by colin
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
// roc-lib: rbxgs-dll roc_unit_140891dd264d8537.cpp

// Candidate translation unit (score above; library headers required).
#pragma include_alias("util/IRenderable.h", "roc_unit_b8671ae8d3010f90.cpp")
#include "v8datamodel/DataModel.h"
#include "reflection/function.h"

class DHTMLWindowAbiBase
{
};

class DHTMLWindow : public RBX::Reflection::DescribedBase, public DHTMLWindowAbiBase
{
public:
    void navigate(std::string url);
};

static RBX::Reflection::BoundFuncDesc<DHTMLWindow, void(std::string), 1> roc_navigateFunction(&DHTMLWindow::navigate, "Navigate", "url", RBX::Reflection::FunctionDescriptor::NeedTrustedCaller);
