// from server: 100% by atomic.potato
typedef int (__cdecl *FunctionType)(int, int, int, int, int);

extern "C" int __cdecl sub_0080b2ea(int, int, int, int, int);

struct S
{
    int f(int);
};

int S::f(int value)
{
    int result = sub_0080b2ea(value, 0, 0x00c071f8, 0x00c44d2c, 0);
    return result != 0;
}
