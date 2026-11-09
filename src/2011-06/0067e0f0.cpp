// from server: 38% by atomic.potato
struct Vec3 {
    float x, y, z;
};

struct Joint {
    char pad[0x24];
    Vec3 m_v;
};

struct Helper {
    void copyFrom(void* src);
};

extern "C" void* __cdecl sub_541450();

void Helper::copyFrom(void* src)
{
    *(Vec3*)this = *(Vec3*)src;
}

Joint* __stdcall sub_67e0f0(Joint* self, void* arg)
{
    Vec3 v;
    v.x = 0.0f;
    v.y = *(float*)0xa75b68;
    v.z = 0.0f;
    void* p = sub_541450();
    ((Helper*)self)->copyFrom(p);
    self->m_v = v;
    return self;
}
