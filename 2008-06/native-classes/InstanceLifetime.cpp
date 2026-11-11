// Inactive candidate: lifetime bodies match; dependent ABI and linkage remain open.
#include "v8tree/Instance.h"
#include <windows.h>
namespace RBX {
extern long instanceCount;
Instance::Instance() : parent(0), name("Instance"), archivable(true)
{
    InterlockedIncrement(&instanceCount);
}
Instance::Instance(const char* value) : parent(0), name(value), archivable(true)
{
    InterlockedIncrement(&instanceCount);
}
Instance::~Instance()
{
    InterlockedDecrement(&instanceCount);
}
}

#ifndef NATIVE_INSTANCE_EXTERNAL_CREATE_CHILD
boost::shared_ptr<RBX::Instance> RBX::Instance::createChild(const Name& className)
{
    return AbstractFactoryProduct::create(className);
}
#endif

// Template members emitted by this unit (bodies byte-identical to the 2008-06 client).
template class boost::scoped_ptr<std::map<RBX::Reflection::SignalDescriptor const *,boost::shared_ptr<RBX::Reflection::SignalInstance>,std::less<RBX::Reflection::SignalDescriptor const *>,std::allocator<std::pair<RBX::Reflection::SignalDescriptor const * const,boost::shared_ptr<RBX::Reflection::SignalInstance> > > > >;
template class std::_Container_base_aux_alloc_real<std::allocator<RBX::Association<RBX::Instance>::Item *> >;
template class std::_Container_base_aux_alloc_real<std::allocator<RBX::Listener<RBX::Instance,RBX::AncestorChanged> *> >;
template class std::_Container_base_aux_alloc_real<std::allocator<RBX::Listener<RBX::Instance,RBX::ChildAdded> *> >;
template class std::_Container_base_aux_alloc_real<std::allocator<RBX::Listener<RBX::Instance,RBX::ChildRemoved> *> >;
template class std::_Container_base_aux_alloc_real<std::allocator<RBX::Listener<RBX::Instance,RBX::DescendantAdded> *> >;
template class std::_Container_base_aux_alloc_real<std::allocator<RBX::Listener<RBX::Instance,RBX::DescendantRemoving> *> >;
template class std::_Container_base_aux_alloc_real<std::allocator<RBX::Listener<RBX::Instance,RBX::PropertyChanged> *> >;
template class std::_Container_base_aux_alloc_real<std::allocator<std::pair<RBX::Reflection::SignalDescriptor const * const,boost::shared_ptr<RBX::Reflection::SignalInstance> > > >;
template class std::_Tmap_traits<RBX::Reflection::SignalDescriptor const *,boost::shared_ptr<RBX::Reflection::SignalInstance>,std::less<RBX::Reflection::SignalDescriptor const *>,std::allocator<std::pair<RBX::Reflection::SignalDescriptor const * const,boost::shared_ptr<RBX::Reflection::SignalInstance> > >,0>;
template class std::_Tree<std::_Tmap_traits<RBX::Reflection::SignalDescriptor const *,boost::shared_ptr<RBX::Reflection::SignalInstance>,std::less<RBX::Reflection::SignalDescriptor const *>,std::allocator<std::pair<RBX::Reflection::SignalDescriptor const * const,boost::shared_ptr<RBX::Reflection::SignalInstance> > >,0> >;
template class std::allocator<std::_Tree_nod<std::_Tmap_traits<RBX::Reflection::SignalDescriptor const *,boost::shared_ptr<RBX::Reflection::SignalInstance>,std::less<RBX::Reflection::SignalDescriptor const *>,std::allocator<std::pair<RBX::Reflection::SignalDescriptor const * const,boost::shared_ptr<RBX::Reflection::SignalInstance> > >,0> >::_Node *>;
template class std::map<RBX::Reflection::SignalDescriptor const *,boost::shared_ptr<RBX::Reflection::SignalInstance>,std::less<RBX::Reflection::SignalDescriptor const *>,std::allocator<std::pair<RBX::Reflection::SignalDescriptor const * const,boost::shared_ptr<RBX::Reflection::SignalInstance> > > >;
