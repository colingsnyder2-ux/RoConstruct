// from server: 100% by colin
struct Freefall {
    Freefall(int);
};

extern void __stdcall G1_func_0062d8b0(int);

Freefall::Freefall(int arg)
{
    G1_func_0062d8b0(arg);
    *(int*)this = 0x7c4d40;
    *(int*)((char*)this + 8) = 0x7c4d38;
}
