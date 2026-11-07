// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS /I{headers}/content-cache-inline
// >>> native-status (generated) -- do not edit >>>
// ContentProviderCacheSupport | 2008-06 | inactive
// unmapped (no binary link) | by -
// <<< native-status | src 654d5abd | roc native-status --write
#include "util/NativeContentProvider.h"

namespace RBX {
ContentProvider::FailedUrl::FailedUrl(const char* value)
    : url(value), expiration(boost::posix_time::second_clock::local_time() + boost::posix_time::minutes(5))
{
}

bool ContentProvider::isUrlBad(const char* url)
{
    boost::mutex::scoped_lock lock(requestSync);
    std::list<FailedUrl>::iterator end = failedUrls.end();
    std::list<FailedUrl>::iterator iter = failedUrls.begin();
    for (; iter != end; iter++) {
        if (boost::posix_time::second_clock::local_time() >= iter->expiration) {
            failedUrls.erase(iter, end);
            return false;
        } else if (iter->url == url) {
            return true;
        }
    }
    return false;
}
}
