// from server: 100% by atomic.potato
struct S_func_0065bc50 {
    char pad0[308];
    int m_x;
    int* f();
};

struct S {
    char pad0[4];
    int* (__thiscall *m_fn)(void*);
    void method(void* p);
};

void S::method(void* p)
{
    S_func_0065bc50* obj;
    if (p) {
        obj = (S_func_0065bc50*)((char*)p - 0x18);
    } else {
        obj = 0;
    }
    int* r = obj->f();
    m_fn((char*)r + 0x28);
}
