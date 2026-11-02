// from server: 14% by Intel
struct VBlockMesh {
    int f();
};

extern "C" void __stdcall sub_414DA0();

int VBlockMesh::f() {
    struct Vec3 { float x, y, z; };
    Vec3* v = reinterpret_cast<Vec3*>(reinterpret_cast<char*>(this) + 0x8C);
    Vec3* arg = reinterpret_cast<Vec3*>(reinterpret_cast<char*>(this) + 0x4);

    if (v->x < arg->x || v->x != v->x || arg->x != arg->x)
        goto update;
    if (v->y < arg->y || v->y != v->y || arg->y != arg->y)
        goto update;
    if (v->z < arg->z || v->z != v->z || arg->z != arg->z)
        goto update;
    return 0;

update:
    v->x = arg->x;
    v->y = arg->y;
    v->z = arg->z;
    *reinterpret_cast<int*>(reinterpret_cast<char*>(this) + 0x4) = 0xE4E9C0;
    sub_414DA0();
    return 0;
}
