// from server: 60% by atomic.potato
extern "C" void __cdecl sub_983A37(int);

struct seg_00ad0000
{
};

int __cdecl f(int a, int b)
{
    sub_983A37(*(int *)((char *)b - 4) ^ b);
    return 0x00D34F54;
}
