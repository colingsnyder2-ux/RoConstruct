// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS
// 2008-06 ServiceProvider Lua function descriptors (statics of v8tree/Service.cpp).
//   007f33b0: push security 0 / push "name" 0081c968 / push "service" 0082f818 / push 0, push 005729c0
//             (findServiceByClassNameString, 8-byte member pointer) / mov ecx, 00974d28 / call BoundFuncDesc ctor 00572f00
//   007f33e0: the same with "GetService" 0082f820 -> object 00974ce0
// Donor tools/rbxgs Client/App/v8tree/Service.cpp line 9 declares func_GetService the same way.
#include "v8tree/Service.h"
#include "reflection/function.h"

namespace RBX
{
	Reflection::BoundFuncDesc<ServiceProvider, boost::shared_ptr<Instance>(std::string), 1> ServiceProvider::func_service(&ServiceProvider::findServiceByClassNameString, "service", "name", static_cast<Reflection::FunctionDescriptor::Security>(0));
	Reflection::BoundFuncDesc<ServiceProvider, boost::shared_ptr<Instance>(std::string), 1> ServiceProvider::func_GetService(&ServiceProvider::findServiceByClassNameString, "GetService", "name", static_cast<Reflection::FunctionDescriptor::Security>(0));
}
