// from server: 36% by atomic.potato
struct S
{
    typedef void (__thiscall *Call)(int, int, int, int);
    Call f;
};

void __stdcall invoke(S* object, int a, int b, int c)
{
    int args[4];
    args[0] = a;
    args[1] = b;
    args[2] = c;
    args[3] = 0;
    object->f(args[0], args[1], args[2], args[3]);
}
