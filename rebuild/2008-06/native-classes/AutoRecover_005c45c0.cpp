// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS
#include "v8datamodel/Visit.h"
#include "util/Http.h"
#include <boost/thread.hpp>

namespace RBX
{
	namespace
	{
		// INFERRED: the original inlines Http's constructor and destructor; the destructor is out of line in
		// the header, so this file-local mirror of the Http layout (two std::string members at offsets 0 and
		// 0x1c, no vtable) is used instead, and Http::get is called through a cast.
		struct PingHttp
		{
			std::string url;
			std::string extra;

			PingHttp(const std::string& u) : url(u), extra() {}
		};
	}

	worker_thread::work_result Visit::ping(std::string url, int interval)
	{
		try
		{
			std::string message;
			PingHttp h(url);
			reinterpret_cast<Http*>(&h)->get(message);
		}
		catch (...)
		{
			// INFERRED: the 2008 handler is an empty catch(...) that resumes at 005c464b (no failure message)
		}

		boost::xtime xt;
		boost::xtime_get(&xt, boost::TIME_UTC);

		xt.sec += interval;

		boost::thread::sleep(xt);

		return worker_thread::more;
	}
}
