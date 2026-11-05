// from server: 27% by atomic.potato
struct Vec3 { float x, y, z; };

struct Sub1 {
    char pad0[0x14];
    float f14;
};

struct Sub2 {
    char pad0[0x30];
    Sub1* p34;
    char pad38[0x60];
    float f98;
};

struct Arg {
    char pad0[0xe8];
    float fx, fy, fz;
    char padf4[0x30];
    Sub2* p30;
};

extern "C" void __stdcall sub_972290(unsigned char a, const char* b);
extern "C" void __stdcall sub_7530d0();
extern "C" void __stdcall sub_954f20();

extern float g_b63190;
extern unsigned char g_e580b3;
extern void* g_e5809c;

struct BodyAngularVelocity {
    char pad0[0x134];
    int f134;
    float f140;
    float f144;
    float f148;
    float f14c;
    float f150;
    float f154;
    float f158;
    float f15c;
    float f160;
    float f164;
    void method(Arg* arg, Vec3* out);
};

void BodyAngularVelocity::method(Arg* arg, Vec3* out) {
    if (g_e580b3 != 0 && f134 == 0) {
        if (g_e5809c != 0) {
            unsigned char r = ((unsigned char (__stdcall*)(int, const char*, const char*))g_e5809c)(0x227, (const char*)0xbe7c38, (const char*)0xb500bc);
            if (r != 0) goto skip;
        }
        sub_972290(g_e580b3, (const char*)0xbe8460);
    }
skip:
    sub_7530d0();
    float dx = f150 - arg->fx;
    float dy = f154 - arg->fy;
    float dz = f158 - arg->fz;
    Sub2* s2 = arg->p30;
    float m = f140;
    dx *= m;
    dy *= m;
    dz *= m;
    float scale;
    if (s2->p34 != 0) {
        sub_954f20();
        scale = s2->p34->f14;
    } else {
        scale = s2->f98;
    }
    f160 = dy * scale;
    f164 = dz * scale;
    f15c = dx * scale;
    float nx = -f144;
    float ny = -f148;
    float nz = -f14c;
    float pz = f164;
    if (nz < pz) {
        if (pz < f14c) nz = f14c;
        else nz = pz;
    }
    float py = f160;
    if (ny < py) {
        if (py < f148) ny = f148;
        else ny = py;
    }
    float px = f15c;
    if (nx < px) {
        if (px < f144) nx = f144;
        else nx = px;
    }
    f15c = nx;
    f160 = ny;
    f164 = nz;
    out->x = f15c;
    out->y = f160;
    out->z = f164;
}
