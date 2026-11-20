// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS /I{headers}/../native-classes
// 0045b820: ServiceProvider::callDoGetClassIndex<RBX::ControllerService>, a 5-byte jump to 0045b2b0. The functions that pass this thunk to call_once then declare the class name "ControllerService", the name of RBX::ControllerService (thunk_lane.py, no model)
#include "ServiceProvider.cpp"
#include "v8datamodel/UserController.h"
template void RBX::ServiceProvider::callDoGetClassIndex<RBX::ControllerService>();
