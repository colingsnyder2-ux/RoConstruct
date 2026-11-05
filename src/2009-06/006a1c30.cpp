// from server: 40% by atomic.potato
struct CString {
    char pad[0x1c];
};

struct Vec3 {
    float x, y, z;
};

struct Mat4 {
    float m[16];
};

struct CFrame {
    float r[12];
};

extern "C" {
    void* __stdcall sub_670F10();
    void* __stdcall sub_576430();
    void* __stdcall sub_578850(int, int, int);
    void* __stdcall sub_64B390(void*, void*);
    void* __stdcall sub_719EC0(float);
    void* __stdcall sub_52DB40(void*, void*, void*);
    void* __stdcall sub_6626E0(void*, void*, int, int, double, void*, void*);
    void* __stdcall sub_89E510(void*, void*, void*);
    void* __stdcall sub_89E4C4(void*);
    void* __stdcall sub_8E9688();
    double __cdecl sqrt(double);
}

extern float g_8BAD4C;
extern double g_8BA2F0;
extern float g_8BA73C;
extern float g_8BE838;
extern double g_8E9680;

struct RBX_VehicleSeat {
    char pad0[0x70];
    void* field70;
    void __thiscall method(void* arg);
};

void RBX_VehicleSeat::method(void* arg) {
    char buf[0x98];
    void* p = arg;
    void** vtbl = *(void***)p;
    void (*getPos)(void*, void*) = (void (*)(void*, void*))vtbl[4];
    getPos(p, buf + 0x3c);
    float a = *(float*)(buf + 0x44) + *(float*)(buf + 0x3c);
    float b = *(float*)(buf + 0x48) + *(float*)(buf + 0x40);
    float c = a * g_8BAD4C;
    float d = b * g_8BAD4C;
    float e = (float)(c + g_8BA2F0);
    void* obj = sub_670F10();
    float* v = (float*)((char*)obj + 0x30);
    float len = v[0]*v[0] + v[1]*v[1] + v[2]*v[2];
    len = (float)sqrt(len);
    float f = g_8BA73C;
    float g = len;
    float h;
    if (f < g) {
        h = g;
    } else {
        h = f;
    }
    float i = h * g_8BE838;
    float j = i * g_8BAD4C;
    float k = j;
    float l = e + k;
    float m = d + k;
    float n = c - k;
    float o = d - k;
    float p1 = l;
    float p2 = m;
    float p3 = n;
    float p4 = o;
    void* q = sub_576430();
    float r = *(float*)q;
    float s = *(float*)((char*)q + 4);
    float t = *(float*)((char*)q + 8);
    float u = 1.0f;
    sub_52DB40(buf + 0x1c, buf + 0x14, buf + 0x5c);
    void** vtbl2 = *(void***)p;
    void (*fn2)(void*, void*, void*) = (void (*)(void*, void*, void*))vtbl2[11];
    fn2(p, buf + 0x5c, buf + 0x24);
    void* w = sub_719EC0(p1);
    *(void**)(buf + 0x0c) = w;
    void* x = sub_64B390(buf + 0x5c, buf + 0x08);
    sub_89E510(buf + 0x84, (void*)0x8E9688, x);
    *(int*)(buf + 0x9c) = 0;
    sub_89E4C4(buf + 0x5c);
    *(unsigned char*)(buf + 0x9c) = 2;
    void* y = sub_576430();
    float z1 = *(float*)y;
    float z2 = *(float*)((char*)y + 4);
    float z3 = *(float*)((char*)y + 8);
    float z4 = 1.0f;
    void* aa = sub_578850(2, 0, 0);
    double bb = g_8E9680;
    void* cc = sub_6626E0(buf + 0x3c, buf + 0x58, 4, 1, bb, buf + 0x5c, aa);
    void** vtbl3 = *(void***)((char*)p + 0x34);
    void (*fn3)(void*, void*, void*) = (void (*)(void*, void*, void*))vtbl3[0];
    fn3(p, buf + 0x30, buf + 0x98);
    *(int*)(buf + 0x9c) = -1;
    sub_89E4C4(buf + 0x78);
}
