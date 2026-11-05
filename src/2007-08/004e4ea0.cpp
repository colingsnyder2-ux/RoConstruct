// from server: 30% by colin
// roc 2007-08 004e4ea0  unit: WedgeBuilder  size: 773 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 004e4ea0

extern "C" void __cdecl sub_5B9970(void*, void*);
extern "C" void* __cdecl sub_62FF32(int);
extern "C" void __cdecl sub_62FF26(void*);
extern "C" void* __cdecl sub_501570();
extern "C" void* __cdecl sub_4F5360(void*, void*, void*, int);
extern "C" void __cdecl sub_4F54E0(void*);
extern "C" void __cdecl sub_4EEE30(void*, int, int, int, int);

struct WedgeBuilder {
    void build(int a, int b, int c, int d, int e, int f, int g, int h, int i, int j, int k, int l, int m);
};

void WedgeBuilder::build(int a, int b, int c, int d, int e, int f, int g, int h, int i, int j, int k, int l, int m)
{
    char buf[0x84];
    int* arr;
    int n, w, hh;
    float fx, fy, fz;
    float ux, uy, uz;
    float vx, vy, vz;
    float du, dv;
    float u0, v0;
    float u1, v1;
    float su, sv;
    int i2, j2;
    int* p;
    int* q;
    float* pf;
    int total;
    int idx;

    sub_5B9970((char*)this + 4, buf + 0x18);

    n = *(short*)((char*)&a + 0x30);
    w = *(short*)((char*)&a + 0x32);

    fx = *(float*)((char*)&a + 0x10);
    fy = *(float*)((char*)&a + 0x14);
    fz = *(float*)((char*)&a + 0x18);

    ux = *(float*)((char*)&a + 0x1c);
    uy = *(float*)((char*)&a + 0x20);
    uz = *(float*)((char*)&a + 0x24);

    vx = *(float*)((char*)&a + 0x28);
    vy = *(float*)((char*)&a + 0x2c);
    vz = *(float*)((char*)&a + 0x30);

    du = (*(float*)((char*)&a + 0x18) - *(float*)((char*)&a + 0x10)) / (float)(n + 1);
    dv = (*(float*)((char*)&a + 0x1c) - *(float*)((char*)&a + 0x14)) / (float)(w + 1);

    total = (n + 1) * (w + 1);
    arr = (int*)sub_62FF32(total * 4);

    u0 = *(float*)((char*)&a + 0x10);
    v0 = *(float*)((char*)&a + 0x24);

    if (n >= 0) {
        for (i2 = 0; i2 <= n; i2++) {
            float uu = u0;
            float vv = v0;
            if (w >= 0) {
                for (j2 = 0; j2 <= w; j2++) {
                    float px = uu;
                    float py = vv;
                    float pz = 1.0f;

                    if (px < 0.0f) {
                        px = px - 0.0f;
                    } else {
                        px = px + 0.0f;
                    }

                    if (py < 0.0f) {
                        py = py - 0.0f;
                    } else {
                        py = py + 0.0f;
                    }

                    float* res = (float*)sub_501570();
                    if (res[0] == *(float*)((char*)&a + 0x2c) && res[1] == *(float*)((char*)&a + 0x30)) {
                        px = *(float*)((char*)&a + 0x24);
                        py = *(float*)((char*)&a + 0x28);
                    }

                    float tx = px * *(double*)0x795b48;
                    float ty = py * *(float*)((char*)&a + 0x2c);

                    sub_5B9970(&tx, buf + 0x18);
                    sub_5B9970(&px, buf + 0x18);

                    void* obj = sub_4F5360(buf + 0x18, buf + 0x18, buf + 0x18, 1);
                    *arr = (int)obj;
                    arr++;

                    uu = uu + du;
                    vv = vv + dv;
                }
            }
            u0 = u0 + du;
            v0 = v0 + dv;
        }
    }

    if (w > 0) {
        int* p1 = arr;
        int* p2 = arr + w + 2;
        for (i2 = 0; i2 < w; i2++) {
            if (n > 0) {
                for (j2 = 0; j2 < n; j2++) {
                    sub_4EEE30((void*)this, p1[0], p1[1], p2[0], p2[1]);
                    p1++;
                    p2++;
                }
            }
            p1 += n + 1;
            p2 += n + 1;
        }
    }

    for (i2 = 0; i2 < total; i2++) {
        sub_4F54E0((void*)arr[i2]);
    }

    sub_62FF26(arr);
}
