#pragma once
// >>> native-status (generated) -- do not edit >>>
// ActiveDocView | 2008-06 | inactive
// unmapped (no binary link) | unmapped (no binary link) | by -
// <<< native-status | src 63e432fb | roc native-status --write
#include <set>
#include <boost/shared_ptr.hpp>
namespace RBX { class DataModel; class Instance; }
// Inactive native interface: RTTI and ctor/dtor verify one virtual slot.
// Activation 00405aa0 passes current/previous DataModels from CRobloxDoc::getDataModel.
class ActiveDocView {
public:
    ActiveDocView();
    ~ActiveDocView();
    void refresh();
    virtual void update(boost::shared_ptr<RBX::DataModel>, boost::shared_ptr<RBX::DataModel>) = 0;
};
extern std::set<ActiveDocView*> activeDocViews;

// Original shared model at 0096c25c; storage initialization not yet recovered.
extern boost::shared_ptr<RBX::DataModel> activeDocDataModel;
