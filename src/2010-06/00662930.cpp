// from server: 50% by atomic.potato
extern "C" void __cdecl sub_005e9220();

struct S {
    char pad[0x20];
    void* field20;
    void method(void* a, void* b);
};

void S::method(void* a, void* b)
{
    void* v;
    if (a) {
        sub_005e9220();
        v = a;
    } else {
        v = 0;
    }
    void** p = (void**)field20;
    void (*fn)(void*, void*) = *(void (**)(void*, void*))((char*)*p + 0x10);
    fn(v, b);
}
