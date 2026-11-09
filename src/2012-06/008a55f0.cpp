// from server: 100% by atomic.potato
struct Vector3
{
    float x;
    float y;
    float z;
};

extern "C" Vector3* __cdecl sub_62bbd0();

Vector3* __stdcall sub_8a55f0(Vector3* result)
{
    Vector3* value = sub_62bbd0();
    result->x = value->x;
    result->y = value->y;
    result->z = value->z;
    return result;
}
