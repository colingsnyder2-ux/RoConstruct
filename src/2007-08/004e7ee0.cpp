// from server: 40% by colin
// roc 2007-08 004e7ee0  unit: TorsoBuilder  size: 853 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 004e7ee0

extern "C" {
    void __cdecl sub_5b9970(float* dst, float* src);
    void* __cdecl sub_62ff32(int size);
    void __cdecl sub_62ff26(void* p);
    void __cdecl sub_4f54e0(void* p);
    void* __cdecl sub_4f5360(void* a, void* b, void* c, int d);
    void* __cdecl sub_501570();
    void __cdecl sub_4eee30(void* self, int a, int b, int c, int d);
}

struct TorsoBuilder {
    char pad0[4];
    int field4;
    void build(
        void* callback,
        float x0, float y0,
        float x1, float y1,
        float z0, float z1,
        float u0, float v0,
        float u1, float v1,
        short nx, short ny,
        void* out);
};

void TorsoBuilder::build(
    void* callback,
    float x0, float y0,
    float x1, float y1,
    float z0, float z1,
    float u0, float v0,
    float u1, float v1,
    short nx, short ny,
    void* out)
{
    float tmp[4];
    sub_5b9970(tmp, (float*)&this->field4);

    float ax = tmp[1];
    if (ax < 0.0f) ax = -ax;
    float ay = tmp[2];
    if (ay < 0.0f) ay = -ay;
    float az = tmp[3];
    if (az < 0.0f) az = -az;

    int n0 = nx + 1;
    int n1 = ny + 1;
    int total = n0 * n1;

    float dx = (x1 - x0) / (float)nx;
    float dy = (y1 - y0) / (float)ny;
    float du = (u1 - u0) / (float)nx;
    float dv = (v1 - v0) / (float)ny;

    float* verts = (float*)sub_62ff32(total * 4);

    float curx = x0;
    float cury = y0;
    float curu = u0;
    float curv = v0;

    int idx = 0;
    for (int i = 0; i <= nx; i++) {
        float px = curx;
        float py = cury;
        float pu = curu;
        float pv = curv;
        for (int j = 0; j <= ny; j++) {
            float pos[3];
            pos[0] = px;
            pos[1] = py;
            pos[2] = z0;
            float uv[2];
            uv[0] = pu;
            uv[1] = pv;
            float col[4];
            col[0] = 1.0f;
            col[1] = 1.0f;
            col[2] = 1.0f;
            col[3] = 1.0f;
            ((void (__cdecl*)(void*, float*, float*, float*, float*))callback)(out, pos, uv, col, tmp);
            void* r = sub_501570();
            float* rf = (float*)r;
            if (rf[0] == z0 && rf[1] == z1) {
                pos[0] = u0;
                pos[1] = v0;
            }
            float uu = pos[0] * 0.5f;
            float vv = pos[1] * 0.5f;
            float uv2[2];
            uv2[0] = uu;
            uv2[1] = vv;
            float uv3[2];
            sub_5b9970(uv3, uv2);
            float uv4[2];
            sub_5b9970(uv4, uv3);
            verts[idx] = (float)(int)sub_4f5360(uv4, uv3, uv2, 1);
            idx++;
            px += dx;
            pu += du;
        }
        curx += dy;
        curu += dv;
    }

    for (int i = 0; i < nx; i++) {
        for (int j = 0; j < ny; j++) {
            int a = i * j + n1;
            int b = a + 1;
            int c = a + n1;
            int d = c + 1;
            sub_4eee30(this, (int)verts[a], (int)verts[b], (int)verts[c], (int)verts[d]);
        }
    }

    for (int i = 0; i < total; i++) {
        sub_4f54e0((void*)(int)verts[i]);
    }
    sub_62ff26(verts);
}
