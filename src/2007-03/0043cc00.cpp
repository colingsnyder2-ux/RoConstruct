// from server: 100% by tester
struct VVector3 {
    float x;
    float y;
    float z;
};

int __stdcall equal(const VVector3* a, const VVector3* b)
{
    if (a->x == b->x && a->y == b->y && a->z == b->z)
        return 1;
    return 0;
}
