// from server: 62% by atomic.potato
struct S
{
    int f(int value);
    int *field;
};

extern "C" void __stdcall G1_func_008d7980(int *);

int S::f(int value)
{
    if (value != 0)
        G1_func_008d7980(field + value - 7);
    else
        G1_func_008d7980(field);
    return 0;
}
