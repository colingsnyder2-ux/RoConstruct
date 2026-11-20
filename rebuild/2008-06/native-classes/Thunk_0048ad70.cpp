// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS /I{headers}/../native-classes
// 0048ad70: ServiceProvider::callDoGetClassIndex<RBX::SpawnerService>, a 5-byte jump to 0048a4c0. The functions that pass this thunk to call_once then declare the class name "SpawnerService", the name of RBX::SpawnerService (thunk_lane.py, no model)
#include "ServiceProvider.cpp"
#include "v8datamodel/SpawnerService.h"
template void RBX::ServiceProvider::callDoGetClassIndex<RBX::SpawnerService>();
