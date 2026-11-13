#include "util/Http.h"

// PORT: omit donor modern-compiler prelude for 2008 MSVC.
#include "util/ContentProvider.h"
#include "util/StandardOut.h"

#include <G3D/format.h>
#include <atlbase.h>
#include <atlstr.h>
#include <atlutil.h>
#include <boost/iostreams/categories.hpp>
#include <boost/iostreams/copy.hpp>
#include <boost/iostreams/filter/gzip.hpp>
#include <boost/iostreams/filtering_stream.hpp>
#include <boost/noncopyable.hpp>
#include <boost/scoped_ptr.hpp>
#include <boost/thread/mutex.hpp>
#include <sstream>
#include <stdexcept>
#include <wininet.h>

namespace RBX {

// PORT: selective unit; remaining functions use the 2008 object.

bool Http::isRobloxSite(const char* url)
{
	CUrl crack;
	crack.CrackUrl(url);

	switch (crack.GetScheme()) {
	case ATL_URL_SCHEME_FTP:
	case ATL_URL_SCHEME_HTTP:
	case ATL_URL_SCHEME_HTTPS: {
		CString hostName = crack.GetHostName();
		hostName.MakeLower();
		if (hostName.Right(10) == "roblox.com") {
			return true;
		}
		return false;
	}

	default:
		return false;
	}
}

} // namespace RBX
