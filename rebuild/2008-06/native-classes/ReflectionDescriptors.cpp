// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
// 2008-06 native reflection descriptor leaves (inactive).
// Already defined inline in read-only headers, not repeated here:
//   EnumDescriptor::equalValue 00448300, EnumDescriptor::isValue 00448450 (reflection/enumconverter.h)
//   Name::empty 00496350 (util/Name.h)
#include "reflection/property.h"
#include "reflection/type.h"

namespace RBX
{
	namespace Reflection
	{
		// 0056be00 ?read@PropertyDescriptor@Reflection@RBX@@UBEXPAVDescribedBase@23@PBVXmlElement@@AAVIReferenceBinder@3@@Z
		// mov eax,[ecx]; jmp [eax+0x2c]: forwards to the private readValue slot.
		void PropertyDescriptor::read(DescribedBase* instance, const XmlElement* element, IReferenceBinder& binder) const
		{
			readValue(instance, element, binder);
		}

		// 00594b40 ?addArgument@SignatureDescriptor@Reflection@RBX@@QAEXABVName@3@ABVType@23@ABVValue@23@@Z
		// Builds an Item on the stack (Value copy clones the boost::any content through slot 2), list push_back
		// (_Buynode 00417f00, _Incsize 00682cc0), then destroys the temporary Item.
		void SignatureDescriptor::addArgument(const Name& name, const Type& type, const Value& defaultValue)
		{
			Item item = {&name, &type, defaultValue};
			arguments.push_back(item);
		}
	}
}

// PARKED: RBX::Guid::getLocalScope 005a82e0 (?getLocalScope@Guid@RBX@@SAABVName@2@XZ).
// Target: push flag 00976b6c; push initLocalScope 005a8260; call boost::call_once 00557330; mov eax,[localScope 00976b64].
// The util/Guid.h this unit resolves to does not declare getLocalScope, so no body can be defined here without a
// header change (proposal: add 'static const Name& getLocalScope();' to RBX::Guid). The registry names the flag as
// the constructor's local static (?flag@?1???0Guid@RBX@@QAE@XZ@4JA), so the body belongs in Guid.cpp beside
// initLocalScope/localScope:
//   const Name& Guid::getLocalScope()
//   {
//       static boost::once_flag flag = BOOST_ONCE_INIT;
//       boost::call_once(initLocalScope, flag);
//       return *localScope;
//   }

// ---------------------------------------------------------------------------------------------------------------
// RBX::worker_thread rows (00595d70 join, 00595de0 wake, 00596db0 set_thread_name). Their original unit is
// util/boost.cpp (worker_thread unit 00595a30..00597350: data() 00595a30, SetThreadName 00595a80, ~worker_thread
// 00595cb0, init_foo 00596d50, worker_thread(function0) 005971d0; record_native_app_unit594_2008.py unit map), which
// has no native file of its own; the assignment places them here. Layout from the targets: _data px +0 (data: mutex
// +0, condition +8 (notify_all 005f1d30), endRequest +0x20), boost::thread +8 (join 005a6850) - the donor
// util/boost.hpp declaration.
#include <windows.h>
#include <boost/thread/once.hpp>
#include <boost/thread/tss.hpp>
#include "util/boost.hpp"

namespace RBX
{
	namespace boost_detail
	{
		extern boost::thread_specific_ptr<std::string>* foo;   // 00975c90 (ThreadNameStorage.cpp)
		extern boost::once_flag once_init_foo;                 // 00975c94
		void init_foo();                                       // 00596d50
	}

	void SetThreadName(DWORD dwThreadID, LPCSTR szThreadName); // 00595a80 (same unit, out of line)

	// 00595d70 ?join@worker_thread@RBX@@QAEXXZ
	void worker_thread::join()
	{
		{
			boost::mutex::scoped_lock scoped_lock(_data->sync);
			_data->endRequest = true;
			_data->wakeCondition.notify_all();
		}

		thread.join();
	}

	// 00595de0 ?wake@worker_thread@RBX@@QAEXXZ
	void worker_thread::wake()
	{
		boost::mutex::scoped_lock scoped_lock(_data->sync);
		_data->wakeCondition.notify_all();
	}

	// 00596db0 ?set_thread_name@RBX@@YAXPBD@Z: new std::string(name) (0x1c), call_once(init_foo), foo->reset
	// (tss get 005a7570 / set 005a76b0 / cleanup 005a6ff0), then SetThreadName(GetCurrentThreadId(), name).
	void set_thread_name(const char* name)
	{
		std::string* value = new std::string(name);
		boost::call_once(&boost_detail::init_foo, boost_detail::once_init_foo);
		boost_detail::foo->reset(value);
		SetThreadName(GetCurrentThreadId(), name);
	}
}
