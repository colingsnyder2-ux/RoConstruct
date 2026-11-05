// from server: 71% by atomic.potato
struct S {
    char pad0[0x2c];
    unsigned int count;
    char pad1[0x98];
    int* begin;
    int* end;
    bool f(unsigned int idx, int* out);
};

extern "C" void __stdcall _invalid_parameter_noinfo();
extern "C" void* __cdecl sub_7a79a0(unsigned int);
extern "C" void* __stdcall sub_9ea90c();

bool S::f(unsigned int idx, int* out) {
    int val;
    bool ok;
    if (idx < count) {
        int n = (int)(((char*)end - (char*)begin) >> 2);
        if (idx >= (unsigned int)n)
            _invalid_parameter_noinfo();
        val = begin[idx];
        ok = true;
    } else {
        val = *out;
        ok = false;
    }
    void* p = sub_7a79a0(8);
    if (p) {
        *(void**)p = (void*)0xa2aa84;
        *((int*)p + 1) = val;
    } else {
        p = 0;
    }
    int* tmp = out;
    int* old = (int*)p;
    if (&out != &tmp) {
        old = *(int**)out;
        *(void**)out = p;
    }
    if (old) {
        void** vt = *(void***)old;
        void (*fn)(void*) = (void (*)(void*))vt[0];
        fn(old);
    }
    return ok;
}
