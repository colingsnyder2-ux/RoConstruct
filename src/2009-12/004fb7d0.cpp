// from server: 52% by atomic.potato
struct S {
    char pad0[4];
};

extern "C" int __stdcall sub_4f86f0(int, int, int, int, int);

int __cdecl f(int a, int b, int c, int d, int e)
{
    char buf[8];
    int v1;
    int v2;
    buf[0] = 0;
    v1 = (int)&e;
    v2 = (int)&d;
    return sub_4f86f0(a, b, (int)buf, v2, v1);
}
