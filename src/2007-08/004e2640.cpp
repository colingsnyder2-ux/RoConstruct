// from server: 37% by colin
// roc 2007-08 004e2640  unit: PBBBuilder  size: 837 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 004e2640

extern "C" {
    void __cdecl sub_5b9a10(float* dst, float* src);
    void* __cdecl sub_62ff32(int size);
    void __cdecl sub_62ff26(void* p);
    float* __cdecl sub_501570();
    void* __cdecl sub_4f5360(float* a, float* b, float* c, int d);
    void __cdecl sub_4f54e0(void* p);
    void __cdecl sub_4eee30(void* self, int a, int b, int c, int d);
}

struct PBBBuilder {
    void func(
        float x0, float y0, float z0,
        float x1, float y1, float z1,
        float u0, float v0, float u1, float v1,
        short a, short b, int c, int d);
};

void PBBBuilder::func(
    float x0, float y0, float z0,
    float x1, float y1, float z1,
    float u0, float v0, float u1, float v1,
    short a, short b, int c, int d)
{
    float tmp[4];
    sub_5b9a10(tmp, (float*)((char*)this + 4));

    float f0 = tmp[0];
    if (f0 < 0.0f) f0 = -f0;
    float f1 = tmp[1];
    if (f1 < 0.0f) f1 = -f1;

    int n = a;
    int m = b;
    int total = (n + 1) * (m + 1);

    float stepx = (x1 - x0) / (float)n;
    float stepy = (y1 - y0) / (float)m;
    float stepz = (z1 - z0) / (float)n;

    float ustep = (u1 - u0) / (float)n;
    float vstep = (v1 - v0) / (float)m;

    float* verts = (float*)sub_62ff32(total * 4 * 4);

    float px = x0;
    float py = y0;
    float pz = z0;

    float uu = u0;
    float vv = v0;

    float* vp = verts;

    for (int i = 0; i <= n; i++) {
        float cx = px;
        float cy = py;
        float cz = pz;
        float cu = uu;
        float cv = vv;

        for (int j = 0; j <= m; j++) {
            float* q = sub_501570();
            if (q[0] == u0 && q[1] == v0) {
                cx = x0;
                cy = y0;
            }

            float tx = cx * 0.5f;
            float ty = cy * 0.5f;

            float t1[2];
            float t2[2];
            sub_5b9a10(t1, &tx);
            sub_5b9a10(t2, &cu);

            void* v = sub_4f5360(t1, t2, &cz, 1);
            *vp = (float)(int)v;
            vp++;

            cz += stepz;
            cv += vstep;
            cx += stepx;
            cy += stepy;
        }

        pz += stepz;
        py += stepy;
        px += stepx;
        uu += ustep;
        vv += vstep;
    }

    if (m > 0) {
        float* row0 = verts;
        float* row1 = verts + (m + 1);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                sub_4eee30(this, (int)row0[j], (int)row0[j+1], (int)row1[j], (int)row1[j+1]);
            }
            row0 += (m + 1);
            row1 += (m + 1);
        }
    }

    for (unsigned int k = 0; k < (unsigned int)total; k++) {
        sub_4f54e0((void*)(int)verts[k]);
    }

    sub_62ff26(verts);
}
