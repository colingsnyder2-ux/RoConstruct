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

// Template members emitted by this unit (bodies byte-identical to the 2008-06 client).
template class std::_Vector_const_iterator<RBX::Listener<RBX::Instance,RBX::PropertyChanged> *,std::allocator<RBX::Listener<RBX::Instance,RBX::PropertyChanged> *> >;
template class std::_Vector_iterator<RBX::Listener<RBX::Instance,RBX::PropertyChanged> *,std::allocator<RBX::Listener<RBX::Instance,RBX::PropertyChanged> *> >;
template class std::vector<RBX::Listener<RBX::Instance,RBX::PropertyChanged> *,std::allocator<RBX::Listener<RBX::Instance,RBX::PropertyChanged> *> >;
