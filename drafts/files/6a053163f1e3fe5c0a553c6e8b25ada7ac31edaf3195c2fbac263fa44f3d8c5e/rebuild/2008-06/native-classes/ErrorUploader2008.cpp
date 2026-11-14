// native-flags: /O2 /Ob2 /Oi /Ot /Oy /GF /GS- /EHsc /MD /D_AFXDLL /D_DLL /I{headers}/mfc-noinline-pcxstr /I{headers}/std-noinline-string
// ErrorUploader (2008 ctor 0044d610, dtor 0044a830; header rebuild/2008-06/native-headers/CRobloxApp.h).
// Body ported from the Dec 2007 client decomp (OpenRBX Client/win/ErrorUploader.{h,cpp}, ROBLOX 0x004520c0 /
// 0x0041e020), same 0x1c object layout (shared state + worker_thread). The 2008 state is 72 bytes vs 0x3c in
// 2007; the private fields below are the 2007 ones (behavioural, not byte-verified).
// >>> native-status (generated) -- do not edit >>>
// ErrorUploader2008 | 2008-06 | draft (no current byte proof)
// 0/1 mapped addresses byte-exact | 1 unproved | no mapped strings | by Espeon (deepseek:deepseek-chat)
// <<< native-status | src 6998bbb7 | roc native-status --write
#include "ErrorUploaderState.h"
#include "util/Http.h"
#include "util/standardout.h"
#include <boost/bind.hpp>
#include <boost/thread/recursive_mutex.hpp>
#include <fstream>
#include <queue>
#include <sstream>

ErrorUploader::ErrorUploader()
    : state(new data()), thread(boost::bind(&ErrorUploader::upload, state), "rbx_erroruploader")
{
}

ErrorUploader::~ErrorUploader()
{
}

