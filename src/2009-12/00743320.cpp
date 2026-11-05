// from server: 74% by atomic.potato
extern "C" void* __cdecl sub_7432D0(void*);

struct S {
    char pad[0x20];
    void* ptr;
    void Method(void*, void*);
};

void S::Method(void* a, void* b)
{
    void* v;
    if (a != 0) {
        v = sub_7432D0(a);
    } else {
        v = 0;
    }
    void* p = ptr;
    void** vt = *(void***)p;
    void (*fn)(void*, void*, void*) = (void (*)(void*, void*, void*))vt[4];
    fn(p, v, b);
}
