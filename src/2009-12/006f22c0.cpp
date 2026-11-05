// from server: 100% by atomic.potato
struct S_func_006cb2b0 {
    char pad0[388];
    int m_x;
    int* f();
};

struct S {
    char pad0[4];
    void (__thiscall *m_fn)(void*);
    void method(void* p);
};

void S::method(void* p)
{
    S_func_006cb2b0* obj;
    if (p) {
        obj = (S_func_006cb2b0*)((char*)p - 0x1c);
    } else {
        obj = 0;
    }
    int* r = obj->f();
    m_fn((char*)r + 0x18);
}
