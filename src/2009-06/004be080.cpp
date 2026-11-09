// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
#include <string>
extern "C" long __cdecl _InterlockedIncrement(long volatile*);
#pragma intrinsic(_InterlockedIncrement)
struct Counted { void* vptr; long use_count; };
struct Obj;
struct SharedPtr {
    Obj* px;
    Counted* pn;
    SharedPtr(const SharedPtr& o) : px(o.px), pn(o.pn) { if (pn) _InterlockedIncrement(&pn->use_count); }
    ~SharedPtr();
};
struct Self;
struct Target {
    void handle(Self* self, std::string s, SharedPtr p);
};
struct Args { const std::string* s; const SharedPtr* p; };
struct Self {
    void call(int, Target* t, const Args& a, int);
};
void Self::call(int, Target* t, const Args& a, int)
{
    t->handle(this, *a.s, *a.p);
}
