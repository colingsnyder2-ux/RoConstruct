// from server: 60% by atomic.potato
struct S {
    char pad0[0x18];
    unsigned int len;
    char pad1[4];
    char data;
};

struct T {
    void* __thiscall f(void*);
};

extern "C" void __stdcall sub_4015a0(void*, void*);
extern "C" void* __cdecl sub_771380();
extern "C" void* __cdecl sub_67f5b0(void*, void*);

void* __cdecl sub_7c7020(S* s) {
    char* p;
    if (s->len < 0x10)
        p = &s->data;
    else
        p = *(char**)((char*)s + 4);
    sub_4015a0((void*)0x7713e0, (void*)0xe48628);
    void* r = sub_771380();
    void* tmp = p;
    void* q = sub_67f5b0(&tmp, p);
    return ((T*)r)->f(q);
}
