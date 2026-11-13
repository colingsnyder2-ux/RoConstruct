// Isolated ABI trial. Requires the 2008 property descriptor candidate header;
// do not include in the live client until descriptor construction and slots agree.
// >>> native-status (generated) -- do not edit >>>
// HistoryItemPropertyTrial | 2008-06 | draft (no current byte proof)
// no original address mapped to this file yet | by -
// <<< native-status | src eec8f748 | roc native-status --write
#include "v8datamodel/HistoryRecord.h"
#include "v8datamodel/ChangeHistoryService.h"
#include "v8tree/Instance.h"

void RBX::HistoryItem::captureProperty(const Reflection::PropertyDescriptor* property)
{
    if (property->isReadOnly()) return;
    if (property->isWriteOnly()) return;
    Reflection::Value value;
    property->getVariant(object.get(), value);
    const Reflection::PropertyDescriptor* key = property;
    properties[key] = value;
}

void RBX::HistoryItem::applyProperty(
    const std::pair<const Reflection::PropertyDescriptor* const, Reflection::Value>& property)
{
    property.first->setVariant(object.get(), property.second);
}

static __forceinline RBX::HistoryItem* findHistoryItem(RBX::HistoryRecord* record, RBX::Instance* instance)
{
    RBX::HistoryRecord::iterator it = record->find(instance);
    return it != record->end() ? &it->second : NULL;
}

void RBX::HistoryItem::unplayProperty(
    const std::pair<const Reflection::PropertyDescriptor* const, Reflection::Value>& property)
{
    bool isParent = property.first == &Instance::propParent;
    std::list<HistoryRecord*>::iterator it = service->backward;
    while (it != service->history.begin()) {
        --it;
        HistoryItem* item = findHistoryItem(*it, object.get());
        if (item) {
            std::map<const Reflection::PropertyDescriptor*, Reflection::Value>::iterator found = item->properties.find(property.first);
            if (found != item->properties.end()) {
                std::pair<const Reflection::PropertyDescriptor* const, Reflection::Value> value = *found;
                value.first->setVariant(item->object.get(), value.second);
                return;
            }
            if (isParent && item->kind == 1) {
                object->setParent(item->parent.get());
                return;
            }
        }
    }
}
