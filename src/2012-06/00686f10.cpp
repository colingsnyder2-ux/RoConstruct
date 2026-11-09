// from server: 85% by atomic.potato
extern "C" int __cdecl sub_983448(int, int, int, int, int);
extern "C" void __cdecl sub_7f4fa0(int);

struct S
{
    int padding[83];
    int field_14c;
    void f();
};

void S::f()
{
    int value = sub_983448(field_14c, 0, 0xd601e8, 0xd9a458, 0);
    if (value)
        sub_7f4fa0(value);
}
