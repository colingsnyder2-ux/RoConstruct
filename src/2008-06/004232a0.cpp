// from server: 100% by Espeon
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: openrbx-client-dll roc_espeon_treetext_9c8ccdd1488c5609.cpp

// Candidate translation unit (score above; library headers required).
#include <boost/shared_ptr.hpp>
#include <string>
typedef boost::shared_ptr<void> Shared;
struct Result : Shared {};
struct Guard {
    unsigned char storage[12];
    Guard(Shared);
    ~Guard();
};

struct Receiver {
    virtual void unused();
    virtual void set(const std::string&);
};

struct Owner {
    unsigned char padding[12];
    Receiver* receiver;
};

struct Event {
    unsigned char padding0[28];
    const char* text;
    unsigned char padding1[16];
    Owner* owner;
};

#define SLOT(n) virtual void slot##n();
#define SLOTS(n) \
    SLOT(n##0) SLOT(n##1) SLOT(n##2) SLOT(n##3) SLOT(n##4) \
    SLOT(n##5) SLOT(n##6) SLOT(n##7) SLOT(n##8) SLOT(n##9)

struct CRobloxTreeCtrl {
    SLOTS(0)
    SLOTS(1)
    SLOTS(2)
    SLOTS(3)
    SLOTS(4)
    SLOTS(5)
    SLOTS(6)
    SLOTS(7)
    SLOT(80) SLOT(81) SLOT(82) SLOT(83) SLOT(84)
    virtual Result get();
    void f(Event*, int*);
};

#undef SLOTS
#undef SLOT

void CRobloxTreeCtrl::f(Event* event, int* result) {
    if (event->text) {
        Owner* owner = event->owner;
        Guard guard(get());
        {
            std::string text(event->text);
            owner->receiver->set(text);
        }
        *result = 1;
    } else {
        *result = 0;
    }
}
