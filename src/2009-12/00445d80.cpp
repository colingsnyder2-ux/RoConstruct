// from server: 84% by atomic.potato
extern "C" void __stdcall _invalid_parameter_noinfo();
extern "C" void* __cdecl sub_7F3860(unsigned int);

struct Inner {
    void** vtable;
    int value;
};

struct Outer {
    char pad0[0x2c];
    unsigned int count;
    char pad1[0x98];
    Inner** begin;
    Inner** end;
    bool get(unsigned int idx, Inner** out);
};

bool Outer::get(unsigned int idx, Inner** out) {
    Inner* item;
    bool ok;
    if (idx < count) {
        unsigned int n = (unsigned int)(((char*)end - (char*)begin) >> 2);
        if (idx >= n) {
            _invalid_parameter_noinfo();
        }
        item = begin[idx];
        ok = true;
    } else {
        item = 0;
        ok = false;
    }
    Inner* tmp = (Inner*)sub_7F3860(8);
    if (tmp) {
        tmp->vtable = (void**)0x9aa348;
        tmp->value = (int)item;
    } else {
        tmp = 0;
    }
    Inner* old = *out;
    if (&old != out) {
        old = *out;
        *out = tmp;
    }
    if (old) {
        ((void (__stdcall*)(void*, int))old->vtable[0])(old, 1);
    }
    return ok;
}
