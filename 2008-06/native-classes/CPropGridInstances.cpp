// >>> native-status (generated) -- do not edit >>>
// CPropGridInstances | 2008-06 | inactive
// unmapped (no binary link) | unmapped (no binary link) | by -
// <<< native-status | src 0e444415 | roc native-status --write
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
