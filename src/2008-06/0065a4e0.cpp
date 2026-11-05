// from server: 100% by coldek
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
struct Vector3int32 {
    int x, y, z;
    Vector3int32() : x(0), y(0), z(0) {}
    Vector3int32(int a, int b, int c) : x(a), y(b), z(c) {}
};
struct Extents { float low[3]; float high[3]; };
struct Primitive {
    char reserved0[0x68];
    Vector3int32 oldSpatialMin;
    Vector3int32 oldSpatialMax;
    const Extents& getFastFuzzyExtents();
    int isActive() const;
};
int toGrid(float, int);
void onAddNode(Primitive*, int);
__declspec(noinline) void calculateBounds(int level, const Extents& e, Vector3int32* min, Vector3int32* max)
{
    min->x = toGrid(e.low[0], level); min->y = toGrid(e.low[1], level); min->z = toGrid(e.low[2], level);
    max->x = toGrid(e.high[0], level); max->y = toGrid(e.high[1], level); max->z = toGrid(e.high[2], level);
}
__declspec(noinline) void computeMinMax(int* level, Primitive* p, const Extents& extents, Vector3int32* min, Vector3int32* max)
{
    *level = 0;
    calculateBounds(0, extents, min, max);
    while ((max->x - min->x + 1) * (max->y - min->y + 1) * (max->z - min->z + 1) > 100 && !p->isActive()) {
        ++*level;
        calculateBounds(*level, extents, min, max);
    }
}
struct SpatialHash {
    void addNode(int level, Primitive* p, const Vector3int32& grid);
    void onPrimitiveAdded(Primitive* p);
};
__declspec(noinline) void SpatialHash::addNode(int level, Primitive* p, const Vector3int32& grid) { onAddNode(p, grid.x + grid.y + grid.z + level); }

void SpatialHash::onPrimitiveAdded(Primitive* p)
{
    Vector3int32 newMin;
    Vector3int32 newMax;
    int level;
    computeMinMax(&level, p, p->getFastFuzzyExtents(), &newMin, &newMax);
    p->oldSpatialMin = newMin;
    p->oldSpatialMax = newMax;
    for (int i = newMin.x; i <= newMax.x; i++)
        for (int j = newMin.y; j <= newMax.y; j++)
            for (int k = newMin.z; k <= newMax.z; k++)
                addNode(level, p, Vector3int32(i, j, k));
}
