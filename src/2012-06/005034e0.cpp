// from server: 100% by tajop
struct Vector3 {
    float x, y, z;
    Vector3(float _x, float _y, float _z) : x(_x), y(_y), z(_z) {}
};

struct OgreRbxMeshPartAdapter {
    char pad[0x94];
    float values[3];

    Vector3 getValues() const;
};

Vector3 OgreRbxMeshPartAdapter::getValues() const {
    return Vector3(values[0], values[1], values[2]);
}
