// 2008-06 native RBX::StandardOut (inactive): the donor util/standardout.h declaration (see
// native-headers/leaves2008/StandardOut2008.h). Original bodies: Notifier<StandardOut, StandardOutMessage>::raise
// (event, listener) 00569780, print(type, format, ...) 005693a0, StandardOut() 00569530, ~StandardOut 00569590,
// singleton 00569620 (with shared_ptr / shared_count constructors 005692f0 / 00569260), ??_G 005696d0,
// print_exception 005696f0 and print(type, exception) 00416e10. Verified by tests/record_native_leaves2008.py.
//
// NATIVE_STANDARDOUT_PENDING (generated donor util/standardout.h copy under out/, see the recorder): the 2008
// StandardOut has no user-declared destructor (00569590 stores no StandardOut vtable). print 005693a0 needs
// Notifier::hasListeners as `size() > 0` (`sar eax, 2; test eax, eax; jbe`), now in native-headers/util/Events.h.
// >>> native-status (generated) -- do not edit >>>
// Leaves2008StandardOut | 2008-06 | draft (no current byte proof)
// 0/3 mapped addresses byte-exact | 3 unproved | no mapped strings | by auto (+1) (gpt-6)
// <<< native-status | src a6ac1fe2 | roc native-status --write
#include "leaves2008/StandardOut2008.h"
#include "leaves2008/Log2008.h"
#include <G3D/format.h>

namespace RBX
{
	void StandardOut::print(MessageType type, const char* format, ...)
	{
		va_list argsList;
		va_start(argsList, format);
		std::string message = G3D::vformat(format, argsList);
		va_end(argsList);

		if (Log::current())
		{
			if (type == MESSAGE_ERROR)
				Log::current()->writeEntry(Log::Error, message.c_str());
			else if (type == MESSAGE_WARNING)
				Log::current()->writeEntry(Log::Warning, message.c_str());
			else if (type == MESSAGE_INFO)
				Log::current()->writeEntry(Log::Information, message.c_str());
		}

		if (Notifier<StandardOut, StandardOutMessage>::hasListeners())
		{
			boost::mutex::scoped_lock lock(sync);
			if (Notifier<StandardOut, StandardOutMessage>::hasListeners())
				Notifier<StandardOut, StandardOutMessage>::raise(StandardOutMessage(type, message.c_str()));
		}
	}

	void StandardOut::print(MessageType type, const std::exception& exp)
	{
		print(type, exp.what());
	}

	void StandardOut::print_exception(const boost::function0<void>& f, MessageType type, bool rethrow)
	{
		try
		{
			f();
		}
		catch (std::exception& ex)
		{
			singleton()->print(type, ex);

			if (rethrow)
				throw;
		}
	}

	boost::shared_ptr<StandardOut> StandardOut::singleton()
	{
		static boost::shared_ptr<StandardOut> standardOut(new StandardOut());
		return standardOut;
	}

	StandardOut::StandardOut()
	{
	}

#ifndef NATIVE_STANDARDOUT_PENDING
	// Only for the current donor declaration (user-declared virtual ~StandardOut); the 2008 destructor is implicit.
	StandardOut::~StandardOut()
	{
	}
#endif
}

// Template members emitted by this unit (bodies byte-identical to the 2008-06 client).
template class boost::enable_shared_from_this<RBX::StandardOut>;
template class std::_Container_base_aux_alloc_real<std::allocator<RBX::Listener<RBX::StandardOut,RBX::StandardOutMessage> *> >;
