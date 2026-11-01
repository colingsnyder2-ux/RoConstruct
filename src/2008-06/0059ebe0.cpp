// from server: 100% by king_originala
struct Vector3 {
    float x, y, z;

    Vector3();
    Vector3(const Vector3& other);
};

inline Vector3::Vector3() {}

inline Vector3::Vector3(const Vector3& other)
    : x(other.x), y(other.y), z(other.z) {}

struct ShapeData {
    char padding[4];
    Vector3 size;
};

struct ChangeTracker {
    void beginChange(void* state);
    void endChange(void* state);
};

struct PartInstance {
    char padding0[0x1dc];
    int mode;
    char padding1[0x48];
    char state[0x9c];
    ShapeData* shape;

    void setMode(int value);
    Vector3 adjustSize(const Vector3& size);
    void applySize(const Vector3& size);
    void refresh();
    void changeMode(int value);
};

extern ChangeTracker* __cdecl findTracker(PartInstance* part);

void PartInstance::changeMode(int value) {
    if (mode == value)
        return;

    ChangeTracker* tracker = findTracker(this);
    if (tracker)
        tracker->beginChange(state);

    setMode(value);

    if (value != 1) {
        Vector3 size(shape->size);
        Vector3 adjusted = adjustSize(size);
        applySize(adjusted);
        refresh();
    }

    refresh();

    tracker = findTracker(this);
    if (tracker)
        tracker->endChange(state);
}
