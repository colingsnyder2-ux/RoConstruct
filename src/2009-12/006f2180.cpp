// from server: 62% by atomic.potato
struct S_func_006cb2b0 {
    char pad0[388];
    int m_x;
    int* f();
};

struct S {
    char pad0[4];
    void* m_fn;
    void g(void*);
};

void S::g(void* p)
{
    S_func_006cb2b0* o;
    if (p) {
        o = (S_func_006cb2b0*)((char*)p - 0x1c);
    } else {
        o = 0;
    }
    int* r = o->f();
    void (*fn)(void*) = (void (*)(void*))m_fn;
    fn(r + 2);
}
