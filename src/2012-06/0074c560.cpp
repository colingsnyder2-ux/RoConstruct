// from server: 37% by atomic.potato
struct S {
    char pad0[0x14];
    int field14;

    int __cdecl f(void* arg);
    void* sub_67f480();
};

extern "C" void __stdcall sub_743a40(void*, void*);

extern "C" char __stdcall sub_509d50(void*);
extern "C" char __stdcall sub_479fa0(void*);
extern "C" void* __stdcall sub_74bb50(void*);
extern "C" void* __stdcall sub_74bcb0(void*);

extern "C" void* __stdcall imp_b22644(void*, void*);
extern "C" void __stdcall imp_b22658(void*, void*);
extern "C" void __stdcall imp_b2263c(void*);

int S::f(void* arg)
{
    char buf[0x20];
    void* p;
    sub_743a40(&p, arg);
    void* g = sub_67f480();
    if (sub_509d50(&p)) {
        imp_b22644(buf, &p);
        *(void**)(buf + 0x1c) = g;
        void* r = sub_74bb50(&p);
        imp_b22658(this, r);
        imp_b2263c(buf);
        if (this->field14 != 0) {
            imp_b2263c(&p);
            return 1;
        }
        imp_b2263c(&p);
        return 0;
    }
    if (sub_479fa0(&p)) {
        imp_b2263c(&p);
        return 1;
    }
    imp_b22644(buf, &p);
    *(void**)(buf + 0x1c) = g;
    void* r = sub_74bcb0(&p);
    imp_b22658(this, r);
    imp_b2263c(buf);
    if (this->field14 != 0) {
        imp_b2263c(&p);
        return 1;
    }
    imp_b2263c(&p);
    return 0;
}
