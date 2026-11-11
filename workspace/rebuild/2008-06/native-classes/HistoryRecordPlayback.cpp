// >>> native-status (generated) -- do not edit >>>
// HistoryRecordPlayback | 2008-06 | selection unverified
// unmapped (no binary link) | by -
// <<< native-status | src 19b6e512 | roc native-status --write
#include "v8datamodel/HistoryRecord.h"
#include "v8tree/Instance.h"
#include <boost/bind.hpp>
#include <algorithm>

void RBX::HistoryRecord::play()
{
    for (iterator it = begin(); it != end(); ++it) it->second.play();
}

void RBX::HistoryRecord::unplay()
{
    for (iterator it = begin(); it != end(); ++it) {
        HistoryItem& item = it->second;
        switch (item.kind) {
        case 1: item.object->setParent(NULL); break;
        case 2:
            std::for_each(item.properties.begin(), item.properties.end(),
                boost::bind(&HistoryItem::unplayProperty, &item, _1));
            break;
        case 3: item.unplay(); break;
        }
    }
}
