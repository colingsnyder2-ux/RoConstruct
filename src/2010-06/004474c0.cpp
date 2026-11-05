// from server: 78% by atomic.potato
struct S {
    char pad0[0x2c];
    unsigned int count;
    char pad1[0xc8 - 0x30];
    int* begin;
    int* end;
    bool f(unsigned int idx, int** out);
};

extern "C" void __stdcall _invalid_parameter_noinfo();
extern "C" void* __cdecl operator_new(unsigned int);

bool S::f(unsigned int idx, int** out) {
    int* val;
    bool ok;
    if (idx < count) {
        int n = (int)((end - begin) >> 2);
        if (idx >= (unsigned int)n) {
            _invalid_parameter_noinfo();
        }
        val = (int*)begin[idx];
        ok = true;
    } else {
        val = 0;
        ok = false;
    }
    void* p = operator_new(8);
    if (p) {
        *(int*)p = 0xa0b100;
        *(int*)((char*)p + 4) = (int)val;
    } else {
        p = 0;
    }
    int* old = *out;
    if (out != (int**)&out) {
        old = *out;
        *out = (int*)p;
    }
    if (old) {
        void (*dtor)(void*) = *(void (**)(void*))old;
        dtor(old);
    }
    return ok;
}
