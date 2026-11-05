// from server: 32% by colin
struct Inner;

struct InnerVtbl {
    char pad[0x5c];
    void* (__stdcall *fn5c)();
    void* (__stdcall *fn60)(void*);
};

struct Inner {
    InnerVtbl* vtbl;
};

struct InnerHolder {
    char pad[0x24];
    Inner* inner;
};

struct CRbxDocTemplate {
    char pad[0x58];
    InnerHolder* holder;
    int f(int, int, int, int, int, int, int);
};

extern "C" void* __stdcall sub_77E69C(void*, const void*);
extern "C" void __stdcall sub_77E6AC(void*);
extern "C" int __stdcall sub_452270(void*, void*);

int CRbxDocTemplate::f(int, int, int, int, int, int, int)
{
    InnerHolder* h = this->holder;
    Inner* in = h->inner;
    InnerVtbl* vt = in->vtbl;
    void* p = vt->fn5c();
    if (p != 0) {
        for (;;) {
            void* q = vt->fn60(&p);
            char buf[0x1c];
            sub_77E69C(buf, &p);
            int r = sub_452270(q, buf);
            sub_77E6AC(buf);
            if (r == 0)
                return 0;
            if (p == 0)
                break;
        }
    }
    return 1;
}
