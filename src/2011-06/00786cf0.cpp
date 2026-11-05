// from server: 100% by atomic.potato
struct Vector3
{
    float x;
    float y;
    float z;
};

extern "C" Vector3* __cdecl sub_53F9F0();

struct AxisMoveTool
{
    Vector3* getValue(Vector3*);
};

Vector3* AxisMoveTool::getValue(Vector3* value)
{
    Vector3* source = sub_53F9F0();
    value->x = source->x;
    value->y = source->y;
    value->z = source->z;
    return value;
}
