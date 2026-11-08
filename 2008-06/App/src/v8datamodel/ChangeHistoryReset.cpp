// >>> native-status (generated) -- do not edit >>>
// ChangeHistoryReset | 2008-06 | inactive
// unmapped (no indexed address) | unmapped (no binary link) | by -
// <<< native-status | src b0044149 | roc native-status --write
#include "v8datamodel/ChangeHistoryService.h"
#include "v8datamodel/HistoryRecord.h"
#include <boost/checked_delete.hpp>
#include <algorithm>

typedef std::list<RBX::HistoryRecord*>::iterator HistoryIterator;
namespace std {
template<> __forceinline boost::checked_deleter<RBX::HistoryRecord> for_each(
    HistoryIterator first, HistoryIterator last, boost::checked_deleter<RBX::HistoryRecord> deleter)
{
    _Checked_iterator_base_helper<HistoryIterator>::_Checked_iterator_base_type begin(_CHECKED_BASE(first));
    _Checked_iterator_base_helper<HistoryIterator>::_Checked_iterator_base_type end(_CHECKED_BASE(last));
    for (; begin != end; ++begin) deleter(*begin);
    return deleter;
}
}

void RBX::ChangeHistoryService::reset()
{
    if (current) {
        delete current;
        current = new HistoryRecord(this);
    }
    std::for_each(history.begin(), history.end(), boost::checked_deleter<HistoryRecord>());
    history.clear();
    forward = history.end();
    backward = history.begin();
}
