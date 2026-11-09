// from server: 100% by atomic.potato
struct S
{
    void __cdecl f(float);
};

void __cdecl S::f(float value)
{
    struct V
    {
        void (__thiscall *call)(V *, float);
        int a;
        int b;
    };

    V *v = (V *)((char *)this);
    int ecx_value = v->b + v->a;
    ((void (__thiscall *)(V *, float))v->call)((V *)ecx_value, value);
}
