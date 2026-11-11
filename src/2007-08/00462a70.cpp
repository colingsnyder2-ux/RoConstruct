// from server: 100% by EspClaude
// from server: 93% by EspClaude
// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 50727
// roc-lib: rbxgs-dll roc_claude_fe65bf0fea96be08.cpp

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
    char pad[0xe8];
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
    char pad[0x1b0 - 0x198];
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
        current.reset();
    }
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
