// from server: 52% by atomic.potato
struct S
{
    void f(int, int);
};

extern "C" int sub_443980(int);
typedef void (__thiscall S::*Fn)(int, int);

void S::f(int a, int b)
{
    sub_443980(b);
    Fn fn = *(Fn *)((*(int **)this) + 0x40);
    (this->*fn)(a, b);
}
