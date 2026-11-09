// from server: 51% by colin
struct Name {
    void* p;
};

struct PartInstance {
    char pad[0x64];
    void* prim;
};

struct Explosion {
    char pad0[0x100];
    float field100;
    float field104;
    float field108;
    float field10c;
    float field110;
    char pad114[0x48];
    int count;
    void* items;

    void doBlast(int arg);
};

extern float g_7bd940;
extern float g_797e9c;
extern float g_8bd12c;
extern float g_8bd130;
extern float g_8bd134;
extern int g_8bd138;
extern float g_8bfbe8;
extern float g_8bfbec;
extern float g_8bfbf0;
extern int g_8bfbf4;

extern "C" void* __stdcall sub_57adb0(void*);
extern "C" void* __stdcall sub_573d40(void*);
extern "C" void* __stdcall sub_573d60(void*);
extern "C" void* __stdcall sub_530100(void*);
extern "C" void* __stdcall sub_5a91c0(void*);
extern "C" void* __stdcall sub_5cf030(void*, void*);
extern "C" int __stdcall sub_608650();
extern "C" void* __stdcall sub_61a510(void*);

struct ExplosionVtbl {
    void* pad0;
    void* pad1;
    void* pad2;
    float (__stdcall* getRadius)(void*);
};

struct Explosion2 {
    ExplosionVtbl* vtbl;
    char pad[0x60];
    PartInstance* part;
};

void Explosion::doBlast(int arg)
{
    if (field110 == 0.0f)
        return;

    void* list = sub_57adb0(this);
    int i = 0;
    if (arg <= 0)
        return;

    while (i < arg) {
        Explosion2* e = (Explosion2*)((void**)list)[i];
        float r = e->vtbl->getRadius(e);
        if (r == field10c * 2.0f) {
            void* n = sub_573d40(e);
            sub_573d60(n);

            PartInstance* p = e->part;
            sub_530100(p);

            float dx = *(float*)((char*)p + 0xa8) - field100;
            float dy = *(float*)((char*)p + 0xac) - field104;
            float dz = *(float*)((char*)p + 0xb0) - field108;

            float nx, ny, nz;
            if (g_8bd138 & 1) {
                nx = g_8bd12c;
                ny = g_8bd130;
                nz = g_8bd134;
            } else {
                g_8bd138 |= 1;
                g_8bd12c = 0.0f;
                g_8bd130 = 0.0f;
                g_8bd134 = 0.0f;
                nx = 0.0f;
                ny = 0.0f;
                nz = 0.0f;
            }

            if (nx == dx && ny == dy && nz == dz) {
                if (g_8bfbf4 & 1) {
                    nx = g_8bfbe8;
                    ny = g_8bfbec;
                    nz = g_8bfbf0;
                } else {
                    g_8bfbf4 |= 1;
                    g_8bfbe8 = 0.0f;
                    g_8bfbec = 1.0f;
                    g_8bfbf0 = 0.0f;
                    nx = 0.0f;
                    ny = 1.0f;
                    nz = 0.0f;
                }
            } else {
                float len = dx*dx + dy*dy + dz*dz;
                len = 1.0f / len;
                nx = dx * len;
                ny = dy * len;
                nz = dz * len;
            }

            float vx = nx;
            float vy = ny;
            float vz = nz;

            float rr = e->vtbl->getRadius(e);
            float f1 = rr * rr;
            float f2 = field110 * vx;
            float f3 = field110 * vy;
            float f4 = field110 * vz;
            float f5 = f2 * g_7bd940;
            float f6 = f3 * g_7bd940;
            float f7 = f4 * g_7bd940;

            int n2 = sub_608650();
            float fn = (float)n2;
            float ax = f5 * fn;
            float ay = f6 * fn;
            float az = f7 * fn;

            sub_5a91c0(e);

            PartInstance* p2 = e->part;
            sub_530100(p2);
            void* prim = *(void**)((char*)p2 + 4);
            void* prim2 = *(void**)((char*)prim + 0x20);
            if (prim2) {
                sub_5cf030((char*)p2 + 0xa8, &ax);
            }

            float s = g_797e9c;
            float bx = ax * s;
            float by = ay * s;
            float bz = az * s;

            void* prim3 = *(void**)((char*)e->part + 4);
            void* prim4 = *(void**)((char*)prim3 + 0x20);
            if (prim4) {
                if (*(char*)((char*)prim4 + 4)) {
                    sub_61a510(prim4);
                }
                *(float*)((char*)prim4 + 0x8c) += bx;
                *(float*)((char*)prim4 + 0x90) += by;
                *(float*)((char*)prim4 + 0x94) += bz;
            }
        }
        i++;
    }
}
