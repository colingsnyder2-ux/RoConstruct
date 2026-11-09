// from server: 70% by atomic.potato
struct S_func_006e6800 {
    char pad0[0x20];
    void* m_ptr;
    void f(void* a, void* b);
};

extern "C" void* __cdecl sub_006e67b0(void*);

void S_func_006e6800::f(void* a, void* b)
{
    void* v;
    if (a != 0) {
        v = sub_006e67b0(a);
    } else {
        v = 0;
    }
    void* p = m_ptr;
    void** pp = (void**)p;
    void (*fn)(void*, void*) = (void (*)(void*, void*))((void**)pp[0])[4];
    fn(v, b);
}
