// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS /I{headers}/../../../tools/rbxgs/Client/Network/raknet30/Source
// 2008-06 native RBX::Network::AbuseReporter constructor (inactive; original unit Network/Players.cpp). Flags copied
// from NetworkPlayers.cpp / NetworkPlayersAbuseReporter.cpp (same original unit). Layout: native-headers/Network/Players.h.
#include "Network/Players.h"
#include <boost/bind.hpp>

namespace RBX
{
	namespace Network
	{
		// 0049e040 (Players.h declaration; called from setAbuseReportUrl 0049e1d0): new data (0x28), shared_ptr<data>
		// 0049d1a0, boost::bind(&processRequests 0049bf90, _data, abuseUrl) 00498d40, function0 0049c440,
		// new worker_thread (0x14) 005971d0 with "rbx_abusereporter" 00822b5c. Shape: openrbx Network/Players.cpp.
		AbuseReporter::AbuseReporter(std::string abuseUrl)
			: _data(new data())
		{
			requestProcessor.reset(
				new worker_thread(boost::bind(&AbuseReporter::processRequests, _data, abuseUrl), "rbx_abusereporter"));
		}
	}
}
