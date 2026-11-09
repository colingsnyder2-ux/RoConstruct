// from server: 100% by atomic.potato
extern "C" int __cdecl sub_7f4aaa(int, int, int, int, int);

struct S
{
    int f(int);
};

int S::f(int value)
{
    return sub_7f4aaa(value, 0, 0xaffe40, 0xb32a2c, 0) != 0;
}
