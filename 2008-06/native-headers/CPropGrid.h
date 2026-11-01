#pragma once
#include <XTToolkitPro.h>
#include "util/Events.h"
#include <boost/thread/recursive_mutex.hpp>
#include <map>
#include <set>

namespace RBX { class DataModel; class Instance; class PropertyChanged; }

// Inactive typed storage recovery. Pointer-container payload identities,
// field names and complete message/virtual ABI remain under verification.
class CPropGrid : public CXTPPropertyGrid,
                  public RBX::Listener<RBX::Instance, RBX::PropertyChanged> {
    DECLARE_DYNAMIC(CPropGrid)
public:
    CPropGrid();
    virtual ~CPropGrid();
    virtual void onEvent(const RBX::Instance*, RBX::PropertyChanged);
    boost::recursive_mutex mutex;
    RBX::DataModel* dataModel;
    std::vector<RBX::Instance*> instances;
    std::map<void*, void*> propertyItems;
    std::map<void*, void*> itemProperties;
    bool posted;
    bool dirty;
    std::set<void*> pendingItems;
    std::set<std::string> names;
};
