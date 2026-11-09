// from server: 69% by atomic.potato
struct S
{
    void f();
    int value[91];
};

extern "C" int __cdecl sub_5fc4e0(int);

void S::f()
{
    int value = this->value[90];
    int remainder = (value + 1) & 0x80000001;
    if (remainder < 0)
        remainder = (remainder - 1) | 0xfffffffe, ++remainder;
    sub_5fc4e0(remainder + value + 1);
}
