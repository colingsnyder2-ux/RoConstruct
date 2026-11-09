// from server: 91% by atomic.potato
extern "C" int sub_0066e7a0(void *, int, int, float);
extern "C" int __cdecl sub_007f7b50(int);

float g_00a8c4c8;

struct S_func_0066f290
{
    int f(int, int);
};

int S_func_0066f290::f(int a, int b)
{
    int value = sub_0066e7a0((char *)this - 172, a, b, g_00a8c4c8);
    return sub_007f7b50(value);
}
