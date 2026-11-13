// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS
// 2008-06 native rows of the Message / Hint creation instances inside the application range 004a0000..004a4000
// (inactive). Verified by tests/record_native_app_unit4a0.py. All headers are read-only here.
//
// The Network::Server unit (Server.cpp, 004a1570..) creates Messages and Hints, so the compiler-emitted Creatable
// instances of both classes lie in it, in link order (same shape as the chat / clipboard runs of
// native-classes/AppUnit40C_2008Creators.cpp):
//   * boost::detail::shared_count(Message*, Creatable<Instance>::Deleter) 004a3710 and the Hint one 004a3a00 (counted
//     by creatable-shared-count);
//   * boost::shared_ptr<Message>(Message*, Creatable<Instance>::Deleter) 004a37a0 and shared_ptr<Hint> 004a3b80 (the
//     enable_shared_from_this hook-up);
//   * Creatable<Instance>::create<Message>() 004a3850 (malloc 0x15c, Message() 005dd120, shared_ptr<Message>);
//   * FactoryProduct<Message, Instance, sMessage>::Creator::create() const 004a38d0 (slot 0 of the Creator vtable).
// sizeof(Message) / sizeof(Hint) come from the read-only native v8datamodel/Message.h (effects owner) and are checked
// against the malloc size by the recorder.
#include "v8datamodel/Message.h"
#include "util/Object.h"

namespace RBX
{
	// util/Object.h declares Creator::create() only; this is the definition every Creator vtable slot 0 reaches
	// (same definition as native-classes/AppUnit40C_2008Creators.cpp).
	template<typename Class, typename DerivedClass, const char* ClassName>
	boost::shared_ptr<Object> FactoryProduct<Class, DerivedClass, ClassName>::Creator::create() const
	{
		return Creatable<Instance>::create<Class>();
	}
}

template boost::shared_ptr<RBX::Message> RBX::Creatable<RBX::Instance>::create<RBX::Message>();
template boost::shared_ptr<RBX::Hint> RBX::Creatable<RBX::Instance>::create<RBX::Hint>();
template boost::shared_ptr<RBX::Object> RBX::FactoryProduct<RBX::Message, RBX::Instance, RBX::sMessage>::Creator::create() const;
