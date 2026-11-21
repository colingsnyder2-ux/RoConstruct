#pragma once
#include <set>
#include <boost/shared_ptr.hpp>
namespace RBX { class DataModel; class Instance; }
class ActiveDocView {
public:
    ActiveDocView();
    ~ActiveDocView();
    void refresh();
    virtual void update(boost::shared_ptr<RBX::DataModel>, boost::shared_ptr<RBX::DataModel>) = 0;
};
extern std::set<ActiveDocView*> activeDocViews;

extern boost::shared_ptr<RBX::DataModel> activeDocDataModel;
