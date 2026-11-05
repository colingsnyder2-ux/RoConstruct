// from server: 87% by atomic.potato
struct S_func_006cb2b0 {
    char pad0[388];
    int m_x;
    int* f();
};

struct S {
    char pad0[4];
    void* m_vtbl;
    void g(void*);
};

void S::g(void* p)
{
    S_func_006cb2b0* q;
    if (p) {
        q = (S_func_006cb2b0*)((char*)p - 0x1c);
    } else {
        q = 0;
    }
    int* r = q->f();
    void (__thiscall *fn)(void*, int*) = *(void (__thiscall **)(void*, int*))((char*)this + 4);
    fn(this, r);
}
