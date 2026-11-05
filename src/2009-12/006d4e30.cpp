// from server: 100% by atomic.potato
struct Vector3
{
    float x;
    float y;
    float z;
};

extern "C" Vector3* __cdecl getVector3();

struct AxisMoveTool
{
    Vector3* copyVector(Vector3*);
};

Vector3* AxisMoveTool::copyVector(Vector3* destination)
{
    Vector3* source = getVector3();
    destination->x = source->x;
    destination->y = source->y;
    destination->z = source->z;
    return destination;
}
