// from server: 81% by atomic.potato
struct S_func_00651f00 {
    int __cdecl f(int value);
};

int __cdecl S_func_00651f00::f(int value)
{
    if (value < 0 || value > 2)
        return 0;
    return 1 << value;
}
