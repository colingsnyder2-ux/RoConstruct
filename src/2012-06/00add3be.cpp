// from server: 60% by atomic.potato
extern "C" int __cdecl sub_00983A37(int);

struct S
{
};

int __cdecl f(int a, int b)
{
    int x = b;
    int y = *(int *)(b - 4) ^ x;
    sub_00983A37(y);
    return 0x00D35DC4;
}
