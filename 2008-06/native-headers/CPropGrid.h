#pragma once
#include <XTToolkitPro.h>
#include "util/Events.h"
#include <boost/thread/recursive_mutex.hpp>
#include <map>
#include <set>
#include "SelectionGroup.h"

namespace RBX { class DataModel; class Instance; class PropertyChanged;
namespace Reflection { class PropertyDescriptor; } }

// Inactive typed storage recovery. Pointer-container payload identities,
// field names and complete message/virtual ABI remain under verification.
class CPropGrid : public CXTPPropertyGrid,
                  public RBX::Listener<RBX::Instance, RBX::PropertyChanged> {
    DECLARE_DYNAMIC(CPropGrid)
    DECLARE_MESSAGE_MAP()
public:
    class Item {
    public:
        virtual void update(RBX::SelectionGroup*) = 0;
    };
    CPropGrid();
    virtual ~CPropGrid();
    virtual void onEvent(const RBX::Instance*, RBX::PropertyChanged);
    void addInstance(boost::shared_ptr<RBX::Instance>);
    void removeInstance(boost::shared_ptr<RBX::Instance>);
    void requestUpdate()
    {
        boost::recursive_mutex::scoped_lock lock(mutex);
        if (!posted) {
            if (m_hWnd) PostMessage(WM_USER + 101);
            posted = true;
        }
    }
    afx_msg int OnCreate(LPCREATESTRUCT);
    afx_msg LRESULT OnUpdate(WPARAM, LPARAM);
    void rebuild(const RBX::Reflection::ClassDescriptor*);
    virtual void addProperty(const RBX::Reflection::ClassDescriptor*, const RBX::Reflection::PropertyDescriptor*);
    boost::recursive_mutex mutex;
    RBX::DataModel* dataModel;
    std::vector<Item*> items;
    std::map<const RBX::Reflection::PropertyDescriptor*, Item*> propertyItems;
    std::map<void*, void*> itemProperties;
    bool posted;
    bool dirty;
    std::set<Item*> pendingItems;
    RBX::SelectionGroup groups;
};
