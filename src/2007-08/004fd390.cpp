// from server: 100% by EspClaude
// from server: 86% by EspClaude
// roc 2007-08 004fd390  AggregateChunk sort predicate: (1.2 - c) * average(size) descending
struct Vector3 {
    float x, y, z;
};

struct AggregateChunk {
    char pad0[0xc];
    float distance;
    char pad10[0x30];
    Vector3 size;
};

bool comparePriority(const AggregateChunk* a, const AggregateChunk* b)
{
    const Vector3& sa = a->size;
    const Vector3& sb = b->size;
    double sizeA = (sa.x + sa.y + sa.z) / 3.0;
    double sizeB = (sb.x + sb.y + sb.z) / 3.0;
    return (1.2 - a->distance) * sizeA > (1.2 - b->distance) * sizeB;
}
