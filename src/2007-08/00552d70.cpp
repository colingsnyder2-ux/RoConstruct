// from server: 100% by colin
struct S {
    char pad[0x18];
    void* field_18;
    S* dtor(char flag);
};

extern "C" void __cdecl sub_54c650();
extern "C" void __cdecl sub_62fc62(void*);

extern void* g_77e4dc;
extern void* g_77e4e0;
extern void (__cdecl *g_77e4e4)(void*);

S* S::dtor(char flag) {
    sub_54c650();
    void* p = (void*)((char*)this + 0x18);
    *(void**)p = g_77e4dc;
    *(void**)p = g_77e4e0;
    g_77e4e4(p);
    if (flag & 1) {
        sub_62fc62(this);
    }
    return this;
}
