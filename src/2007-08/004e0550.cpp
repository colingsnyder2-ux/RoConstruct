// from server: 22% by colin
// roc 2007-08 004e0550  unit: RBX::Render::Mesh::Level  size: 816 bytes

extern "C" double __stdcall ceil(double);
extern "C" float __stdcall fabsf(float);

struct Vec3 {
    float x;
    float y;
    float z;
};

struct MeshLevel {
    int pad0;
    int pad4;
    int pad8;
    int padC;
    unsigned int flags;
    int getOrientedBoundingBox(const Vec3* dirs, Vec3* out, int count, int mode, int a, int b, int c);
};

struct MeshHelper {
    int pad0[7];
    float f18;
    float f1c;
};

extern "C" int __stdcall sub_5b99f0(void* out, void* in);
extern "C" void* __stdcall sub_50b010(void* out, void* in);
extern "C" float __stdcall sub_4de980(int mode);
extern "C" void __stdcall sub_4deeb0(void* self, void* a, void* b, void* c, void* d);
extern "C" void __stdcall sub_4e0180(void* a, void* b, void* c, void* d, void* e, void* f, void* g);

extern float g_795b48;
extern float g_787050;
extern float g_797e9c;
extern float g_79f340;
extern float g_79f348;

int MeshLevel::getOrientedBoundingBox(const Vec3* dirs, Vec3* out, int count, int mode, int a, int b, int c)
{
    unsigned int ebx = (this->flags >> 12) & 7;
    Vec3 local;
    sub_5b99f0(&local, &this->pad4);

    float fabsX = fabsf(local.x);
    float fabsY = fabsf(local.y);
    float fabsZ = fabsf(local.z);

    int ebp;
    int esi;

    if (mode == 0 && fabsX == fabsZ) {
        esi = 0;
    } else {
        esi = 1;
    }

    if (mode == 0 && ebx != 0) {
        float f = (esi == 0) ? fabsX : fabsY;
        f = (float)(f * g_795b48);
        f = (float)ceil((double)f);
        ebp = (int)f;
    } else {
        ebp = 1;
    }

    short arr[2];
    arr[0] = 0;
    arr[1] = 0;

    short v = *(short*)((char*)&local + esi * 2);
    int q = (int)v / ebp;
    int one = 1;
    unsigned short qq = (unsigned short)q;
    int qv = qq;
    if ((short)qq <= 1) {
        qv = one;
    }
    arr[esi] = (short)qv;

    Vec3 tmp;
    sub_50b010(&tmp, &local);
    float nx = -tmp.x;
    float ny = -tmp.y;
    float nz = tmp.z;

    float f0 = 0.0f;
    float r28 = f0, r2c = f0, r1c = f0, r20 = f0;

    if (mode == 0) {
        if (ebx == 0) {
            r28 = g_787050;
            r2c = g_797e9c;
            if (esi == 0) {
                r1c = r28;
                r20 = r2c;
            } else {
                r1c = r2c;
                r20 = r28;
            }
        } else {
            r2c = sub_4de980(ebx);
            r1c = local.x * 2.0f;
            r20 = g_797e9c;
            if (esi == 1) {
                r1c = -r1c;
            }
        }
    } else if (mode == 1) {
        MeshHelper* h = (MeshHelper*)&this->pad0;
        r2c = h->f1c;
        r1c = h->f18;
        r20 = -h->f1c;
    } else if (mode == 2) {
        r28 = f0;
        r2c = f0;
        r1c = f0;
        r20 = f0;
    }

    int i = 0;
    if (ebp > 0) {
        while (i < ebp) {
            if (i == ebp - 1) {
                float f = (esi == 0) ? fabsX : fabsY;
                float fv = f;
                float* p30 = (float*)((char*)&r28 + esi * 4);
                *p30 = fv;
                if (mode == 0 && r28 != 0.0f) {
                    float d = fv - r1c;
                    d = (float)(d * g_79f348);
                    d = d * r1c;
                    r1c = d;
                }
            } else {
                float f = r1c + (float)g_79f340;
                float* p30 = (float*)((char*)&r28 + esi * 4);
                *p30 = f;
            }

            float args[2];
            args[0] = r1c;
            args[1] = r20;

            Vec3 v1;
            v1.x = r28;
            v1.y = r2c;

            Vec3 v2;
            v2.x = r1c;
            v2.y = r20;

            sub_4e0180(&v1, &v2, &local, &tmp, &args, &out[i], 0);

            Vec3 v3;
            v3.x = r1c;
            v3.y = r20;
            sub_4deeb0(this, &v3, &out[i], &local, 0);

            r1c = *(float*)((char*)&r28 + esi * 4);
            i++;
        }
    }

    return 0;
}
