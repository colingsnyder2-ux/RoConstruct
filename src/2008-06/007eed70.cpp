// from server: 100% by king_originala
// from server: 71% by colin
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
// roc-lib: rbxgs-dll roc_unit_a405fcb86393d046.cpp

// Candidate translation unit (score above; library headers required).
#include "reflection/reflection.h"

class DHTMLWindowAbiBase
{
};

class DHTMLWindow : public RBX::Reflection::DescribedBase, public DHTMLWindowAbiBase
{
public:
    void navigate(std::string url);
};

static RBX::Reflection::BoundFuncDesc<DHTMLWindow, void(std::string), 1>
    roc_navigate(
        &DHTMLWindow::navigate,
        "Navigate",
        "url",
        std::string("about:blank"),
        RBX::Reflection::FunctionDescriptor::NeedTrustedCaller);
