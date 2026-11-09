// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: openrbx-client-dll roc_espclaude_5a1a70e3cf173fbe.cpp

// Candidate translation unit (score above; library headers required).
#include <boost/shared_ptr.hpp>
namespace RBX {
class ChildAdded {};
class ChildRemoved {};
template<class Class, class Event> class Listener {
public:
    virtual void onEvent(const Class* source, Event event) = 0;
};
template<class Class, class Event> class Notifier {
    char pad[0x20];
public:
    void addListener(Listener<Class, Event>* listener);
    template<typename T>
    static void connect(const T& notifier, Listener<Class, Event>* listener)
    {
        if (notifier)
            notifier->Notifier<Class, Event>::addListener(listener);
    }
};
class InstanceHead { public: virtual ~InstanceHead(); char pad[0x60]; };
class Instance : public InstanceHead, public Notifier<Instance, ChildAdded>, public Notifier<Instance, ChildRemoved> {};
class Backpack : public Instance {};
template<class T> boost::shared_ptr<T> shared_from(T* r);
class GuiBase { public: virtual ~GuiBase(); char pad[0x16c]; };
class LocalBackpack : public GuiBase, public Listener<Instance, ChildAdded>, public Listener<Instance, ChildRemoved> {
public:
    char mid[0x198 - 0x178];
    boost::shared_ptr<Backpack> localBackpack;
    virtual void onEvent(const Instance* source, ChildAdded event);
    virtual void onEvent(const Instance* source, ChildRemoved event);
    void onLocalBackpackAdded(Backpack* added);
};
void LocalBackpack::onLocalBackpackAdded(Backpack* added)
{
    localBackpack = shared_from(added);
    Notifier<Instance, ChildAdded>::connect(localBackpack, this);
    Notifier<Instance, ChildRemoved>::connect(localBackpack, this);
}
}
