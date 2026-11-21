// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS /I{headers}/../../../tools/rbxgs/Client/Network/raknet30/Source
// 2008-06 Network/Server.cpp reflection static: dynamic initializer 007f1c90 ("Stop", "blockDuration", default 1000,
// security 1; constructor by RTTI BoundFuncDesc<Network::Server, void(int), 1>).  Object name from the 2007 donor
// Network/Server.cpp (f_stop); the default argument and the security value are the 2008 initializer's.
#include "Network/Server2008.h"
#include "reflection/reflection.h"
namespace RBX {
	namespace Reflection {
		// BoundFuncDesc<C, F, 1> constructor with a default: reflection/reflection.h declares it without a body (same
		// definition as native-classes/AppUnit4A0ClientDescriptors.cpp and AppLeaves2008DHTMLWindow.cpp).
		template<typename Class, typename Function>
		BoundFuncDesc<Class, Function, 1>::BoundFuncDesc(
			typename BoundFuncDesc<Class, Function, 1>::FunctionSig function,
			const char* name,
			const char* arg1Name,
			typename BoundFuncDesc<Class, Function, 1>::Arg1 default1,
			Security security)
			: FuncDesc<Class>(name, security),
			  function(function),
			  default1(default1)
		{
			declareSignature(arg1Name);
		}
	}
}
static RBX::Reflection::BoundFuncDesc<RBX::Network::Server, void(int), 1> f_stop(&RBX::Network::Server::stop, "Stop", "blockDuration", 1000, RBX::Reflection::FunctionDescriptor::AnyCaller);   // 00970ef0
