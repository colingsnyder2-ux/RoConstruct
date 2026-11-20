// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS /I{headers}/../native-classes
// 0042d180: ServiceProvider::callDoGetClassIndex<RBX::ScriptContext>, a 5-byte jump to 0042d030. The functions that pass this thunk to call_once then declare the class name "ScriptContext", the name of RBX::ScriptContext (thunk_lane.py, no model)
#include "ServiceProvider.cpp"
#include "script/ScriptContext.h"
template void RBX::ServiceProvider::callDoGetClassIndex<RBX::ScriptContext>();
