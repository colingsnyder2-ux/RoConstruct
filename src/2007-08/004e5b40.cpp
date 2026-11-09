// from server: 27% by colin
// roc 2007-08 004e5b40  unit: WedgeBuilder  size: 821 bytes
// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD

struct Vec2 { float x; float y; };
struct Vec3 { float x; float y; float z; };

extern "C" void __cdecl sub_5b9a10(void*, void*);
extern "C" void* __cdecl sub_62ff32(unsigned int);
extern "C" void* __cdecl sub_501570();
extern "C" void* __cdecl sub_4f5360(void*, void*, void*, int);
extern "C" void __cdecl sub_4eee30(void*, int, int, int, int);
extern "C" void __cdecl sub_4f54e0(void*);
extern "C" void __cdecl sub_62ff26(void*);

extern float g_795b48;

struct WedgeBuilder {
    char pad0[4];
    int field4;
    void build(int a, int b, int c, int d, int e, int f, int g, int h,
               int i, int j, int k, int l, int m);
};

void WedgeBuilder::build(int a, int b, int c, int d, int e, int f, int g, int h,
                         int i, int j, int k, int l, int m)
{
    char buf[0x60];
    Vec2 uv;
    Vec3 v;
    int n0, n1, n2, n3;
    float f0, f1, f2, f3, f4, f5, f6, f7, f8, f9, f10, f11, f12, f13, f14, f15;
    int* arr;
    int i0, i1, i2, i3;
    int count;
    int idx;

    sub_5b9a10(&buf[0x20], &field4);

    n0 = (short)i;
    n1 = (short)j;
    n2 = n0 + 1;
    n3 = n1 + 1;
    count = n3 * n2;

    f0 = (float)(int)n0;
    f1 = *(float*)&k - *(float*)&a;
    f2 = f1 / f0;
    f3 = (float)(int)n1;
    f4 = *(float*)&l - *(float*)&b;
    f5 = f4 / f3;
    f6 = *(float*)&m / *(float*)&c;
    f7 = *(float*)&d / *(float*)&e;

    arr = (int*)sub_62ff32((unsigned int)count * 4);

    f8 = *(float*)&a;
    f9 = *(float*)&f;
    f10 = *(float*)&b;
    f11 = *(float*)&g;
    f12 = *(float*)&h;
    f13 = *(float*)&i;
    f14 = *(float*)&j;
    f15 = *(float*)&k;

    if (n0 >= 0) {
        int row;
        float acc0 = f8;
        float acc1 = f9;
        float acc2 = f10;
        float acc3 = f11;
        float acc4 = f12;
        float acc5 = f13;
        float acc6 = f14;
        float acc7 = f15;
        int* p = arr;
        int rows = n0 + 1;
        do {
            if (n1 >= 0) {
                int cols = n1 + 1;
                float u0 = acc0;
                float u1 = acc1;
                float u2 = acc2;
                float u3 = acc3;
                float u4 = acc4;
                float u5 = acc5;
                float u6 = acc6;
                float u7 = acc7;
                do {
                    Vec2 t;
                    Vec3 q;
                    float s0, s1, s2, s3;
                    t.x = u0;
                    t.y = u1;
                    q.x = u2;
                    q.y = u3;
                    q.z = 1.0f;
                    s0 = u4;
                    s1 = u5;
                    s2 = u6;
                    s3 = u7;
                    if (s0 < s1) {
                        s0 = s0 - s1;
                    } else {
                        s0 = s0 + s1;
                    }
                    if (s2 < s3) {
                        s2 = s2 - s3;
                    } else {
                        s2 = s2 + s3;
                    }
                    if (s0 < s2) {
                        s0 = s0 - s2;
                        s1 = s1 - s2;
                    } else {
                        s0 = s0 + s2;
                        s1 = s1 + s2;
                    }
                    {
                        Vec2* r = (Vec2*)sub_501570();
                        if (r->x == *(float*)&c && r->y == *(float*)&d) {
                            t.x = *(float*)&f;
                            t.y = *(float*)&g;
                        }
                    }
                    {
                        Vec2 uv2;
                        Vec3 v2;
                        uv2.x = t.x * g_795b48;
                        uv2.y = t.y * g_795b48;
                        sub_5b9a10(&uv2, &uv);
                        sub_5b9a10(&q, &v);
                        *p = (int)sub_4f5360(&v, &uv, &t, 1);
                    }
                    u0 = u0 + f2;
                    u1 = u1 + f5;
                    u2 = u2 + f6;
                    u3 = u3 + f7;
                    u4 = u4 + f8;
                    u5 = u5 + f9;
                    u6 = u6 + f10;
                    u7 = u7 + f11;
                    p++;
                    cols--;
                } while (cols != 0);
            }
            acc0 = acc0 + f2;
            acc1 = acc1 + f5;
            acc2 = acc2 + f6;
            acc3 = acc3 + f7;
            acc4 = acc4 + f8;
            acc5 = acc5 + f9;
            acc6 = acc6 + f10;
            acc7 = acc7 + f11;
            rows--;
        } while (rows != 0);
    }

    if (count > 0) {
        int* p0 = arr;
        int* p1 = arr + n1 + 2;
        int rows = count;
        do {
            if (n1 > 0) {
                int cols = n1;
                int* q0 = p0;
                int* q1 = p1;
                do {
                    sub_4eee30((void*)this, q0[0], q0[1], q1[-1], q1[0]);
                    q0++;
                    q1++;
                    cols--;
                } while (cols != 0);
            }
            p0 += n1 + 1;
            p1 += n1 + 1;
            rows--;
        } while (rows != 0);
    }

    {
        unsigned int n = (unsigned int)count;
        unsigned int s = 0;
        if (n > 0) {
            do {
                sub_4f54e0((void*)arr[s]);
                s++;
            } while (s < n);
        }
    }
    sub_62ff26(arr);
}
