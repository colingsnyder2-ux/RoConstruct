// from server: 35% by atomic.potato
extern "C" void* __cdecl sub_4287B0(unsigned int);
extern "C" void __cdecl sub_428700(void*);
extern "C" void __cdecl sub_443CC0(void*, void*);
extern "C" void __cdecl sub_7D7F40(void*, void*, void*);

struct S {
    void f(void* a, void* b);
};

void S::f(void* a, void* b)
{
    void* p = sub_4287B0(0x38);
    if (p) {
        sub_7D7F40(p, a, b);
        *(void**)p = (void*)0xbc0f7c;
        *(void**)((char*)p + 8) = (void*)0xbc0f74;
    } else {
        p = 0;
    }
    sub_443CC0(this, p);
    *(void**)b = p;
    if (p) {
        sub_428700((char*)p + 5);
    }
}
