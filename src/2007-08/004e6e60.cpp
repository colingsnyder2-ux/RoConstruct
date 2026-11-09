// from server: 28% by colin
// roc 2007-08 004e6e60 unit: WedgeBuilder size: 977 bytes

extern "C" {
    int __stdcall sub_5b99f0(void*, void*);
    void* __cdecl sub_62ff32(unsigned int);
    void __cdecl sub_62ff26(void*);
    void __cdecl sub_62fc62(void*);
    void* __stdcall sub_501570();
    void* __stdcall sub_4f5360(void*, void*, void*, int);
    void __stdcall sub_4f54e0(void*);
    void __stdcall sub_4eee30(void*, int, int, int, int);
    int __stdcall InterlockedDecrement(int*);
}

struct WedgeBuilder {
    char pad0[4];
    int field4;
    void build(int a, int b, int c, int d, int e, int f, int g, int h, int i, int j, int k, int l, int m, int n, int o, int p, int q, int r, int s, int t, int u);
};

void WedgeBuilder::build(int a, int b, int c, int d, int e, int f, int g, int h, int i, int j, int k, int l, int m, int n, int o, int p, int q, int r, int s, int t, int u)
{
    char buf[0x88];
    int* arr;
    int rows, cols;
    int i2, j2;
    float fx, fy, fz;
    float dx, dy, dz;
    float stepx, stepy;
    float basex, basey, basez;
    float curx, cury, curz;
    float ustep, vstep;
    float u0, v0;
    int total;
    int idx;
    float* verts;
    int* faces;
    int nv, nf;
    int* tmp;
    int k2;

    sub_5b99f0(&field4, buf);

    rows = *(short*)((char*)&a + 0);
    cols = *(short*)((char*)&a + 2);

    fx = *(float*)((char*)&a + 0x28);
    fy = *(float*)((char*)&a + 0x2c);
    fz = *(float*)((char*)&a + 0x30);

    dx = *(float*)((char*)&a + 0x20) - *(float*)((char*)&a + 0x18);
    dy = *(float*)((char*)&a + 0x24) - *(float*)((char*)&a + 0x1c);

    stepx = dx / (float)(cols + 1);
    stepy = dy / (float)(rows + 1);

    ustep = (*(float*)((char*)&a + 0x38) - *(float*)((char*)&a + 0x34)) / (float)(cols + 1);
    vstep = (*(float*)((char*)&a + 0x3c) - *(float*)((char*)&a + 0x40)) / (float)(rows + 1);

    total = (rows + 1) * (cols + 1);
    verts = (float*)sub_62ff32(total * 4 * 4);

    basex = *(float*)((char*)&a + 0x18);
    basey = *(float*)((char*)&a + 0x1c);
    basez = *(float*)((char*)&a + 0x40);

    u0 = *(float*)((char*)&a + 0x34);
    v0 = *(float*)((char*)&a + 0x38);

    if (rows >= 0) {
        float* vp = verts;
        cury = basey;
        for (i2 = 0; i2 <= rows; i2++) {
            curx = basex;
            if (cols >= 0) {
                float* vp2 = vp;
                for (j2 = 0; j2 <= cols; j2++) {
                    float px = curx;
                    float py = cury;
                    float pz = basez;
                    float uu = u0;
                    float vv = v0;
                    float* pt = (float*)sub_501570();
                    if (pt[0] == fx && pt[1] == fy) {
                        px = *(float*)((char*)&a + 0x24);
                        py = *(float*)((char*)&a + 0x28);
                    }
                    vp2[0] = px;
                    vp2[1] = py;
                    vp2[2] = pz;
                    vp2[3] = 1.0f;
                    vp2[4] = uu;
                    vp2[5] = vv;
                    vp2[6] = 0.0f;
                    vp2[7] = 0.0f;
                    vp2[8] = 0.0f;
                    vp2[9] = 0.0f;
                    vp2[10] = 0.0f;
                    vp2[11] = 0.0f;
                    curx += stepx;
                    uu += ustep;
                    vp2 += 12;
                }
            }
            cury += stepy;
            v0 += vstep;
            vp += (cols + 1) * 12;
        }
    }

    nf = rows * cols;
    faces = (int*)sub_62ff32(nf * 4 * 4);

    if (rows > 0) {
        int* fp = faces;
        int rowbase = 0;
        for (i2 = 0; i2 < rows; i2++) {
            if (cols > 0) {
                int* fp2 = fp;
                int cbase = rowbase;
                for (j2 = 0; j2 < cols; j2++) {
                    int v0i = cbase;
                    int v1i = cbase + 1;
                    int v2i = cbase + cols + 1;
                    int v3i = cbase + cols + 2;
                    *fp2 = (int)sub_4f5360(verts, &verts[v0i*12], &verts[v1i*12], 1);
                    fp2++;
                    cbase++;
                }
            }
            rowbase += cols + 1;
            fp += cols;
        }
    }

    for (k2 = 0; k2 < rows; k2++) {
        sub_4f54e0((void*)faces[k2]);
    }

    sub_62ff26(faces);

    if (arr) {
        if (InterlockedDecrement(arr + 1) == 0) {
            int* node = (int*)arr[2];
            while (node) {
                (*(void(**)(void*))(*node))(node);
                int* next = (int*)node[1];
                sub_62fc62(node);
                node = next;
            }
            (*(void(**)(void*, int))(*arr))(arr, 1);
        }
    }
}
