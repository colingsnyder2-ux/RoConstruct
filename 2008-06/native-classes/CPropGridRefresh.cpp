// >>> native-status (generated) -- do not edit >>>
// CPropGridRefresh | 2008-06 | draft (no current byte proof)
// no original address mapped to this file yet | by -
// <<< native-status | src 77a79e22 | roc native-status --write
#include "CPropGrid.h"
#include "v8datamodel/DataModel.h"
#include <algorithm>
#include <functional>

LRESULT CPropGrid::OnUpdate(WPARAM, LPARAM)
{
    if (items.size() == 0) {
        CXTPPropertyGridUpdateContext context;
        BeginUpdate(context);
        rebuild(&RBX::Reflection::ClassDescriptor::rootDescriptor());
        EndUpdate(context);
    }
    std::vector<Item*> all;
    std::set<Item*> pending;
    {
        boost::recursive_mutex::scoped_lock lock(mutex);
        if (dirty) {
            all = items;
            dirty = false;
        } else {
            pending = pendingItems;
            pendingItems.clear();
        }
        posted = false;
    }
    {
        RBX::DataModel::Lock lock(dataModel);
        std::for_each(all.begin(), all.end(), std::bind2nd(std::mem_fun(&Item::update), &groups));
        std::for_each(pending.begin(), pending.end(), std::bind2nd(std::mem_fun(&Item::update), &groups));
    }
    for (int i = 0; i < GetCategories()->GetCount(); ++i) {
        CXTPPropertyGridItem* category = GetCategories()->GetAt(i);
        CXTPPropertyGridItems* children = category->GetChilds();
        bool hidden = true;
        for (int j = 0; j < children->GetCount(); ++j) {
            if (!children->GetAt(j)->IsHidden()) {
                hidden = false;
                break;
            }
        }
        category->SetHidden(hidden);
    }
    RedrawControl();
    return 0;
}

// Template members emitted by this unit (bodies byte-identical to the 2008-06 client).
template class CArray<CXTPPropertyGridItem *,CXTPPropertyGridItem *>;
template class CMap<unsigned int,unsigned int,int,int &>;
template class std::_Container_base_aux_alloc_real<std::allocator<CPropGrid::Item *> >;
template class std::_Tree<std::_Tset_traits<CPropGrid::Item *,std::less<CPropGrid::Item *>,std::allocator<CPropGrid::Item *>,0> >;
template class std::_Vector_const_iterator<CPropGrid::Item *,std::allocator<CPropGrid::Item *> >;
template class std::_Vector_iterator<CPropGrid::Item *,std::allocator<CPropGrid::Item *> >;
template class std::allocator<std::_Tree_nod<std::_Tset_traits<CPropGrid::Item *,std::less<CPropGrid::Item *>,std::allocator<CPropGrid::Item *>,0> >::_Node *>;
template class std::vector<CPropGrid::Item *,std::allocator<CPropGrid::Item *> >;
