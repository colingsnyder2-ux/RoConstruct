// from server: 100% by colin
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
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