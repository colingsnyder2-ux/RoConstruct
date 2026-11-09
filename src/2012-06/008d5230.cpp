// from server: 69% by atomic.potato
struct S_func_008d5230
{
    int __cdecl f(int a, int b);
};

extern "C" int __cdecl sub_008d5090(int, int, int);

int S_func_008d5230::f(int a, int b)
{
    if (b != 4)
        return sub_008d5090(0, a, b);

    *(int*)a = 0xDF3E80;
    *(unsigned char*)(a + 4) = 0;
    *(unsigned char*)(a + 5) = 0;
    return 0;
}
