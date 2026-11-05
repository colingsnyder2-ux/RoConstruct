// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
// roc-lib: rbxgs-dll roc_espclaude_17f11b1fc4d80591.cpp

// Candidate translation unit (score above; library headers required).
#include "v8tree/Instance.h"
#include "v8tree/Service.h"
#include "util/Http.h"
#include "util/standardout.h"
#include <G3D/format.h>
#include <boost/thread.hpp>

namespace RBX
{
	class Visit
	{
	private:
		char instanceLayoutPad[0x130];
		std::string uploadUrl;
		boost::scoped_ptr<worker_thread> pingThread;

	public:
		void setPing(std::string url, int interval);
		static worker_thread::work_result ping(std::string url, int interval);
	};

	void Visit::setPing(std::string url, int interval)
	{
		if (url != "")
		{
			pingThread.reset(new worker_thread(boost::bind(&Visit::ping, url, interval), "rbx_visit"));
		}
		else
		{
			pingThread.reset();
		}
	}
}
