// from server: 100% by Intel
struct Geometry {
    int getFaceIndex(int index);
};

int Geometry::getFaceIndex(int index) {
    return *(*(int**)((char*)this + 0x38) + index);
}
