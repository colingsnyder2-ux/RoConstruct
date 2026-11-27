// from server: 100% by Xemicl
// roc-cl: 30729
// roc-flags: /O2 /GS- /EHsc /MD
extern "C" __declspec(dllimport) long __stdcall InterlockedDecrement(volatile long*);
struct F {
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(int);
    long pad; volatile long ref;
};
unsigned long __stdcall f(F* p)
{
    unsigned long r = InterlockedDecrement(&p->ref);
    if (r == 0) {
        ++p->ref;
        p->v3(1);
        return 0;
    }
    if (r > 1) return r;
    return 1;
}

