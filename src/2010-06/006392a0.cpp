// from server: 45% by atomic.potato
struct S
{
    struct V
    {
        int (__thiscall **vtable)(void*, int);
    };

    V* value;
    int f(int);
};

extern "C" int sub_6390f0(S*, int);

int S::f(int arg)
{
    V* p = value;
    int result = p->vtable[3](&arg, arg);
    return sub_6390f0(this, result);
}
