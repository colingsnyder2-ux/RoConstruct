// from server: 100% by Yeetserama
// hypothesis: 00464eb0 is a this-adjusting thunk like exact 0045d840,
// with a negative adjustment (-0x28) and three stack arguments.
struct S_func_00464eb0 {
    char pad0[0x28];
    void f(int, int, int);
};

extern "C" void __fastcall sub_00463a00(void*);

void S_func_00464eb0::f(int, int, int)
{
    sub_00463a00((char*)this - 0x28);
}
