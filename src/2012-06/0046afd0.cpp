// from server: 72% by atomic.potato
struct S
{
    int f(int value);
};

extern "C" void __stdcall G1_func_00414500(S* object, int value);

int S::f(int value)
{
    if (value != *(int*)((char*)this + 0x94))
    {
        *(int*)((char*)this + 0x94) = value;
        G1_func_00414500((S*)((char*)this + 0x144), 0x00e198ec);
    }
    return 0;
}
