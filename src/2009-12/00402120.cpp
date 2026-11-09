// from server: 49% by atomic.potato
struct S
{
    int value;
    int f(int *out);
};

extern "C" void __stdcall G1_func_00476b90(int *value);

int S::f(int *out)
{
    int *value = *(int **)((char *)this + 0x9c);
    if (value != 0)
    {
        G1_func_00476b90(value);
        return (int)value;
    }
    out[0] = 0;
    out[1] = 0;
    return 0;
}
