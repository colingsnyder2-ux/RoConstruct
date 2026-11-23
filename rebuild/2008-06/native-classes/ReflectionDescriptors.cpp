// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /I{headers}/boost-function-pod-vtable-memptr
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
#include <boost/bind.hpp>

namespace RBX
{
	namespace boost_detail
	{
		extern boost::thread_specific_ptr<std::string>* foo;   // 00975c90 (ThreadNameStorage.cpp)
		extern boost::once_flag once_init_foo;                 // 00975c94
		void init_foo();                                       // 00596d50
	}

	void SetThreadName(DWORD dwThreadID, LPCSTR szThreadName); // 00595a80 (same unit, out of line)

	// INFERRED: the 2008 background_function 00597110 takes a thread priority (it binds run_in_background 00596ea0 with
	// std::string(name) and the int; worker_thread passes -1), absent from the donor util/boost.hpp declaration.
	// AppUnit54C_2008RunService.cpp declares the same overload.
	boost::function0<void> background_function(const boost::function0<void>& threadfunc, const char* name, int priority);

	// 00596ea0 (ThreadPrioritySetter.cpp): INFERRED 2008 signature with the thread priority after the by-value name.
	void run_in_background(const boost::function0<void>& threadfunc, std::string name, int priority);

	// 005971d0 ??0worker_thread@RBX@@QAE@ABV?$function0@W4work_result@worker_thread@RBX@@V?$allocator@Vfunction_base@boost@@@std@@@boost@@PBD@Z
	// new data (0x24, data() 00595a30), shared_ptr init (00596110, sp_enable_shared_from_this 0047d410),
	// bind(&threadProc 00595e40, _data, work_function) 005965d0 -> function0<void> 00596f90,
	// background_function(.., name, -1) 00597110, boost::thread(const function0<void>&) 005a6a80 at +8.
	worker_thread::worker_thread(const boost::function0<enum work_result>& work_function, const char* name)
		: _data(new data()),
		  thread(background_function(boost::bind(&threadProc, _data, work_function), name, -1))
	{
	}

	// 00595cb0 ??1worker_thread@RBX@@QAE@XZ: lock 00594ce0, endRequest (+0x20) = true, notify_all 005f1d30,
	// unlock 00594d00, ~thread 005a6840 (+8), _data release.
	worker_thread::~worker_thread()
	{
		boost::mutex::scoped_lock scoped_lock(_data->sync);
		_data->endRequest = true;
		_data->wakeCondition.notify_all();
	}

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

	// 00595e40 (static threadProc; the bind target of the worker_thread constructor, pushed at 005972a2): the donor
	// rbxgs util/boost.cpp loop. Near miss (343 B against 335 B, batch 43): the candidate rotates the loop and repeats the
	// endRequest test after the wait, the target tests only at the top (jmp 00595e66); the openrbx while (true) / if
	// (endRequest) return form and a `continue` form compile to the same 343 B. endRequest (+0x20) ends it; work_function() (bad_function_call when empty) returning
	// anything but `more` waits on wakeCondition (+8) under sync (+0): do_lock 00594ce0, condition enter_wait 005f1dd0,
	// do_unlock(state) 00594d40, do_wait 005f1df0, do_lock(state) 00594d20, do_unlock 00594d00.
	void worker_thread::threadProc(boost::shared_ptr<data> data, const boost::function0<enum work_result>& work_function)
	{
		while (!data->endRequest)
		{
			if (work_function() != more)
			{
				boost::mutex::scoped_lock scoped_lock(data->sync);
				data->wakeCondition.wait(scoped_lock);
			}
		}
	}

	// 00597110: boost::bind(&run_in_background 00596ea0, threadfunc, std::string(name), priority) (bind 005968d0) into
	// the returned function0<void> (00597080), whose functor_manager<bind_t<..., list3<function0<void>, std::string,
	// int> > >::manager is 00596cd0 (RTTI type descriptor 00949af8).
	boost::function0<void> background_function(const boost::function0<void>& threadfunc, const char* name, int priority)
	{
		return boost::bind(&run_in_background, threadfunc, std::string(name), priority);
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
