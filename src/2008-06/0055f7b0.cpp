// from server: 100% by colin
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
// roc-lib: rbxgs-dll roc_unit_20d2ec6a12aa22f7.cpp

// Candidate translation unit (score above; library headers required).
#pragma include_alias("v8tree/Instance.h", "roc_unit_b34763c2f3d3f398.cpp")
#pragma include_alias("util/ContentProvider.h", "roc_unit_d492c70b3d6feceb.cpp")
#include "G3D/platform.h"
#include "util/ContentProvider.h"
namespace RBX {
	bool ContentProvider::isUrlBad(const char* url)
	{
		boost::mutex::scoped_lock lock(requestSync);

		std::list<FailedUrl>::iterator end = failedUrls.end();
		std::list<FailedUrl>::iterator iter = failedUrls.begin();

		for (; iter != end; iter++)
		{
			if (boost::posix_time::second_clock::local_time() >= iter->expiration)
			{
				failedUrls.erase(iter, end);
				return false;
			}
			else if (iter->url == url)
			{
				return true;
			}
		}

		return false;
	}

}
