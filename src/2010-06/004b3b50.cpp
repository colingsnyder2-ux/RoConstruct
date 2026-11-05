// from server: 55% by atomic.potato
struct S
{
    int f();
};

int S::f()
{
    struct T
    {
        void (__thiscall **vtable)(void*);
        int a;
        int b;
        int c;
    };

    T* p = *(T**)((char*)this + 4);
    p->vtable[0]((void*)((char*)p + 16));
    return 0;
}
