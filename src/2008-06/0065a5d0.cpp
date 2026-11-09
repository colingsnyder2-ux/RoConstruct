// from server: 100% by coldek
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// SpatialHash::changeMinMax (2008 multi-level hash). Same-TU analog: the callees
// (addNode 0065a220, findNode 00659890, destroyNode 0065a080) only read the grid
// argument, so their bodies are visible here as read-only analogs; this lets the
// compiler hoist the invariant grid.x/grid.y stores out of the k loop as the target does.
struct Vector3int32 {
    int x, y, z;
    Vector3int32(int a, int b, int c) : x(a), y(b), z(c) {}
};
struct Extents {
    Vector3int32 low;
    Vector3int32 high;
    bool contains(const Vector3int32& p) const {
        return p.x >= low.x && p.y >= low.y && p.z >= low.z
            && p.x <= high.x && p.y <= high.y && p.z <= high.z;
    }
};
struct Primitive;
struct SpatialNode;
void onAddNode(Primitive*, int);
SpatialNode* onFindNode(Primitive*, int);
void onDestroyNode(SpatialNode*);
struct SpatialHash {
    void addNode(int level, Primitive* p, const Vector3int32& grid);
    SpatialNode* findNode(Primitive* p, const Vector3int32& grid);
    void destroyNode(SpatialNode* node);
    void changeMinMax(int level, Primitive* p, const Extents& change, const Extents& oldBox, const Extents& newBox);
};
__declspec(noinline) void SpatialHash::addNode(int level, Primitive* p, const Vector3int32& grid) { onAddNode(p, grid.x + grid.y + grid.z + level); }
__declspec(noinline) SpatialNode* SpatialHash::findNode(Primitive* p, const Vector3int32& grid) { return onFindNode(p, grid.x ^ grid.y ^ grid.z); }
__declspec(noinline) void SpatialHash::destroyNode(SpatialNode* node) { onDestroyNode(node); }

void SpatialHash::changeMinMax(int level, Primitive* p, const Extents& change, const Extents& oldBox, const Extents& newBox)
{
    for (int i = change.low.x; i <= change.high.x; ++i) {
        for (int j = change.low.y; j <= change.high.y; ++j) {
            for (int k = change.low.z; k <= change.high.z; ++k) {
                Vector3int32 grid(i, j, k);
                bool inNew = newBox.contains(grid);
                bool inOld = oldBox.contains(grid);
                if (inNew) {
                    if (!inOld)
                        addNode(level, p, grid);
                } else if (inOld) {
                    destroyNode(findNode(p, grid));
                }
            }
        }
    }
}
