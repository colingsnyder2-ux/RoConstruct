// from server: 80% by Intel
struct Vector3 {
    int x, y, z;
};

struct KeyframeSequence {
    Vector3 getValue(int* out) const;
};

Vector3 KeyframeSequence::getValue(int* out) const {
    const char* base = reinterpret_cast<const char*>(this);
    const Vector3* src;
    if (base[0xD4] != 0) {
        src = reinterpret_cast<const Vector3*>(base + 0xD8);
    } else {
        src = reinterpret_cast<const Vector3*>(base + 0xE4);
    }
    out[0] = src->x;
    out[1] = src->y;
    out[2] = src->z;
    return *src;
}
