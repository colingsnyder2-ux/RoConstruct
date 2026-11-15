#include "v8datamodel/ChangeHistoryService.h"
#include "v8datamodel/HistoryRecord.h"

void RBX::ChangeHistoryService::onHistoryAdded(boost::shared_ptr<Instance> instance)
{
    if (playing) return;
    if (instance.get() == this) return;
    if (dynamic_cast<Service*>(instance.get())) return;
    if (current) current->get(instance)->captureAll();
}

void RBX::ChangeHistoryService::onHistoryRemoving(boost::shared_ptr<Instance> instance)
{
    if (playing) return;
    if (instance.get() == this) return;
    if (dynamic_cast<Service*>(instance.get())) return;
    if (current) current->get(instance)->reset();
}

void RBX::ChangeHistoryService::onHistoryChanged(boost::shared_ptr<Instance> instance,
    const Reflection::PropertyDescriptor* property)
{
    if (!playing && instance.get() != this && current) current->get(instance)->update(property);
}
