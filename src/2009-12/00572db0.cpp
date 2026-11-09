// from server: 29% by atomic.potato
extern "C" void* __cdecl sub_7F4A40(unsigned int);
extern "C" int __cdecl sub_572680(int*, int*, int, int);
extern "C" int __cdecl sub_572700(int*, int*, int, int, int*);
extern "C" int __cdecl sub_5727A0(int*, int, int);
extern "C" int __cdecl sub_5727E0(int*, int, int, int);
extern "C" void __cdecl sub_5729B0(int, int, int, int);
extern "C" void __cdecl sub_572DB0(int, int*, int*, int*);

void __cdecl sub_572DB0(int a, int* b, int* c, int* d)
{
    if (a < 0x14 || (a & 1))
    {
        sub_5729B0(a, (int)b, (int)c, (int)d);
        return;
    }

    int half = a / 2;
    sub_572DB0(half, b, c, d);
    sub_572DB0(half, b + a, c + half, d + half);

    int* p1 = (int*)sub_7F4A40(half * 4);
    int* p2 = (int*)sub_7F4A40(half * 4);
    int* p3 = (int*)sub_7F4A40(a * 4);

    int v1 = sub_572700(b, b + half, half, half, p1);
    int v2 = sub_572700(d, d + half, half, half, p2);

    sub_572DB0(half, p3, p1, p2);

    int r = sub_5727E0(p3, a, (int)b, a);
    r += sub_5727E0(p3, a, (int)(b + a), a);

    if (v2)
        r += sub_572680(p3 + half, p1, half, half);
    if (v1)
        r += sub_572680(p3 + half, p2, half, half);

    r += sub_572680(b + half, p3, a / 2 * 3, a);

    int t = v2 & v1;
    t += r;
    if (t)
        sub_5727A0(b + (a / 2 * 3), half, t);
}
