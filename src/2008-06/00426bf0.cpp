// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: rbxgs-dll roc_espclaude_a5ea428152578063.cpp

// Candidate translation unit (score above; library headers required).
#include <boost/shared_ptr.hpp>

namespace RBX {
class DataModel;
class Listener {};
class ListenerList {
public:
    void add(Listener* l);
    void remove(Listener* l);
};
class Workspace {
public:
    char pad[0x130];
    ListenerList listeners;
};
class Selection {
public:
    char pad[0x130];
    ListenerList listeners;
};
class DataModel {
public:
    class scoped_lock {
    public:
        scoped_lock(boost::shared_ptr<DataModel> dataModel);
        ~scoped_lock();
        void* p;
        void* q;
        void* r;
    };
    Workspace* getWorkspace();
    Selection* getSelection();
};
}

class ViewBase {
public:
    char pad[0xd4];
};
class CRobloxView : public ViewBase, public RBX::Listener {
public:
    char pad2[0x124 - 0xd4];
    boost::shared_ptr<RBX::DataModel> dataModel;
    void setDataModel(boost::shared_ptr<RBX::DataModel> dm);
};

static inline void detach(RBX::Workspace* w, RBX::Listener* l) { if (w) w->listeners.remove(l); }
static inline void attach(RBX::Selection* s, RBX::Listener* l) { if (s) s->listeners.add(l); }
void CRobloxView::setDataModel(boost::shared_ptr<RBX::DataModel> dm)
{
    if (dataModel) {
        RBX::DataModel::scoped_lock lock(dataModel);
        detach(dataModel->getWorkspace(), this);
    }
    dataModel = dm;
    if (dataModel) {
        RBX::DataModel::scoped_lock lock(dataModel);
        attach(dataModel->getSelection(), this);
    }
}
