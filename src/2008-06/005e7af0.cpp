// from server: 100% by Intel
struct Geometry {
    int getFaceId(int index);
};

int Geometry::getFaceId(int index) {
    return *(*(int**)((char*)this + 0x1c) + index);
}
