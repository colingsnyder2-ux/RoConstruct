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
    double sizeA = (a->size.x + a->size.y + a->size.z) / 3.0;
    double sizeB = (b->size.x + b->size.y + b->size.z) / 3.0;
    return (1.2 - a->distance) * sizeA > (1.2 - b->distance) * sizeB;
}
