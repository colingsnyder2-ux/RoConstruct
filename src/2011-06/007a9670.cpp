// from server: 31% by atomic.potato
struct Vec3 {
    float x;
    float y;
    float z;
};

struct PosObj {
    char pad[0x30];
    float x;
    float y;
    float z;
};

struct MidHolder {
    PosObj* obj;
};

struct InnerHolder {
    char pad[0xc];
    MidHolder* mh;
};

struct Self {
    char pad[0x18];
    InnerHolder* ih;
    void get(Vec3* out);
};

void Self::get(Vec3* out)
{
    InnerHolder* ih = this->ih;
    MidHolder* mh = ih->mh;
    PosObj* obj = mh->obj;
    out->x = 0.0f;
    out->y = 0.0f;
    out->z = 0.0f;
    if (obj != 0) {
        out->x = obj->x;
        out->y = obj->y;
        out->z = obj->z;
    }
}
