// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS /I{headers}/boost-function-pod-vtable
#include "ErrorUploaderState.h"
#include <boost/bind.hpp>

ErrorUploader::ErrorUploader()
    : state(new data), thread(boost::bind(&ErrorUploader::upload, state), "rbx_erroruploader")
{
}
