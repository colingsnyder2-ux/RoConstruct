// 2008-06 native rows of the event and bound-function descriptor instances of the Network::Client unit
// (Network/Client.cpp, 0049ed30..004a156f) inside the application range 004a0000..004a4000 (inactive). Verified by
// tests/record_native_app_unit4a0.py. All headers are read-only here (Client: native-headers/Network/Client2008.h,
// network-client-server owner; descriptors: reflection/signal.h and reflection/reflection.h, core owner).
//
// Original descriptor classes (RTTI of the vtables the constructors store):
//   * SignalDesc<Client, void(std::string, shared_ptr<Instance>)> vtable 008230b0, constructor 004a0020 (static
//     initializer 007f1bd0; three names, ret 0xc);
//   * SignalDesc<Client, void(std::string)> vtable 008230d0, constructor 004a02e0 (007f1c00; two names, ret 8);
//   * BoundFuncDesc<Client, void(std::string, int, int, int), 4> vtable 008230e0, constructor 004a03b0 (007f1b60;
//     defaults for the third and fourth arguments, ret 0x28) with declareSignature 0049ee50 and execute 004a04b0;
//   * BoundFuncDesc<Client, void(int), 1> vtable 008230ec, constructor 004a06b0 (007f1ba0; with a default for the
//     argument, ret 0x18) and execute 004a0780;
//   * the deleting destructor 004a0690 both BoundFuncDesc vtables share (identical-code folded).
// The member functions they bind are not needed here: only the descriptor templates are instantiated.
#include "Network/Client2008.h"
#include <boost/shared_ptr.hpp>
#include <string>
#include <typeinfo>

namespace RBX
{
	namespace Reflection
	{
		// BoundFuncDesc<C, F, 1> constructor with a default reflection/reflection.h declares without a body (same
		// definition as native-classes/AppLeaves2008DHTMLWindow.cpp): 004a06b0 stores Value(int) for the default.
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

		// BoundFuncDesc<C, F, 4> members reflection/reflection.h declares without a body.
		template<typename Class, typename Function>
		BoundFuncDesc<Class, Function, 4>::BoundFuncDesc(
			typename BoundFuncDesc<Class, Function, 4>::FunctionSig function,
			const char* name,
			const char* arg1Name,
			const char* arg2Name,
			const char* arg3Name,
			typename BoundFuncDesc<Class, Function, 4>::Arg3 default3,
			const char* arg4Name,
			typename BoundFuncDesc<Class, Function, 4>::Arg4 default4,
			Security security)
			: FuncDesc<Class>(name, security),
			  function(function),
			  default1(),
			  default2(),
			  default3(default3),
			  default4(default4)
		{
			declareSignature(arg1Name, arg2Name, arg3Name, arg4Name);
		}

		template<typename Class, typename Function>
		void BoundFuncDesc<Class, Function, 4>::declareSignature(const char* arg1Name, const char* arg2Name,
			const char* arg3Name, const char* arg4Name)
		{
			signature.resultType = &Type::singleton<typename result_type>();
			signature.addArgument(Name::declare(arg1Name, -1), Type::singleton<typename Arg1>(), default1);
			signature.addArgument(Name::declare(arg2Name, -1), Type::singleton<typename Arg2>(), default2);
			signature.addArgument(Name::declare(arg3Name, -1), Type::singleton<typename Arg3>(), default3);
			signature.addArgument(Name::declare(arg4Name, -1), Type::singleton<typename Arg4>(), default4);
		}

		// 004a04b0: the four arguments are copied from the defaults, overridden from the call arguments, converted
		// right to left and passed straight to the bound member (no separate call<void> member in the original).
		template<typename Class, typename Function>
		void BoundFuncDesc<Class, Function, 4>::execute(DescribedBase* instance, Arguments& arguments) const
		{
			Value arg1 = default1;
			arguments.get(1, arg1);
			Value arg2 = default2;
			arguments.get(2, arg2);
			Value arg3 = default3;
			arguments.get(3, arg3);
			Value arg4 = default4;
			arguments.get(4, arg4);

			Class* o = dynamic_cast<Class*>(instance);
			if (!o)
				throw std::bad_cast();

			(o->*function)(arg1.convert<typename Arg1>(), arg2.convert<typename Arg2>(), arg3.convert<typename Arg3>(),
				arg4.convert<typename Arg4>());
		}
	}
}

typedef RBX::Network::Client NetworkClient;

template RBX::Reflection::SignalDesc<NetworkClient, void(std::string, boost::shared_ptr<RBX::Instance>)>::SignalDesc(
	const char*, const char*, const char*);
template RBX::Reflection::SignalDesc<NetworkClient, void(std::string)>::SignalDesc(const char*, const char*);
template RBX::Reflection::BoundFuncDesc<NetworkClient, void(std::string, int, int, int), 4>::BoundFuncDesc(
	void (NetworkClient::*)(std::string, int, int, int), const char*, const char*, const char*, const char*, int,
	const char*, int, RBX::Reflection::FunctionDescriptor::Security);
template void RBX::Reflection::BoundFuncDesc<NetworkClient, void(std::string, int, int, int), 4>::execute(
	RBX::Reflection::DescribedBase*, RBX::Reflection::FunctionDescriptor::Arguments&) const;
template RBX::Reflection::BoundFuncDesc<NetworkClient, void(int), 1>::BoundFuncDesc(void (NetworkClient::*)(int),
	const char*, const char*, int, RBX::Reflection::FunctionDescriptor::Security);
template void RBX::Reflection::BoundFuncDesc<NetworkClient, void(int), 1>::execute(RBX::Reflection::DescribedBase*,
	RBX::Reflection::FunctionDescriptor::Arguments&) const;
