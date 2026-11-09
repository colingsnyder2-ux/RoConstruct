// from server: 100% by colin
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
#include <string>
struct Context {
    int value;
};

struct OwnerPadding {
    char storage[0x1c8];
};

struct Owner : OwnerPadding, Context {
};

extern double __cdecl readTime();

struct Base {
    int storage[2];

    Base(Context*, std::string);
    virtual ~Base();
};

struct CRobloxView : Base {
    void* argument;
    Owner* owner;
    int reserved;
    double timestamp;

    CRobloxView(void*, Owner*);
    virtual ~CRobloxView();
};

CRobloxView::CRobloxView(void* value, Owner* source)
    : Base(static_cast<Context*>(source), "ToggleToolbox")
{
    argument = value;
    owner = source;
    timestamp = readTime();
}
