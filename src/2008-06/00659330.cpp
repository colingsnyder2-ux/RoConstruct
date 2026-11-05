// from server: 100% by king_originala
struct Box {
    int minX, minY, minZ;
    int maxX, maxY, maxZ;
};

bool __cdecl intersects(const Box* a, const Box* b)
{
    if (a->minX <= b->maxX &&
        a->minY <= b->maxY &&
        a->minZ <= b->maxZ &&
        a->maxY >= b->minY &&
        a->maxX >= b->minX &&
        a->maxZ >= b->minZ)
        return true;
    return false;
}
