// from server: 94% by atomic.potato
struct S_func_0066c140 {
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
    S_func_0066c140* q;
    if (p) {
        q = (S_func_0066c140*)((char*)p - 0x1c);
    } else {
        q = 0;
    }
    int* r = q->f();
    void* fn = *(void**)((char*)this + 4);
    ((void (__thiscall*)(void*, int*))fn)((char*)r + 0x18, r);
}
