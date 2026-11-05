// from server: 100% by king_originala
struct VVector3 {
    float x;
    float y;
    float z;
};

#pragma float_control(precise, off, push)
int __stdcall equals(const VVector3* b, const VVector3* a) {
    if (b->x == a->x && b->y == a->y && b->z == a->z) return 1;
    return 0;
}
#pragma float_control(pop)
