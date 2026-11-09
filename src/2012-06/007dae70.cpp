// from server: 40% by atomic.potato
extern "C" void __stdcall G1_func_00536a00(void*);

struct S
{
    int f(int);
    void* field_2c;
};

int S::f(int value)
{
    char* p = (char*)field_2c;
    if (value)
        p += value - 0x1c;
    G1_func_00536a00(p);
    return 0;
}
