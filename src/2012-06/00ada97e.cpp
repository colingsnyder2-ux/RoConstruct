// from server: 61% by atomic.potato
extern "C" int __cdecl sub_00983A37(int);
extern "C" int __cdecl sub_009830E6(int, int);

struct seg_00ad0000
{
    int f(int, int);
};

int seg_00ad0000::f(int a, int b)
{
    int v = *(int *)((char *)b - 4) ^ b;
    sub_00983A37(v);
    return sub_009830E6(0x00D32EB4, 0);
}
