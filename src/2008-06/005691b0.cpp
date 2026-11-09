// from server: 100% by colin
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
// roc-lang: cpp
// roc-lib: openrbx-client-dll App/util/standardout.cpp

// Candidate translation unit (score above; library headers required).
#include "util/standardout.h"

#include "decomp.h"
#include "util/Log.h"

#include <G3D/format.h>
#include <cstdarg>
#include <ctime>

namespace RBX {

DECOMP_SIZE_ASSERT(StandardOut, 0x28)
DECOMP_SIZE_ASSERT(StandardOutMessage, 0x28)

// FUNCTION: WEBSERVICE 0x100010d0
void StandardOut::print(MessageType type, const std::exception& exp)
{
	print(type, exp.what());
}

// FUNCTION: WEBSERVICE 0x10031e40
void StandardOut::print(MessageType type, const char* format, ...)
{
	va_list arguments;
	va_start(arguments, format);
	std::string message = G3D::vformat(format, arguments);
	va_end(arguments);

	if (Log::current()) {
		if (type == MESSAGE_ERROR) {
			Log::current()->writeEntry(Log::Error, message.c_str());
		}
		else if (type == MESSAGE_WARNING) {
			Log::current()->writeEntry(Log::Warning, message.c_str());
		}
		else if (type == MESSAGE_INFO) {
			Log::current()->writeEntry(Log::Information, message.c_str());
		}
	}

	if (hasListeners()) {
		boost::mutex::scoped_lock lock(sync);

		if (hasListeners()) {
			raise(StandardOutMessage(type, message.c_str()));
		}
	}
}

// FUNCTION: WEBSERVICE 0x100320e0
boost::shared_ptr<StandardOut> StandardOut::singleton()
{
	static boost::shared_ptr<StandardOut> standardOut(new StandardOut());

	return standardOut;
}

// FUNCTION: WEBSERVICE 0x100321b0
void StandardOut::print_exception(const boost::function0<void>& f, MessageType type, bool rethrow)
{
	try {
		f();
	}
	catch (const std::exception& error) {
		singleton()->print(type, error);

		if (rethrow) {
			throw;
		}
	}
}

} // namespace RBX
