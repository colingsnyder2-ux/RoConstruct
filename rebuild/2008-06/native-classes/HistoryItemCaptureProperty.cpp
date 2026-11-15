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
