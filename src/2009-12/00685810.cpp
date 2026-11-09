// from server: 100% by colin
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
// roc-lib: rbxgs-dll roc_unit_f2f51c401b99ae45.cpp

// Candidate translation unit (score above; library headers required).
#pragma include_alias("util/IRenderable.h", "roc_unit_b8671ae8d3010f90.cpp")
#include "v8datamodel/DataModel.h"
#include "reflection/function.h"

namespace RBX {

class ChangeHistoryServiceAbi
{
};

class ChangeHistoryService : public Reflection::DescribedBase, public ChangeHistoryServiceAbi
{
public:
    void setRecording(std::string message);
};

static Reflection::BoundFuncDesc<ChangeHistoryService, void(std::string), 1> roc_recordingFunction(&ChangeHistoryService::setRecording, "SetRecording", "message", Reflection::FunctionDescriptor::NeedTrustedCaller);

}
