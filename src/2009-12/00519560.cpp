// from server: 80% by atomic.potato
struct S
{
    void f();
};

void S::f()
{
    void** p = *(void***)(this + 8);
    if (p != 0)
    {
        void (__thiscall *fn)(void*, void*, int) =
            (void (__thiscall *)(void*, void*, int))*p;
        if (fn != 0)
        {
            void* q = (char*)this + 16;
            fn(q, q, 2);
        }
        *(void**)((char*)this + 8) = 0;
    }
}
