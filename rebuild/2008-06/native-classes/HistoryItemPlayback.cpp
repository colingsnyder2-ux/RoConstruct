#include "v8datamodel/HistoryRecord.h"
#include "v8datamodel/ChangeHistoryService.h"
#include "v8tree/Instance.h"
#include <boost/bind.hpp>
#include <algorithm>
#include <deque>

static __forceinline RBX::HistoryItem* lookup(RBX::HistoryRecord* record, RBX::Instance* object)
{
    RBX::HistoryRecord::iterator it = record->find(object);
    if (it == record->end()) return NULL;
    return &it->second;
}

void RBX::HistoryItem::play()
{
    switch (kind) {
    case 1:
        std::for_each(properties.begin(), properties.end(), boost::bind(&HistoryItem::applyProperty, this, _1));
        object->setParent(parent.get());
        break;
    case 2:
        std::for_each(properties.begin(), properties.end(), boost::bind(&HistoryItem::applyProperty, this, _1));
        break;
    case 3:
        object->setParent(NULL);
        break;
    }
}

void RBX::HistoryItem::unplay()
{
    std::deque<HistoryItem*> pending;
    std::list<HistoryRecord*>::iterator it = service->backward;
    while (it != service->history.begin()) {
        --it;
        HistoryItem* item = lookup(*it, object.get());
        if (item) {
            if (item->kind == 1) {
                item->play();
                break;
            }
            pending.push_back(item);
        }
    }
    while (!pending.empty()) {
        pending.back()->play();
        pending.pop_back();
    }
}
