// from server: 100% by Xemicl
// roc-cl: 30729
// roc-flags: /O2 /GS- /EHsc /MD

extern "C" long __cdecl _InterlockedIncrement(long volatile*);
#pragma intrinsic(_InterlockedIncrement)
struct Cnt { virtual void dispose(); virtual void destroy(); long use; long weak; };
struct SP {
    void* px; Cnt* pn;
    SP(const SP& o) : px(o.px), pn(o.pn) { if (pn) _InterlockedIncrement(&pn->use); }
    ~SP();
};
struct F {
    void (*fn)(SP, int); SP a1; int a2;
    void operator()() { fn(a1, a2); }
};
void invoke(void* p)
{
    F* f = (F*)p;
    (*f)();
}
