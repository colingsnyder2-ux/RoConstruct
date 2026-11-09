// from server: 88% by atomic.potato
struct S_func_00750a60 {
    char pad0[436];
    int m_x;
    int* f();
};

struct S {
    char pad0[4];
    void (S::*m_fn)(int*);
    void g(void*);
};

void S::g(void* p)
{
    S_func_00750a60* obj;
    if (p) {
        obj = (S_func_00750a60*)((char*)p - 0x1c);
    } else {
        obj = 0;
    }
    int* r = obj->f();
    (this->*m_fn)(r);
}
