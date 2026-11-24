// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS /I{headers}/../../../tools/rbxgs/Client/Network/raknet30/Source
// 2008-06 native RBX::Network::Client (inactive); evidence in native-headers/Network/Client2008.h.
// Verified by tests/record_native_network_client_server2008.py. Original bodies: constructor 004a0990,
// DescribedCreatable<Client> 0049ff10, FactoryProduct<Client> 0049eef0 / ~FactoryProduct 0049edb0, destructor
// 0049f2e0 (deleting 0049f4e0), classDescriptor 0049eb30 (atexit 007fba60).
#include "Network/Client2008.h"

namespace RBX
{
	// Template members the shared headers only declare (same definitions as TimerService.cpp / ClickDetector.cpp).
	template<class C, class D, const char* N>
	FactoryProduct<C, D, N>::FactoryProduct() : D() {}

	template<class C, class D, const char* N>
	const Name& FactoryProduct<C, D, N>::className() { return Name::declare<N>(); }

	template<class C, class D, const char* N>
	const Name& FactoryProduct<C, D, N>::getClassName() const { return className(); }

	template<class C, class D, const char* N>
	DescribedCreatable<C, D, N>::DescribedCreatable()
		: Reflection::Described<C, N, FactoryProduct<C, D, N> >() {}

	namespace Reflection
	{
		// 0049fa40: SignalDescImpl<3, void(std::string, int, std::string)>::GenericSlotAdapter::operator() of
		// event_ConnectionFailed (00970bb4). The binary's RTTI names SignalDescImpl<3, ...>::GenericSlotAdapter
		// (004a0900); its boost::function invoker 0049fd90 (function vtable 00822fa8) calls this body. Same shape as the
		// arity-1 adapter in reflection/signal.h: Arguments(3) (0041b170), any::operator= per argument (string 00417230,
		// int holder vtable 008106cc), then wrapper->execute (GenericSlotWrapper slot 1). The core header declares the
		// operator only; the definition lives here like the FactoryProduct members above.
		template<int ArgCount, typename CallbackSignature>
		void SignalDescImpl<ArgCount, CallbackSignature>::GenericSlotAdapter::operator()(
			typename boost::function_traits<CallbackSignature>::arg1_type arg1,
			typename boost::function_traits<CallbackSignature>::arg2_type arg2,
			typename boost::function_traits<CallbackSignature>::arg3_type arg3)
		{
			std::vector<boost::any> args(3);
			args[0] = arg1;
			args[1] = arg2;
			args[2] = arg3;

			wrapper->execute(args);
		}

		template void SignalDescImpl<3, void(std::string, int, std::string)>::GenericSlotAdapter::operator()(
			std::string, int, std::string);
	}
}

// 0049fd90: the boost::function<void(std::string, int, std::string)> invoker of that adapter (function vtable
// 00822fa8 slot 1): copies both strings and calls 0049fa40 on the stored functor.
template struct boost::detail::function::void_function_obj_invoker3<
	RBX::Reflection::SignalDescImpl<3, void(std::string, int, std::string)>::GenericSlotAdapter,
	void, std::string, int, std::string>;

namespace RBX
{

	namespace Network
	{
		char sClient[] = "NetworkClient"; // 00938c88 (classDescriptor 0049eb30, constructor setName)

		Client::Client()
		{
			setName(sClient);
		}

		bool Client::clientIsPresent(const Instance* context, bool testInDatamodel)
		{
			return ServiceProvider::find<Client>(ServiceProvider::findServiceProvider(context)) != NULL;
		}

		Client::~Client()
		{
			rakPeer->CloseConnection(serverId, true, 0);
		}

		void Client::disconnect(int blockDuration)
		{
			removeAllChildren();
			rakPeer->CloseConnection(serverId, true, 0);
			rakPeer->Shutdown(blockDuration, 0);
		}

#ifdef NATIVE_NETWORK_CLIENT_PENDING
		// 0049f130 (Listener<ServiceProvider, Closing> slot 0, entered through the +0x144 subobject). Needs a complete
		// RBX::Closing (only forward-declared in the native v8tree/Service.h): header-owner proposal, verified by the
		// recorder against a generated Service.h copy under rebuild/2008-06/out/ (not counted).
		void Client::onEvent(const ServiceProvider* source, Closing event)
		{
			disconnect(3000);
		}
#endif
	}
}
// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS /I{headers}/../../../tools/rbxgs/Client/Network/raknet30/Source
