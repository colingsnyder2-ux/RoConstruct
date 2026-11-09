// from server: 33% by atomic.potato
struct S {
    char pad0[4];
    void* (__thiscall *fn)(void*);
};

extern "C" {
    void* __stdcall sub_a404c8(void*, void*);
    void __stdcall sub_a404d0(void*);
}

void* __stdcall S_GetSetImpl(S* self, void* a, void* b)
{
    void* v = 0;
    void* p = 0;
    if (a) {
        char* q = (char*)a - 0x1c;
        if (q)
            p = q + 0x208;
    }
    void* r = self->fn(p);
    void* s = (void*)((char*)self + 4);
    sub_a404c8(s, r);
    sub_a404d0(s);
    return s;
}
