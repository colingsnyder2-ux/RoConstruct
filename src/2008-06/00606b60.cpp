// from server: 100% by colin
// roc-cl: 50727
// roc-flags: /O2 /GS- /EHsc /MD /fp:fast
struct Extents {
    float lowX;
    float lowY;
    float lowZ;
    float highX;
    float highY;
    float highZ;
    bool overlapsOrTouches(const Extents& other) const;
};

bool Extents::overlapsOrTouches(const Extents& other) const {
    if (!(lowX > other.highX) && !(lowY > other.highY) && !(lowZ > other.highZ) &&
        !(highY < other.lowY) && !(highX < other.lowX) && !(highZ < other.lowZ)) {
        return true;
    }
    return false;
}
