// from server: 16% by colin
// roc 2007-08 004ec270  unit: CylinderBuilder  size: 837 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 004ec270

struct Vector3 {
    float x, y, z;
};

struct Matrix3 {
    float m[3][3];
};

struct CylinderBuilder {
    char pad0[4];
    int field4;
    void build(int a, int b, int c, int d, int e, int f, int g, int h, int i, int j, int k, int l, int m);
};

extern "C" void __cdecl sub_5b9970(void*, void*);
extern "C" void* __cdecl sub_62ff32(int);
extern "C" void __cdecl sub_62ff26(void*);
extern "C" void __cdecl sub_4f54e0(void*);
extern "C" void __cdecl sub_4eb600(void*, void*, void*, void*, void*, void*);
extern "C" void* __cdecl sub_501570();
extern "C" void* __cdecl sub_4f5360(void*, void*, void*, int);
extern "C" void __cdecl sub_4eee30(void*, int, int, int, int);

extern double g_795b48;

void CylinderBuilder::build(int a, int b, int c, int d, int e, int f, int g, int h, int i, int j, int k, int l, int m)
{
    Vector3 v;
    sub_5b9970(&v, &this->field4);

    float ax = (v.x < 0.0f) ? -v.x : v.x;
    float ay = (v.y < 0.0f) ? -v.y : v.y;
    float az = (v.z < 0.0f) ? -v.z : v.z;

    int n1 = (short)a;
    int n2 = (short)b;
    int count = (n1 + 1) * (n2 + 1);

    float f1 = (float)n1;
    float f2 = (float)(c - d);
    float f3 = f2 / f1;
    float f4 = (float)(e - f);
    float f5 = f4 / f1;
    float f6 = (float)g / f1;
    float f7 = (float)h / f1;

    void* buf = sub_62ff32(count * 4);
    void** arr = (void**)buf;

    float base1 = (float)d;
    float base2 = (float)f;
    float base3 = (float)i;
    float base4 = (float)j;

    int idx = 0;
    float acc1 = 0.0f;
    float acc2 = 0.0f;

    if (n1 >= 0) {
        for (int ii = 0; ii <= n1; ii++) {
            float cur1 = base1;
            float cur2 = base2;
            if (n2 >= 0) {
                for (int jj = 0; jj <= n2; jj++) {
                    Vector3 p;
                    p.x = cur1;
                    p.y = cur2;
                    p.z = base3;
                    Vector3 q;
                    q.x = cur1;
                    q.y = cur2;
                    q.z = base4;

                    float t1 = 1.0f;
                    float t2 = 1.0f;

                    sub_4eb600(&this->field4, &p, &q, &t1, &t2, 0);

                    void* r = sub_501570();
                    float* rf = (float*)r;
                    if (rf[0] == f6 && rf[1] == f7) {
                        p.z = base3;
                        q.z = base4;
                    }

                    Vector3 p2;
                    p2.x = p.x * (float)g_795b48;
                    p2.y = p.y * (float)g_795b48;
                    p2.z = p.z;

                    Vector3 q2;
                    q2.x = q.x * (float)g_795b48;
                    q2.y = q.y * (float)g_795b48;
                    q2.z = q.z;

                    sub_5b9970(&p2, &p2);
                    sub_5b9970(&q2, &q2);

                    void* res = sub_4f5360(&p2, &q2, &p2, 1);
                    arr[idx] = res;
                    idx++;

                    cur1 += f3;
                    cur2 += f5;
                }
            }
            base1 += f3;
            base2 += f5;
        }
    }

    if (n1 > 0) {
        int row = 0;
        for (int ii = 0; ii < n1; ii++) {
            int col = 0;
            for (int jj = 0; jj < n2; jj++) {
                int i0 = row + col;
                int i1 = row + col + 1;
                int i2 = row + col + n2 + 1;
                int i3 = row + col + n2 + 2;
                sub_4eee30(this, (int)arr[i0], (int)arr[i1], (int)arr[i2], (int)arr[i3]);
                col++;
            }
            row += n2 + 1;
        }
    }

    for (unsigned int ii = 0; ii < (unsigned int)count; ii++) {
        sub_4f54e0(arr[ii]);
    }
    sub_62ff26(arr);
}
