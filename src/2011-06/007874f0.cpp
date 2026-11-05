// from server: 100% by atomic.potato
struct Vector3
{
    float x;
    float y;
    float z;
};

extern "C" Vector3* __cdecl sub_53F8A0();

struct AxisRotateTool
{
    Vector3* f(Vector3*);
};

Vector3* AxisRotateTool::f(Vector3* destination)
{
    Vector3* result = sub_53F8A0();
    destination->x = result->x;
    destination->y = result->y;
    destination->z = result->z;
    return destination;
}
