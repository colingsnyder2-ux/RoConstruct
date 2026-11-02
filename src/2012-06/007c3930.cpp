// from server: 69% by tajop
struct Vector3int16 {
    short x, y, z;
    Vector3int16(short _x, short _y, short _z) : x(_x), y(_y), z(_z) {}
    Vector3int16 operator+(const Vector3int16& o) const { return Vector3int16(x + o.x, y + o.y, z + o.z); }
    Vector3int16 operator*(int s) const { return Vector3int16(x * s, y * s, z * s); }
};

struct Vector3 {
    float x, y, z;
    Vector3() {}
    Vector3(float _x, float _y, float _z) : x(_x), y(_y), z(_z) {}
    Vector3(const Vector3int16& v);
    Vector3 operator+(const Vector3& o) const { return Vector3(x + o.x, y + o.y, z + o.z); }
    Vector3 operator-(const Vector3& o) const { return Vector3(x - o.x, y - o.y, z - o.z); }
    Vector3 operator*(float s) const { return Vector3(x * s, y * s, z * s); }
};

struct CoordinateFrame {
    float rotation[9];
    Vector3 translation;
};

struct MegaClusterInstance {
    char pad[0x324];
    Vector3int16 gridSize;
    const Vector3& getPartSizeUi() const;
    const CoordinateFrame& getCoordinateFrame() const;
    Vector3 cellCornerToWorld(const Vector3int16& v) const;
};

Vector3 MegaClusterInstance::cellCornerToWorld(const Vector3int16& v) const
{
    Vector3 size = getPartSizeUi();
    Vector3 position = getCoordinateFrame().translation;
    Vector3 cell((v + Vector3int16(gridSize.x / 2, 0, gridSize.z / 2)) * 4);
    return position + (cell - size * 0.5f);
}
