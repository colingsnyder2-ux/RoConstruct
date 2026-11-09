// from server: 29% by atomic.potato
struct Primitive {
    char pad0[0x24];
    float x;
    float y;
    float z;
    char pad1[0x24];
};

struct Vec3 {
    float x;
    float y;
    float z;
};

extern "C" void __stdcall sub_6eebf0(Vec3* out, Primitive* p);
extern "C" void __fastcall sub_5f3900(Primitive* self, void* src);

Primitive* __fastcall sub_6f0150(Primitive* self, Vec3* v) {
    Vec3 tmp;
    tmp.x = self->x / v->x;
    tmp.y = self->y / v->y;
    tmp.z = self->z / v->z;

    int ix = (int)tmp.x;
    int iy = (int)tmp.y;
    int iz = (int)tmp.z;

    Vec3 scaled;
    scaled.x = v->x * (float)ix;
    scaled.y = v->y * (float)iy;
    scaled.z = v->z * (float)iz;

    Vec3 out;
    sub_6eebf0(&out, self);
    sub_5f3900(self, &out);

    self->x = scaled.x;
    self->y = scaled.y;
    self->z = scaled.z;
    return self;
}
