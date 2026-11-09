// from server: 100% by atomic.potato
struct S_func_0065bc50 {
    char pad0[308];
    int m_x;
    int* f();
};

struct S {
    char pad0[4];
    void* m_callback;
    void invoke(void*);
};

void S::invoke(void* p)
{
    S_func_0065bc50* obj;
    if (p) {
        obj = (S_func_0065bc50*)((char*)p - 0x18);
    } else {
        obj = 0;
    }
    int* r = obj->f();
    void* fn = m_callback;
    ((void (__thiscall*)(int*))fn)((int*)((char*)r + 0x20));
}
