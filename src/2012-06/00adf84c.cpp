// from server: 63% by atomic.potato
extern "C" int __cdecl Function983A37(int);

struct S
{
    int f(int, int);
};

int S::f(int a, int b)
{
    return Function983A37(*(int *)(b - 4) ^ b);
}
