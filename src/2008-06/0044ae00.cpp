// from server: 100% by EspClaude
// from server: 97% by Espeon
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: openrbx-client-dll roc_espclaude_1ba0a1a4b73aa7cc.cpp

// Candidate translation unit (score above; library headers required).
#include <boost/shared_ptr.hpp>
typedef boost::shared_ptr<void> Shared;
struct Target {
    void apply(Shared value);
};

struct Interface {
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual void slot4();
    virtual void slot5();
    virtual void slot6();
    virtual void slot7();
    virtual void slot8();
    virtual void slot9();
    virtual void slot10();
    virtual void slot11();
    virtual void slot12();
    virtual void slot13();
    virtual void slot14();
    virtual void slot15();
    virtual void slot16();
    virtual void slot17();
    virtual void slot18();
    virtual void slot19();
    virtual void slot20();
    virtual void slot21();
    virtual void slot22();
    virtual void slot23();
    virtual void slot24();
    virtual void slot25();
    virtual void slot26();
    virtual void slot27();
    virtual void slot28();
    virtual void slot29();
    virtual void slot30();
    virtual void slot31();
    virtual void slot32();
    virtual void slot33();
    virtual Target* get(int, int);
};

struct Holder {
    char padding[0x28];
    Interface* interfaceObject;
    Interface* getInterface() const { return interfaceObject; }
};

struct CRobloxApp {
    char padding[0x58];
    Holder* holder;
    Holder* getHolder() const { return holder; }
    void apply(Shared value);
};

void CRobloxApp::apply(Shared value) {
    Interface* p = getHolder()->getInterface();
    Target* target = p->get(0, 1);
    target->apply(value);
}

