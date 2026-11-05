// from server: 51% by atomic.potato
extern "C" void __stdcall func_0070fe50(void*);

struct S {
    char pad[0x20];
    void* field20;
    void method(void* a, void* b);
};

void S::method(void* a, void* b)
{
    void* v;
    if (a)
        func_0070fe50(a);
    else
        v = 0;
    void* p = field20;
    void** vt = *(void***)p;
    void (*fn)(void*, void*, void*) = (void (*)(void*, void*, void*))vt[3];
    fn(p, b, v);
}
