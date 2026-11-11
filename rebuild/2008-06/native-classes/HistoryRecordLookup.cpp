// >>> native-status (generated) -- do not edit >>>
// HistoryRecordLookup | 2008-06 | draft (no current byte proof)
// no original address mapped to this file yet | by -
// <<< native-status | src 40e6cade | roc native-status --write
#include "v8datamodel/HistoryRecord.h"
#include "v8tree/Instance.h"

RBX::HistoryItem::HistoryItem(ChangeHistoryService* owner, boost::shared_ptr<Instance> instance)
    : service(owner), object(instance), kind(0)
{
}

RBX::HistoryItem* RBX::HistoryRecord::get(boost::shared_ptr<Instance> instance)
{
    iterator it = find(instance.get());
    if (it == end())
        it = insert(std::pair<Instance*, HistoryItem>(instance.get(), HistoryItem(service, instance))).first;
    return &it->second;
}
