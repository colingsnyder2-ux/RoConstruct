#pragma once
#include <set>
#include <boost/shared_ptr.hpp>
namespace RBX { class DataModel; class Instance; }
// Inactive native interface: RTTI and ctor/dtor verify one virtual slot.
// Callback signature and registry identity remain provisional.
class ActiveDocView {
public:
    ActiveDocView();
    ~ActiveDocView();
    virtual void update(boost::shared_ptr<RBX::DataModel>, boost::shared_ptr<RBX::Instance>) = 0;
};
extern std::set<ActiveDocView*> activeDocViews;
