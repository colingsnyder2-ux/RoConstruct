// from server: 76% by atomic.potato
struct S
{
    void f(void* object);
};

void S::f(void* object)
{
    if (object)
    {
        unsigned long* vtable = *(unsigned long**)object;
        void (__thiscall *function)(void*) =
            (void (__thiscall *)(void*))(vtable[0x3d]);
        function(object);
    }
}
