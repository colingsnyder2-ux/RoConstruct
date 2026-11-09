// from server: 73% by atomic.potato
struct Vec3 { float x, y, z; };

extern "C" Vec3* __stdcall copy_vec3(Vec3* dst, const Vec3* src);

struct Ray {
    Vec3 origin;
    Vec3 direction;
    Ray* __cdecl set(const Ray* other);
};

Ray* Ray::set(const Ray* other) {
    copy_vec3(&origin, &other->origin);
    copy_vec3(&direction, &other->direction);
    copy_vec3((Vec3*)((char*)this + 8), (Vec3*)((char*)other + 8));
    return this;
}
