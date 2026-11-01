// from server: 100% by colin
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
// roc-lib: rbxgs-dll roc_unit_1d5ef495fc48e309.cpp

// Candidate translation unit (score above; library headers required).
#pragma include_alias("util/IRenderable.h", "roc_unit_b8671ae8d3010f90.cpp")
#include "v8datamodel/DataModel.h"
#include "reflection/function.h"

namespace RBX { namespace Network {

class PlayersListener
{
};

class Players : public Reflection::DescribedBase, public PlayersListener
{
public:
    void chat(std::string message);
};

static Reflection::BoundFuncDesc<Players, void(std::string), 1> roc_chatFunction(&Players::chat, "Chat", "message", Reflection::FunctionDescriptor::NeedTrustedCaller);

}}
