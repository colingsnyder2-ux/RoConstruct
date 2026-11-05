// from server: 77% by atomic.potato
extern "C" void __cdecl sub_007adc70(int);

struct S_func_007ae0b0 {
    char pad0[28];
    int f();
};

int S_func_007ae0b0::f()
{
    sub_007adc70(2);
    *(int *)this = 0x00abcfa4;
    *(int *)(this->pad0 + 28) = 0x00abcf88;
    return (int)this;
}
