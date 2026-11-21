// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS /I{headers}/datamodel-2008 /I{headers}/std-noinline-string
#include "LoginRenewer.h"
#include <boost/bind.hpp>
#include <boost/thread/xtime.hpp>
#include <string>
#include <stdlib.h>
#include <G3D/format.h>
#include "util/Http.h" // datamodel-2008 copy: implicit ~Http (url / additionalHeaders destroyed inline, see 00427480)
#include "util/standardout.h"
// Original functions 00427310 and 00427480; symbol identities provisional.
std::string loginRenewalUrl();
RBX::worker_thread::work_result renewLogin(std::string);
LoginRenewer::LoginRenewer()
    : RBX::worker_thread(boost::bind(renewLogin, loginRenewalUrl()), "LoginRenewer") {}

// 00427480 ?renewLogin@@YA?AW4work_result@worker_thread@RBX@@V?$basic_string@...@std@@@Z (registry; bound by
// LoginRenewer() 004277d0 through boost::bind 00577110). Callees: Http::get 00569ae0 (Http(url) built inline: url copy,
// empty additionalHeaders), atoi import, G3D::format 00509b10 ("renewLogin %s failed: %s" 008102cc, e.what() vtable +4),
// StandardOut::singleton 00569620 / print 005693a0 (MESSAGE_WARNING = 2), boost::xtime_get 005a6b40 (TIME_UTC = 1),
// boost::thread::sleep 005a6870. The delay is minutes (x 60), at least 1 and at most 30; the default before the
// request is 5. Returns worker_thread::more (1).
RBX::worker_thread::work_result renewLogin(std::string url)
{
	int minutes = 5;
	try
	{
		std::string response;
		RBX::Http(url).get(response);
		minutes = atoi(response.c_str());
	}
	catch (std::exception& e)
	{
		std::string message = G3D::format("renewLogin %s failed: %s", url.c_str(), e.what());
		RBX::StandardOut::singleton()->print(RBX::MESSAGE_WARNING, message.c_str());
	}

	if (minutes <= 0)
		minutes = 1;
	else
		minutes = std::min(minutes, 30);

	boost::xtime xt;
	boost::xtime_get(&xt, boost::TIME_UTC);
	xt.sec += minutes * 60;
	boost::thread::sleep(xt);

	return RBX::worker_thread::more;
}
