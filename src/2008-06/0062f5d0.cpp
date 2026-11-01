// from server: 100% by king_originala
struct Vector3 {
    float x, y, z;
};

struct S {
    char padding[8];
    int offset;
    Vector3 get(void* object);
};

Vector3 S::get(void* object)
{
    char* base = object ? static_cast<char*>(object) - 20 : 0;
    const float* source = reinterpret_cast<const float*>(base + offset);
    Vector3 result;
    result.x = source[0];
    result.y = source[1];
    result.z = source[2];
    return result;
}
