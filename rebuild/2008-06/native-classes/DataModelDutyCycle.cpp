// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /fp:fast /D_AFXDLL /DNDEBUG /D_MBCS
// >>> native-status (generated) -- do not edit >>>
// DataModelDutyCycle | 2008-06 | draft (no current byte proof)
// 0/1 mapped addresses byte-exact | 1 unproved | no mapped strings | by colin (chatgpt:gpt-6.1-sol)
// <<< native-status | src f952e7cd | roc native-status --write
#include "v8datamodel/DataModel.h"
#include "util/RunStateOwner.h"

double RBX::DataModel::getDutyCycle() const { return runService->dutyCycle(); }
