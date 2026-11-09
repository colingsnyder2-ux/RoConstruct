// from server: 58% by atomic.potato
struct S_func_006d5c70 {
    char pad0[4];
    int m_x;
    void f(int a1);
};

struct S {
    char pad0[8];
    void* m_p8;
    char padC[4];
    int m_count;
    char pad14[4];
    void* m_p18;
    void f(void* a1);
};

void S_func_006d5c70::f(int a1)
{
    m_x = (int)a1;
}

void S::f(void* a1)
{
    S_func_006d5c70* p = (S_func_006d5c70*)a1;
    p->f((int)this);
    void** vt = *(void***)a1;
    if (((int (__thiscall*)(void*))vt[4])(a1) == 0) {
        if (((char (__thiscall*)(void*))vt[12])(a1)) {
            void* prev = *(void**)((char*)this + 0x18);
            void* node = (char*)a1 + 0x24;
            *(void**)((char*)node + 4) = prev;
            *(void**)prev = node;
            *(void**)((char*)this + 0x18) = node;
            *(void**)node = (char*)this + 0x14;
            ++*(int*)((char*)this + 0x10);
        }
    }
    if (((int (__thiscall*)(void*))vt[4])(a1) != 0 ||
        ((int (__thiscall*)(void*))vt[5])(a1) < 1 ||
        ((int (__thiscall*)(void*))vt[5])(a1) > 3) {
        void* p8 = *(void**)((char*)this + 8);
        void** vt2 = *(void***)p8;
        ((void (__thiscall*)(void*, void*))vt2[3])(p8, a1);
    }
}
