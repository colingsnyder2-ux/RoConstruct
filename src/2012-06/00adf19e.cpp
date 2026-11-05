// from server: 40% by atomic.potato
extern "C" int __cdecl sub_00983A37(int);

struct S
{
};

int __cdecl f(int a, int b)
{
    int v = sub_00983A37(b ^ *(&b - 1));
    v = 0x00D37B78;
    return v;
}
