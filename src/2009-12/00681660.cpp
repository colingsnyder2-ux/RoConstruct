// from server: 39% by atomic.potato
extern "C" {
    int __stdcall sub_98B768();
    int __stdcall sub_98B7A4();
    void __cdecl sub_40A1D0(void*);
}

struct type_info {
    virtual ~type_info();
    virtual int operator==(const type_info&) const;
};

struct bad_cast {
    bad_cast(const char*);
};

struct S {
};

void* __cdecl f(void* a) {
    void* p = a;
    if (p != 0) {
        int* q = *(int**)p;
        if (q != 0) {
            int* vt = *(int**)q;
            typedef int (__thiscall *Fn)(void*);
            Fn fn = (Fn)vt[1];
            fn(q);
        } else {
            q = (int*)0xb0030c;
        }
        if (sub_98B768() != 0) {
            int* r = *(int**)p;
            r += 1;
            if (r != 0) {
                return p;
            }
        }
    }
    sub_98B7A4();
    void* v = (void*)0x99fe94;
    sub_40A1D0(&v);
    return p;
}
