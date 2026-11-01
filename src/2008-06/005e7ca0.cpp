// from server: 100% by king_originala
struct Geometry {
    int next(void* item);
    int resolve(void* item);
};

int Geometry::next(void* item) {
    int index;
    if (this == *(Geometry**)((char*)item + 0x0c))
        index = *(int*)((char*)item + 0x14);
    else
        index = *(int*)((char*)item + 0x18);

    ++index;
    if (index < *(int*)((char*)this + 0x3c))
        item = (*(void***)((char*)this + 0x38))[index];
    else
        item = 0;

    return resolve(item);
}
