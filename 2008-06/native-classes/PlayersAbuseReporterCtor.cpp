// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS /I{headers}/boost-function-pod-vtable /I{headers}/../../../tools/rbxgs/Client/Network/raknet30/Source
// 2008-06 native RBX::Network::AbuseReporter constructor (inactive; original unit Network/Players.cpp). Flags copied
// from NetworkPlayers.cpp / NetworkPlayersAbuseReporter.cpp (same original unit). Layout: native-headers/Network/Players.h.
// /I{headers}/boost-function-pod-vtable (b46 hn03): the Boost 1.35 function_template.hpp inlines assign_to into the
// function0<work_result>(bind_t) constructor 0049c440 (has_empty_target 0060a2f0, new(0x28) functor, stored vtable
// 008229e0), which is then 162 B IDENTICAL with relocations masked (without it: 111 B calling a 190 B assign_to). It stays
// uncredited: registry placeholders func_0049c440 (no candidate) and func_00497740 (the bind_t destructor it calls).
// Exact set unchanged (49 -> 49 rows).
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
