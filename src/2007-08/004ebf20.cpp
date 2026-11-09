// from server: 31% by colin
// roc 2007-08 004ebf20  unit: CylinderBuilder  size: 837 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 004ebf20

struct Vec3 {
    float x;
    float y;
    float z;
};

struct CylinderBuilder {
    char pad0[4];
    Vec3 m_v0;
    Vec3 m_v1;
    float m_f10;
    float m_f14;
    float m_f18;
    float m_f1c;
    float m_f20;
    float m_f24;
    float m_f28;
    float m_f2c;
    float m_f30;
    int m_i34;
    int m_i38;
    int m_i3c;
    void build(int a, int b, int c, int d, int e, int f, int g, int h, int i, int j, int k, int l, int m);
};

extern "C" void __cdecl sub_5b99d0(Vec3* dst, const Vec3* src);
extern "C" void* __cdecl sub_62ff32(unsigned int size);
extern "C" void __cdecl sub_62ff26(void* p);
extern "C" void* __cdecl sub_501570();
extern "C" void __cdecl sub_4eb600(Vec3* a, Vec3* b, Vec3* c, Vec3* d, Vec3* e, Vec3* f);
extern "C" void __cdecl sub_4f5360(void* a, void* b, void* c, int d);
extern "C" void __cdecl sub_4eee30(void* self, int a, int b, int c, int d);
extern "C" void __cdecl sub_4f54e0(void* p);

extern double g_795b48;

void CylinderBuilder::build(int a, int b, int c, int d, int e, int f, int g, int h, int i, int j, int k, int l, int m)
{
    Vec3 v0;
    Vec3 v1;
    sub_5b99d0(&v0, &m_v0);
    float ax = v0.x < 0 ? -v0.x : v0.x;
    float ay = v0.y < 0 ? -v0.y : v0.y;
    float az = v0.z < 0 ? -v0.z : v0.z;

    int n0 = m_i38 + 1;
    int n1 = m_i3c + 1;
    int total = n0 * n1;

    float f0 = (m_f18 - m_f10) / (float)n0;
    float f1 = (m_f1c - m_f14) / (float)n1;
    float f2 = m_f2c / ax;
    float f3 = m_f30 / ay;
    float f4 = m_f30 / az;

    void* buf = sub_62ff32(total * 4);
    void** arr = (void**)buf;

    int i0 = 0;
    int i1 = 0;
    float f5 = m_f10;
    float f6 = m_f24;
    float f7 = m_f14;
    float f8 = m_f28;

    if (m_i38 >= 0) {
        float f9 = 0.0f;
        int idx = 0;
        if (m_i3c >= 0) {
            int off = m_i34 * 4;
            void** p = arr;
            void** q = (void**)((char*)&v0 + off);
            do {
                float f10 = v1.y;
                float f11 = f7;
                float f12 = m_f20;
                float f13 = f9;
                float f14 = f9;
                v0.z = f6;
                v1.x = f8;
                v0.x = f13;
                v0.y = f14;
                v1.z = 1.0f;
                sub_4eb600(&v0, &v1, &v0, &v1, &v0, &v1);
                void* r = sub_501570();
                float* rf = (float*)r;
                if (rf[0] == m_f2c && rf[1] == m_f30) {
                    v0.x = m_f24;
                    v0.y = m_f28;
                }
                float t = v0.x * (float)g_795b48;
                float u = v0.y * (float)g_795b48;
                sub_5b99d0(&v0, &v1);
                sub_5b99d0(&v1, &v0);
                sub_4f5360(&v0, &v1, &v0, 1);
                *p = r;
                f6 += f2;
                p++;
                idx++;
                f8 += f3;
                f9 = 0.0f;
            } while (idx <= m_i3c);
        }
        f7 += f1;
        i0++;
        f5 += f0;
        f6 = m_f24;
        f8 = m_f28;
    }

    if (m_i38 > 0) {
        int rows = m_i38;
        void** p = arr;
        void** q = (void**)((char*)arr + m_i3c * 4 + 8);
        do {
            if (m_i3c > 0) {
                int cols = m_i3c;
                void** pp = q;
                void** qq = p;
                do {
                    void* a0 = pp[0];
                    void* a1 = pp[-1];
                    void* b0 = qq[0];
                    void* b1 = qq[1];
                    sub_4eee30(this, (int)b1, (int)b0, (int)a1, (int)a0);
                    pp++;
                    qq++;
                    cols--;
                } while (cols != 0);
            }
            q = (void**)((char*)q + m_i3c * 4 + 4);
            p = (void**)((char*)p + m_i3c * 4 + 4);
            rows--;
        } while (rows != 0);
    }

    unsigned int cnt = (unsigned int)total;
    if (cnt > 0) {
        unsigned int n = 0;
        do {
            sub_4f54e0(arr[n]);
            n++;
        } while (n < cnt);
    }
    sub_62ff26(arr);
}
