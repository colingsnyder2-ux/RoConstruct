// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS /I{headers}/boost-function-pod-vtable
// >>> native-status (generated) -- do not edit >>>
// ErrorUploaderConstructor | 2008-06 | inactive
// unmapped (no indexed address) | unmapped (no binary link) | by -
// <<< native-status | src bb18c74c | roc native-status --write
#include "ErrorUploaderState.h"
#include <boost/bind.hpp>

ErrorUploader::ErrorUploader()
    : state(new data), thread(boost::bind(&ErrorUploader::upload, state), "rbx_erroruploader")
{
}
