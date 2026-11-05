// from server: 40% by atomic.potato
struct S
{
    int f(int);
    int field_2c;
};

extern "C" void __stdcall G1_func_00536f00(void*);

int S::f(int value)
{
    char* base = (char*)field_2c;
    if (value)
        base += value - 0x1c;
    G1_func_00536f00(base);
    return 0;
}
