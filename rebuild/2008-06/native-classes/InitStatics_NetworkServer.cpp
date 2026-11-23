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

#ifdef SERVER_HEADER_DECLARES_START
		// BoundFuncDesc<C, F, 2> constructor with both defaults (reflection/reflection.h declares it without a body):
		// 004a4530 for "Start" (FunctionDescriptor 00595790, vtable 008239d8, function +0x38, Value<int> defaults +0x40
		// / +0x48, then declareSignature 00416eb0).
		template<typename Class, typename Function>
		BoundFuncDesc<Class, Function, 2>::BoundFuncDesc(
			typename BoundFuncDesc<Class, Function, 2>::FunctionSig function,
			const char* name,
			const char* arg1Name,
			typename BoundFuncDesc<Class, Function, 2>::Arg1 default1,
			const char* arg2Name,
			typename BoundFuncDesc<Class, Function, 2>::Arg2 default2,
			Security security)
			: FuncDesc<Class>(name, security),
			  function(function),
			  default1(default1),
			  default2(default2)
		{
			declareSignature(arg1Name, arg2Name);
		}
#endif
	}
}
#ifdef SERVER_HEADER_DECLARES_START
// 00970f98 (dynamic initializer 007f1c50: "Start", "port" default 0, "threadSleepTime" default 20, security 1;
// Server::start 004a1d80; atexit 007fbcc0). BLOCKED: Network/Server2008.h does not declare Server::start.
static RBX::Reflection::BoundFuncDesc<RBX::Network::Server, void(int, int), 2> f_start(&RBX::Network::Server::start, "Start", "port", 0, "threadSleepTime", 20, RBX::Reflection::FunctionDescriptor::AnyCaller);
#endif
static RBX::Reflection::BoundFuncDesc<RBX::Network::Server, void(int), 1> f_stop(&RBX::Network::Server::stop, "Stop", "blockDuration", 1000, RBX::Reflection::FunctionDescriptor::AnyCaller);   // 00970ef0

// 00970ebc Server::event_IncommingConnection (donor Server.cpp): dynamic initializer 007f1d20 ("IncommingConnection"
// 00823c14, "peer" 00823258, "replicator" 00823260) calls SignalDesc<Server, void(std::string, shared_ptr<Instance>)>
// constructor 004a4400 (RTTI vtable 008239c8); atexit 007fbcd0.
RBX::Reflection::SignalDesc<RBX::Network::Server, void(std::string, boost::shared_ptr<RBX::Instance>)> RBX::Network::Server::event_IncommingConnection("IncommingConnection", "peer", "replicator");
