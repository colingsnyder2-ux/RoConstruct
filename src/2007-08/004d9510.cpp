// from server: 100% by colin
struct MegaTextureProxy {
    float x;
    float y;
    float z;
};

int __fastcall compare(const MegaTextureProxy* b, const MegaTextureProxy* a)
{
    if (a->x < b->x)
        return -1;
    if (a->x > b->x)
        return 1;
    if (a->y < b->y)
        return -1;
    if (a->y > b->y)
        return 1;
    if (a->z < b->z)
        return -1;
    if (a->z > b->z)
        return 1;
    return 0;
}
