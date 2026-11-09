// from server: 48% by atomic.potato
struct Vec3 { float x, y, z; };

struct Inner {
    char pad[0xc8];
    int field_c8;
};

struct Outer {
    char pad[0xc8];
    Inner inner;
    void method(Vec3* v);
};

struct Copier {
    void copy9(void* src);
};

struct Sub {
    void sub_6ac130(Outer* self, Vec3* v);
};

void Outer::method(Vec3* v) {
    Inner tmp;
    ((Copier*)&tmp)->copy9(&inner);
    Vec3 local;
    local.x = v->x;
    local.y = v->y;
    local.z = v->z;
    ((Sub*)this)->sub_6ac130(this, &local);
}
