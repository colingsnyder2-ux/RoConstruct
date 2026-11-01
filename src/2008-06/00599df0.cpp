// from server: 100% by king_originala
struct Vector3 {
    float x, y, z;

    Vector3();
    Vector3(const Vector3 &other);
};

inline Vector3::Vector3() {
}

inline Vector3::Vector3(const Vector3 &other)
    : x(other.x), y(other.y), z(other.z) {
}

typedef Vector3 *(__thiscall *Getter)(void *, Vector3 *);

struct S {
    char padding[8];
    Getter getter;
    int adjustment;
    int tableOffset;

    Vector3 get(void *object) const;
};

Vector3 S::get(void *object) const {
    char *base = object ? static_cast<char *>(object) - 0x14 : 0;
    Vector3 result;
    return *getter(
        base +
        (*reinterpret_cast<int *>(
            reinterpret_cast<char *>(
                *reinterpret_cast<int **>(base + 0x134)) +
            tableOffset) + adjustment) +
        0x134,
        &result);
}
