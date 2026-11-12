// from server: 78% by EspClaude
// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS /EHsc /MD
// roc-lib: g3d-6.09 roc_claude_e255617b41df5a6b.cpp

// Candidate translation unit (score above; library headers required).
// 2007-08 CRobloxView "ToggleToolbox" verb constructor (codegen analog; layout read off 0x455e50):
//   source upcast lea [ebx+0x14c]; Base(Context*, std::string by value 0x1c); vptr; [+0xc]=arg1; [+0x10]=arg2;
//   [+0x18]=double from 0x4ffef0; ret 8.
#include <string>
struct Context {
    int value;
};

struct OwnerPadding {
    char storage[0x14c];
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
