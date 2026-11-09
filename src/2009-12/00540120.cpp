// from server: 71% by atomic.potato
struct Vector3
{
    float x;
    float y;
    float z;
};

extern "C" Vector3* __cdecl sub_0053f5c0(Vector3*);

Vector3* __cdecl sub_00540120(Vector3* result)
{
    Vector3* value = sub_0053f5c0(result);
    result->x = value->x;
    result->y = value->y;
    result->z = value->z;
    return result;
}
