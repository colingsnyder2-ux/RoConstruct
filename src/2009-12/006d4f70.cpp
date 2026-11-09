// from server: 100% by atomic.potato
struct Vector3
{
    float x;
    float y;
    float z;
};

extern "C" Vector3* __cdecl GetVector3();

struct AxisRotateTool
{
    Vector3* copy(Vector3*);
};

Vector3* AxisRotateTool::copy(Vector3* value)
{
    Vector3* source = GetVector3();
    value->x = source->x;
    value->y = source->y;
    value->z = source->z;
    return value;
}
