// >>> native-status (generated) -- do not edit >>>
// CPropGridRefresh | 2008-06 | inactive
// unmapped (no binary link) | by -
// <<< native-status | src aee678aa | roc native-status --write
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
