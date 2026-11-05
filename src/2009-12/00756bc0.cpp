// from server: 100% by atomic.potato
struct S
{
    int f(int);
};

extern "C" int __cdecl sub_7f4aaa(int, int, int, int, int);

int S::f(int a)
{
    return !sub_7f4aaa(a, 0, 0xaffe40, 0xb533ec, 0);
}
