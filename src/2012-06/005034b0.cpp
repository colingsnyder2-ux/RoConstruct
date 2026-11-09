// from server: 100% by tajop
struct Vector3 {
    float x, y, z;
    Vector3(float _x, float _y, float _z) : x(_x), y(_y), z(_z) {}
};

struct OgreRbxMeshPartAdapter {
    char pad[0x88];
    float value88;
    float value8c;
    float value90;

    Vector3 func() const;
};

Vector3 OgreRbxMeshPartAdapter::func() const {
    return Vector3(value88, value8c, value90);
}
