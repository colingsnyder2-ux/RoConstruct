// from server: 60% by atomic.potato
extern "C" void __cdecl sub_983A37(int);

struct S
{
};

int __cdecl f(int a, int b)
{
    sub_983A37(b ^ *(int *)(b - 4));
    return 0x00D3846C;
}
