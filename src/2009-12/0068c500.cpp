// from server: 97% by atomic.potato
struct Vec3 { float x, y, z; };

extern "C" Vec3* __stdcall sub_7830A0(Vec3* out, const float* in);

struct ArchiveBinder {
    char pad[0x124];
    float f124;
    float f128;
    float f12c;
    void sub_68C500(const float* in);
};

void ArchiveBinder::sub_68C500(const float* in) {
    Vec3 tmp;
    Vec3* r = sub_7830A0(&tmp, in);
    f124 = r->x;
    f128 = r->y;
    f12c = r->z;
}
