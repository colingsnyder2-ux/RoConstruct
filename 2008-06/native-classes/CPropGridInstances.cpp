#include "CPropGrid.h"
#include "v8tree/Instance.h"

void CPropGrid::removeInstance(boost::shared_ptr<RBX::Instance> instance)
{
    RBX::Notifier<RBX::Instance, RBX::PropertyChanged>::disconnect(instance, this);
    groups.remove(instance.get());
}

void CPropGrid::addInstance(boost::shared_ptr<RBX::Instance> instance)
{
    groups.add(instance.get());
    RBX::Notifier<RBX::Instance, RBX::PropertyChanged>::connect(instance, this);
}
