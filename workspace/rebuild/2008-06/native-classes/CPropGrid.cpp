// >>> native-status (generated) -- do not edit >>>
// CPropGrid | 2008-06 | draft (no current byte proof)
// 0/2 mapped addresses byte-exact | 2 unproved | no mapped strings | by king_originala (+1) (mixed 2)
// <<< native-status | src ffef17dd | roc native-status --write
#include "CPropGrid.h"
IMPLEMENT_DYNAMIC(CPropGrid, CXTPPropertyGrid)

CPropGrid::CPropGrid() : dataModel(NULL), posted(false), dirty(false)
{
    m_bHelpVisible = FALSE;
}

CPropGrid::~CPropGrid()
{
}

// Template members emitted by this unit (bodies byte-identical to the 2008-06 client).
template class RBX::Listener<RBX::Instance,RBX::PropertyChanged>;
template class std::_Container_base_aux_alloc_real<std::allocator<std::pair<RBX::Reflection::ClassDescriptor const * const,std::vector<boost::shared_ptr<RBX::Instance>,std::allocator<boost::shared_ptr<RBX::Instance> > > > > >;
template class std::_Container_base_aux_alloc_real<std::allocator<std::pair<RBX::Reflection::PropertyDescriptor const * const,CPropGrid::Item *> > >;
template class std::_Container_base_aux_alloc_real<std::allocator<std::pair<void * const,void *> > >;
template class std::_Tmap_traits<RBX::Reflection::ClassDescriptor const *,std::vector<boost::shared_ptr<RBX::Instance>,std::allocator<boost::shared_ptr<RBX::Instance> > >,std::less<RBX::Reflection::ClassDescriptor const *>,std::allocator<std::pair<RBX::Reflection::ClassDescriptor const * const,std::vector<boost::shared_ptr<RBX::Instance>,std::allocator<boost::shared_ptr<RBX::Instance> > > > >,0>;
template class std::_Tmap_traits<RBX::Reflection::PropertyDescriptor const *,CPropGrid::Item *,std::less<RBX::Reflection::PropertyDescriptor const *>,std::allocator<std::pair<RBX::Reflection::PropertyDescriptor const * const,CPropGrid::Item *> >,0>;
template class std::_Tmap_traits<void *,void *,std::less<void *>,std::allocator<std::pair<void * const,void *> >,0>;
template class std::_Tree<std::_Tmap_traits<RBX::Reflection::ClassDescriptor const *,std::vector<boost::shared_ptr<RBX::Instance>,std::allocator<boost::shared_ptr<RBX::Instance> > >,std::less<RBX::Reflection::ClassDescriptor const *>,std::allocator<std::pair<RBX::Reflection::ClassDescriptor const * const,std::vector<boost::shared_ptr<RBX::Instance>,std::allocator<boost::shared_ptr<RBX::Instance> > > > >,0> >;
template class std::_Tree<std::_Tmap_traits<RBX::Reflection::PropertyDescriptor const *,CPropGrid::Item *,std::less<RBX::Reflection::PropertyDescriptor const *>,std::allocator<std::pair<RBX::Reflection::PropertyDescriptor const * const,CPropGrid::Item *> >,0> >;
template class std::_Tree<std::_Tmap_traits<void *,void *,std::less<void *>,std::allocator<std::pair<void * const,void *> >,0> >;
template class std::_Vector_val<boost::shared_ptr<RBX::Instance>,std::allocator<boost::shared_ptr<RBX::Instance> > >;
template class std::allocator<std::_Tree_nod<std::_Tmap_traits<RBX::Reflection::ClassDescriptor const *,std::vector<boost::shared_ptr<RBX::Instance>,std::allocator<boost::shared_ptr<RBX::Instance> > >,std::less<RBX::Reflection::ClassDescriptor const *>,std::allocator<std::pair<RBX::Reflection::ClassDescriptor const * const,std::vector<boost::shared_ptr<RBX::Instance>,std::allocator<boost::shared_ptr<RBX::Instance> > > > >,0> >::_Node *>;
template class std::allocator<std::_Tree_nod<std::_Tmap_traits<RBX::Reflection::PropertyDescriptor const *,CPropGrid::Item *,std::less<RBX::Reflection::PropertyDescriptor const *>,std::allocator<std::pair<RBX::Reflection::PropertyDescriptor const * const,CPropGrid::Item *> >,0> >::_Node *>;
template class std::allocator<std::_Tree_nod<std::_Tmap_traits<void *,void *,std::less<void *>,std::allocator<std::pair<void * const,void *> >,0> >::_Node *>;
template class std::allocator<std::pair<RBX::Reflection::ClassDescriptor const * const,std::vector<boost::shared_ptr<RBX::Instance>,std::allocator<boost::shared_ptr<RBX::Instance> > > > >;
template class std::allocator<std::pair<RBX::Reflection::PropertyDescriptor const * const,CPropGrid::Item *> >;
template class std::allocator<std::pair<void * const,void *> >;
template class std::map<RBX::Reflection::ClassDescriptor const *,std::vector<boost::shared_ptr<RBX::Instance>,std::allocator<boost::shared_ptr<RBX::Instance> > >,std::less<RBX::Reflection::ClassDescriptor const *>,std::allocator<std::pair<RBX::Reflection::ClassDescriptor const * const,std::vector<boost::shared_ptr<RBX::Instance>,std::allocator<boost::shared_ptr<RBX::Instance> > > > > >;
template class std::map<RBX::Reflection::PropertyDescriptor const *,CPropGrid::Item *,std::less<RBX::Reflection::PropertyDescriptor const *>,std::allocator<std::pair<RBX::Reflection::PropertyDescriptor const * const,CPropGrid::Item *> > >;
template class std::map<void *,void *,std::less<void *>,std::allocator<std::pair<void * const,void *> > >;
