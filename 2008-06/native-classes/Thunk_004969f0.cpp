// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS /I{headers}/../native-classes
// 004969f0: ServiceProvider::callDoGetClassIndex<RBX::Teams>, a 5-byte jump to 004962f0. The functions that pass this thunk to call_once then declare the class name "Teams", the name of RBX::Teams (thunk_lane.py, no model)
#include "ServiceProvider.cpp"
#include "v8datamodel/Teams.h"
template void RBX::ServiceProvider::callDoGetClassIndex<RBX::Teams>();
