// from server: 36% by colin
// roc 2007-08 004e54f0  unit: WedgeBuilder  size: 821 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 004e54f0

extern "C" void __cdecl sub_5B99B0(void*, void*);
extern "C" void* __cdecl sub_62FF32(unsigned int);
extern "C" void* __cdecl sub_501570();
extern "C" void __cdecl sub_4F5360(void*, void*, void*, int);
extern "C" void __cdecl sub_4EEE30(void*, int, int, int, int);
extern "C" void __cdecl sub_4F54E0(void*);
extern "C" void __cdecl sub_62FF26(void*);

struct WedgeBuilder {
    void build(int a, int b, int c, int d, int e, int f, int g, int h, int i, int j, int k, int l, int m);
};

void WedgeBuilder::build(int a, int b, int c, int d, int e, int f, int g, int h, int i, int j, int k, int l, int m)
{
    char buf[0x84];
    int* verts;
    int nx, ny;
    int total;
    float fx, fy, fz;
    float dx, dy, dz;
    float ux, uy, uz;
    float sx, sy, sz;
    float step_x, step_y, step_z;
    float start_x, start_y, start_z;
    float cur_x, cur_y, cur_z;
    int i2, j2;
    int* p;
    int* q;
    int idx;

    sub_5B99B0(buf, (char*)this + 4);

    nx = *(short*)((char*)&m + 4);
    ny = *(short*)((char*)&m + 6);

    total = (nx + 1) * (ny + 1);

    fx = *(float*)((char*)&a + 4) - *(float*)&a;
    fy = *(float*)((char*)&a + 8) - *(float*)((char*)&a + 4);
    fz = *(float*)((char*)&a + 12) - *(float*)((char*)&a + 8);

    step_x = fx / (float)nx;
    step_y = fy / (float)ny;
    step_z = fz / (float)(nx + 1);

    verts = (int*)sub_62FF32(total * 4);

    start_x = *(float*)&a;
    start_y = *(float*)((char*)&a + 4);
    start_z = *(float*)((char*)&a + 8);

    cur_x = start_x;
    cur_y = start_y;
    cur_z = start_z;

    if (nx >= 0) {
        for (i2 = 0; i2 <= nx; i2++) {
            if (ny >= 0) {
                for (j2 = 0; j2 <= ny; j2++) {
                    float u = cur_x;
                    float v = cur_y;
                    float w = cur_z;

                    float* pv = (float*)sub_501570();
                    if (pv[0] == *(float*)((char*)&a + 12) && pv[1] == *(float*)((char*)&a + 16)) {
                        u = *(float*)((char*)&a + 20);
                        v = *(float*)((char*)&a + 24);
                    }

                    float tu = u * 1.0f;
                    float tv = v * 1.0f;

                    sub_5B99B0(&tu, &tu);
                    sub_5B99B0(&tv, &tv);

                    sub_4F5360(&tu, &tv, &w, 1);

                    *verts = (int)sub_501570();
                    verts++;

                    cur_y += step_y;
                }
            }
            cur_x += step_x;
            cur_z += step_z;
        }
    }

    if (total > 0) {
        p = verts;
        q = verts + ny + 2;
        for (i2 = 0; i2 < total; i2++) {
            if (ny > 0) {
                for (j2 = 0; j2 < ny; j2++) {
                    sub_4EEE30((void*)this, p[0], p[1], q[0], q[1]);
                    p++;
                    q++;
                }
            }
            p += ny + 1;
            q += ny + 1;
        }
    }

    for (i2 = 0; i2 < total; i2++) {
        sub_4F54E0((void*)verts[i2]);
    }

    sub_62FF26(verts);
}
