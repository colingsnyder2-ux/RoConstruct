// >>> native-status (generated) -- do not edit >>>
// HistoryItemCaptureProperty | 2008-06 | inactive
// unmapped (no binary link) | unmapped (no binary link) | by -
// <<< native-status | src c798e0a5 | roc native-status --write
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
