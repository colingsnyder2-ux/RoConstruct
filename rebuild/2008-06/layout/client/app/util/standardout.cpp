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
	StandardOut::~StandardOut()
	{
	}
#endif
}

template class boost::enable_shared_from_this<RBX::StandardOut>;
template class std::_Container_base_aux_alloc_real<std::allocator<RBX::Listener<RBX::StandardOut,RBX::StandardOutMessage> *> >;
