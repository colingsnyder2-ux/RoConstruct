// from server: 45% by colin
struct MVCXTPPropertyGridItem {
    char pad[0x114];
    void* field114;
    void* field118;
    void* f(void* a, void* b);
};

extern "C" void __stdcall sub_439850(void*, void*);
extern "C" void __stdcall sub_5595a0(void*);

void* MVCXTPPropertyGridItem::f(void* a, void* b) {
    void* local;
    void* p = field114;
    void* q = *(void**)((char*)p + 0x188);
    sub_439850(&local, q);
    void* r;
    if (a) {
        r = (char*)a + 4;
    } else {
        r = 0;
    }
    void* s = field118;
    void* t = *(void**)s;
    void* (*fn)(void*, void*, void*) = *(void* (**)(void*, void*, void*))((char*)t + 0x10);
    fn(s, b, r);
    sub_5595a0(&local);
    return b;
}
