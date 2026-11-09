// from server: 80% by atomic.potato
extern "C" void __stdcall _invalid_parameter_noinfo();
extern "C" void* __cdecl operator_new(unsigned int);

struct Holder {
    void* vtbl;
    int value;
};

struct Inner {
    void** vtbl;
    int value;
};

struct Outer {
    char pad0[0x2c];
    unsigned int count;
    char pad1[0x98];
    Inner** begin;
    Inner** end;
    bool insert(unsigned int idx, Holder** slot);
};

extern void* g_vtbl_holder;

bool Outer::insert(unsigned int idx, Holder** slot)
{
    Inner* item;
    bool ok;
    if (idx < count) {
        unsigned int n = (unsigned int)(((char*)end - (char*)begin) >> 2);
        if (idx >= n)
            _invalid_parameter_noinfo();
        item = begin[idx];
        ok = true;
    } else {
        item = 0;
        ok = false;
    }
    Holder* h = (Holder*)operator_new(8);
    if (h) {
        h->vtbl = g_vtbl_holder;
        h->value = (int)item;
    } else {
        h = 0;
    }
    Holder* old = *slot;
    if (slot != &old) {
        old = *slot;
        *slot = h;
    }
    if (old) {
        void** vt = (void**)old->vtbl;
        void (*fn)(Holder*, int) = (void (*)(Holder*, int))vt[0];
        fn(old, 1);
    }
    return ok;
}
