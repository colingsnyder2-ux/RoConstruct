// from server: 69% by atomic.potato
struct Vec3 {
    float x;
    float y;
    float z;
};

extern "C" bool __cdecl sub_880f30(const Vec3* p);

bool __stdcall sub_005d87e0(float x, float y, float z, Vec3* out)
{
    Vec3 v;
    v.x = x;
    v.y = y;
    v.z = z;
    if (sub_880f30(&v)) {
        return false;
    }
    if (out) {
        *out = v;
    }
    return true;
}
