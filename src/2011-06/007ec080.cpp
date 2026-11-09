// from server: 54% by atomic.potato
struct Vec3 { float x, y, z; };

extern "C" Vec3* __cdecl G3D_Sphere_00542780();

struct Climbing {
    char pad0[0x54];
    Vec3 v54;
    Vec3 v60;
    Vec3 v6c;
    Vec3 v78;
    float f84;
    void* ctor(void* a, void* b);
};

void* Climbing::ctor(void* a, void* b)
{
    G3D_Sphere_00542780();
    *(int*)this = 0xabed38;
    *(int*)((char*)this + 4) = 0xabed2c;
    v54 = *G3D_Sphere_00542780();
    v60 = *G3D_Sphere_00542780();
    v6c = *G3D_Sphere_00542780();
    v78 = *G3D_Sphere_00542780();
    f84 = 0.0f;

    return this;
}
