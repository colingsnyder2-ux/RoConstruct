// from server: 84% by atomic.potato
struct S_func_006cb2b0 {
    char pad0[388];
    int m_x;
    int* f();
};

struct S {
    char pad0[4];
    void* m_vt;
    void g(void*);
};

void S::g(void* p)
{
    S_func_006cb2b0* obj;
    if (p) {
        obj = (S_func_006cb2b0*)((char*)p - 0x1c);
    } else {
        obj = 0;
    }
    int* r = obj->f();
    void (*fn)(int*) = *(void (**)(int*))((char*)this + 4);
    fn(r);
}
