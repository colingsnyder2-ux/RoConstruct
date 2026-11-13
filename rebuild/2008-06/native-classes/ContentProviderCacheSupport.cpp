// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS /I{headers}/content-cache-inline
// >>> native-status (generated) -- do not edit >>>
// ContentProviderCacheSupport | 2008-06 | draft (no current byte proof)
// 0/2 mapped addresses byte-exact | 2 unproved | no mapped strings | by colin (mixed 2)
// <<< native-status | src 12e8b0a4 | roc native-status --write
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

// Template members emitted by this unit (bodies byte-identical to the 2008-06 client).
template class boost::date_time::base_time<boost::posix_time::ptime,boost::date_time::counted_time_system<boost::date_time::counted_time_rep<boost::posix_time::millisec_posix_time_system_config> > >;
template class boost::date_time::counted_time_system<boost::date_time::counted_time_rep<boost::posix_time::millisec_posix_time_system_config> >;
template class boost::date_time::date<boost::gregorian::date,boost::gregorian::gregorian_calendar,boost::date_time::date_duration<boost::date_time::duration_traits_adapted> >;
template class boost::date_time::gregorian_calendar_base<boost::date_time::year_month_day_base<boost::gregorian::greg_year,boost::gregorian::greg_month,boost::gregorian::greg_day>,unsigned long>;
template class boost::date_time::int_adapter<__int64>;
