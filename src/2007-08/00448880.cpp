// from server: 100% by colin
struct Inner;

struct InnerVtbl {
    void* pad[34];
    void (__stdcall *fn)(int, int);
};

struct Inner {
    InnerVtbl* vtbl;
};

struct Mid {
    char pad[0x20];
    Inner* inner;
};

struct Outer {
    char pad[0x58];
    Mid* mid;
};

struct CRbxDocTemplate {
    char pad[0x58];
    Mid* mid;
    void f();
};

void CRbxDocTemplate::f()
{
    Mid* m = this->mid;
    Inner* in = m->inner;
    InnerVtbl* vt = in->vtbl;
    vt->fn(0, 1);
}
