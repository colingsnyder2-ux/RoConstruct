// from server: 81% by atomic.potato
extern "C" void __stdcall _invalid_parameter_noinfo();
extern "C" void* __cdecl operator_new(unsigned int);

struct Inner {
    void* vtbl;
    int value;
};

struct Outer {
    char pad0[0x2c];
    unsigned int count;
    char pad1[0xc8 - 0x30];
    Inner** begin;
    char pad2[0xcc - 0xc8];
    Inner** end;
    bool func(unsigned int idx, Inner** out);
};

bool Outer::func(unsigned int idx, Inner** out) {
    Inner* item;
    bool ok;
    if (idx < count) {
        unsigned int n = (unsigned int)(end - begin);
        if (idx >= n)
            _invalid_parameter_noinfo();
        item = begin[idx];
        ok = true;
    } else {
        item = 0;
        ok = false;
    }
    Inner* p = (Inner*)operator_new(8);
    if (p) {
        p->vtbl = (void*)0x9cc8d0;
        p->value = (int)item;
    } else {
        p = 0;
    }
    Inner* old = *out;
    *out = p;
    if (old) {
        void** vt = (void**)old->vtbl;
        void (*fn)(Inner*, int) = (void (*)(Inner*, int))vt[0];
        fn(old, 1);
    }
    return ok;
}
