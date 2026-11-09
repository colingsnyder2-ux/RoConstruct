// from server: 100% by Espeon
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: openrbx-client-dll roc_espeon_viewchanged_aa6405150c5bf390.cpp

// Candidate translation unit (score above; library headers required).
#include <boost/shared_ptr.hpp>
struct StringValue {
    unsigned char data[28];
};

extern int (__thiscall *compareString)(const StringValue*, const char*);
extern int (__stdcall *PostMessageA)(void*, unsigned int, unsigned int, long);

struct NameValue {
    unsigned long reserved;
    StringValue text;
};

struct NameProvider {
    virtual void unused();
    virtual NameValue* getName();
};

struct Instance {
    unsigned char reserved[16];
    NameProvider names;
};

typedef boost::shared_ptr<Instance> SharedInstance;

struct MarshaledListener {
    void notify(void*);
};

struct CRobloxView {
    void changed(int, SharedInstance);
};

void CRobloxView::changed(int, SharedInstance instance)
{
    NameValue* name;
    if ((name = instance.get()->names.getName(),
         compareString(&name->text, "NetworkClient")) == 0 ||
        (name = instance.get()->names.getName(),
         compareString(&name->text, "Players")) == 0) {
        PostMessageA(*reinterpret_cast<void**>(
                         reinterpret_cast<char*>(this) - 128),
                     0x46b, 0, 0);
    }

    name = instance.get()->names.getName();
    if (compareString(&name->text, "Players") == 0) {
        void* listener = (reinterpret_cast<char*>(this) - 160)
                             ? reinterpret_cast<char*>(this) + 8
                             : 0;
        if (instance.get())
            reinterpret_cast<MarshaledListener*>(
                reinterpret_cast<char*>(instance.get()) + 0x150)->notify(listener);
    }
}
