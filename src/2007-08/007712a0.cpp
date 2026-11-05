// from server: 100% by Espeon
// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
// roc-lib: rbxgs roc_espeon_httpget_aug2007_fefea999152b07d8.cpp

// Candidate translation unit (score above; library headers required).
#include "v8datamodel/DataModel.h"
namespace RBX { static Reflection::BoundFuncDesc<DataModel, std::string(std::string, bool), 2> httpGetFunction(&DataModel::httpGet, "HttpGet", "url", "synchronous", false, Reflection::FunctionDescriptor::AnyCaller); }
