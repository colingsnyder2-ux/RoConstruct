// from server: 42% by atomic.potato
extern "C" void __cdecl sub_006824E0(void*);

struct S {
    char pad[0x20];
    void* field20;
    void method(void*, void*);
};

void S::method(void* a, void* b)
{
    void* v;
    if (a) {
        sub_006824E0(a);
        v = a;
    } else {
        v = 0;
    }
    void* p = field20;
    void* f = *(void**)p;
    void (*fn)(void*, void*, void*) = *(void (**)(void*, void*, void*))((char*)f + 0xc);
    fn(p, b, v);
}
