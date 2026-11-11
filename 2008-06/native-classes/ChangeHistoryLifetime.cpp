#include "v8datamodel/ChangeHistoryService.h"
#include "v8datamodel/HistoryRecord.h"

RBX::ChangeHistoryService::ChangeHistoryService()
    : DescribedCreatable<ChangeHistoryService, Instance, sChangeHistoryService>("ChangeHistoryService"),
      current(NULL), playing(false), enabled(false)
{
}

RBX::ChangeHistoryService::~ChangeHistoryService()
{
    delete current;
}

// Template members emitted by this unit (bodies byte-identical to the 2008-06 client).
template class std::_Container_base_aux_alloc_real<std::allocator<RBX::HistoryRecord *> >;
template class std::_Container_base_aux_alloc_real<std::allocator<std::pair<RBX::Instance * const,RBX::HistoryItem> > >;
template class std::_Container_base_aux_alloc_real<std::allocator<std::pair<RBX::Reflection::PropertyDescriptor const * const,RBX::Reflection::Value> > >;
template class std::_Tmap_traits<RBX::Instance *,RBX::HistoryItem,std::less<RBX::Instance *>,std::allocator<std::pair<RBX::Instance * const,RBX::HistoryItem> >,0>;
template class std::_Tmap_traits<RBX::Reflection::PropertyDescriptor const *,RBX::Reflection::Value,std::less<RBX::Reflection::PropertyDescriptor const *>,std::allocator<std::pair<RBX::Reflection::PropertyDescriptor const * const,RBX::Reflection::Value> >,0>;
template class std::_Tree<std::_Tmap_traits<RBX::Instance *,RBX::HistoryItem,std::less<RBX::Instance *>,std::allocator<std::pair<RBX::Instance * const,RBX::HistoryItem> >,0> >;
template class std::_Tree<std::_Tmap_traits<RBX::Reflection::PropertyDescriptor const *,RBX::Reflection::Value,std::less<RBX::Reflection::PropertyDescriptor const *>,std::allocator<std::pair<RBX::Reflection::PropertyDescriptor const * const,RBX::Reflection::Value> >,0> >;
template class std::allocator<RBX::HistoryRecord *>;
template class std::allocator<std::_List_nod<RBX::HistoryRecord *,std::allocator<RBX::HistoryRecord *> >::_Node *>;
template class std::allocator<std::_List_nod<RBX::HistoryRecord *,std::allocator<RBX::HistoryRecord *> >::_Node>;
template class std::allocator<std::_Tree_nod<std::_Tmap_traits<RBX::Instance *,RBX::HistoryItem,std::less<RBX::Instance *>,std::allocator<std::pair<RBX::Instance * const,RBX::HistoryItem> >,0> >::_Node *>;
template class std::allocator<std::_Tree_nod<std::_Tmap_traits<RBX::Reflection::PropertyDescriptor const *,RBX::Reflection::Value,std::less<RBX::Reflection::PropertyDescriptor const *>,std::allocator<std::pair<RBX::Reflection::PropertyDescriptor const * const,RBX::Reflection::Value> >,0> >::_Node *>;
template class std::list<RBX::HistoryRecord *,std::allocator<RBX::HistoryRecord *> >;
template class std::map<RBX::Instance *,RBX::HistoryItem,std::less<RBX::Instance *>,std::allocator<std::pair<RBX::Instance * const,RBX::HistoryItem> > >;
template class std::map<RBX::Reflection::PropertyDescriptor const *,RBX::Reflection::Value,std::less<RBX::Reflection::PropertyDescriptor const *>,std::allocator<std::pair<RBX::Reflection::PropertyDescriptor const * const,RBX::Reflection::Value> > >;
