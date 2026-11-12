// from server: 92% by EspClaude
// from server: 56% by TrollStein
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS /EHsc /MD
// roc-lib: boost-1.34.1 roc_claude_d39cd183505b0953.cpp

// Candidate translation unit (score above; library headers required).
// vtable 0x7932e8 RTTI: boost::detail::sp_counted_impl_pd<RBX::ControllerService*,
// RBX::Creatable<RBX::Instance>::Deleter>; new(0x14) = vtable, use, weak, ptr, empty deleter.
// Creatable/Deleter copied from rbxgs include/util/Object.h.
// The library compile environment lacks _CPPUNWIND although /EHsc is on; the client's
// shared_count ctor has the try/catch(...) form (target saves esp at [ebp-0x10]).
#include <boost/config.hpp>
#undef BOOST_NO_EXCEPTIONS
#include <boost/shared_ptr.hpp>

namespace RBX
{
	class Instance
	{
	};

	class ControllerService : public Instance
	{
	};

	template<typename T>
	class Creatable
	{
	public:
		class Deleter
		{
		public:
			void operator()(T*);
		};
	};
}

template boost::detail::shared_count::shared_count(RBX::ControllerService*, RBX::Creatable<RBX::Instance>::Deleter);
