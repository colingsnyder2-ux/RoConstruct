// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
// roc-lib: rbxgs-dll roc_espclaude_c10ceb206eeeada0.cpp

// Candidate translation unit (score above; library headers required).
#define _DLL
#include <boost/shared_ptr.hpp>
namespace RBX {
class Instance { public: int x; };
class Listener;
class ListenerList {
public:
    void remove(Listener* l);
    void add(Listener* l);
};
class Selection {
public:
    char pad[0x130];
    ListenerList listeners;
};
class Root : public Instance { public: void* getThing(); };
template<class T> boost::shared_ptr<T> shared_from(void* p);
class Guard {
public:
    Guard(boost::shared_ptr<Instance> instance);
    ~Guard();
    int a, b, c;
};
class Listener { public: virtual void onEvent(); };
}
class CBase0 { public: virtual ~CBase0(); char pad[0x18c]; };
class ISelectionTarget {
public:
    virtual void setInstance(boost::shared_ptr<RBX::Root> instance, boost::shared_ptr<RBX::Instance> other) = 0;
};
class CSelectionCaption : public CBase0, public ISelectionTarget, public RBX::Listener {
public:
    char pad[0x1b8 - 0x198];
    boost::shared_ptr<RBX::Root> current;
    boost::shared_ptr<RBX::Selection> selection;
    void updateCaption();
    static void attach(boost::shared_ptr<RBX::Selection>& s, RBX::Listener* l) { if (s) s->listeners.add(l); }
    static void detachFrom(boost::shared_ptr<RBX::Selection>& s, RBX::Listener* l) { if (s) s->listeners.remove(l); }
    void detach()
    {
        RBX::Guard guard1(current);
        detachFrom(selection, this);
        selection.reset();
    }
    virtual void setInstance(boost::shared_ptr<RBX::Root> instance, boost::shared_ptr<RBX::Instance> other);
};
void CSelectionCaption::setInstance(boost::shared_ptr<RBX::Root> instance, boost::shared_ptr<RBX::Instance> other)
{
    {
        RBX::Guard guard1(current);
        detachFrom(selection, this);
        selection.reset();
    }
    current.reset();
    if (instance)
    {
        current = instance;
        RBX::Guard guard2(current);
        selection = RBX::shared_from<RBX::Selection>(current ? current->getThing() : 0);
        attach(selection, this);
    }
    if (!selection)
        updateCaption();
}
