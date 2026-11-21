// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS /I{headers}
// 2008-06 DataModel "HttpGet" function descriptor of the v8datamodel/DataModel.cpp object (inactive).
//
// 007f3530 ??__EhttpGetFunction@RBX@@YAXXZ (49 B): dynamic initializer of the static descriptor object 00974e68.
//   push 4 (security) / push 0 (default2 = false) / push "synchronous" 00830470 / push "url" 0080f08c /
//   push "HttpGet" 00830468 / push 0, push 0057bc00 (8-byte member pointer: DataModel has multiple bases) /
//   mov ecx, 00974e68 / call 00579360 (BoundFuncDesc<DataModel, std::string(std::string, bool), 2> ctor with
//   default2, 177 B, ret 0x1c) / atexit(007fd4e0 ??__FhttpGetFunction@RBX@@YAXXZ).
// Donor tools/rbxgs/Client/App/v8datamodel/DataModel.cpp line 23 declares the same static (httpGetFunction,
// &DataModel::httpGet, "HttpGet", "url", "synchronous"); the 2008-06 binary also passes default2 = false and
// security 4 (the Visit/Players units cast the same value), so it uses the default2 constructor.
// 0057bc00 is DataModel::httpGet(std::string url, bool synchronous) (donor DataModel.cpp line 137: it tests
// synchronous first, then copies url for doHttpGet 00575060).
//
// BLOCKED: the core native v8datamodel/DataModel.h does not declare DataModel::httpGet (proposal:
//   std::string httpGet(std::string url, bool synchronous);   // 0057bc00
// ). Measured against a scratch DataModel.h with only that line added: 007f3530 and 007fd4e0 are exact, and the
// reference 007f3530 -> 00579360 establishes the DataModel identity of the 00579360 BoundFuncDesc constructor.
// Define RBX_NATIVE_DATAMODEL_HTTPGET (or drop the guard) once the core header declares it.
#ifdef RBX_NATIVE_DATAMODEL_HTTPGET
#include "reflection/reflection.h"
#include "v8datamodel/DataModel.h"
#include <string>

namespace RBX
{
	// 007f3530 (initializer) / 007fd4e0 (atexit destructor): object 00974e68
	static Reflection::BoundFuncDesc<DataModel, std::string(std::string, bool), 2> httpGetFunction(&DataModel::httpGet, "HttpGet", "url", "synchronous", false, static_cast<Reflection::FunctionDescriptor::Security>(4));
}
#endif
