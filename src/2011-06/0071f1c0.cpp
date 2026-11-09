// from server: 57% by atomic.potato
struct S_func_0066c140 {
    char pad0[388];
    int m_x;
    int* f();
};

struct S {
    char pad0[4];
    void* m_vtable;
    void g(void*);
};

void S::g(void* p)
{
    S_func_0066c140* obj;
    if (p) {
        obj = (S_func_0066c140*)((char*)p - 0x1c);
    } else {
        obj = 0;
    }
    int* r = obj->f();
    void (*fn)(void*, int*) = *(void (**)(void*, int*))((char*)this + 4);
    fn(this, r + 8);
}
