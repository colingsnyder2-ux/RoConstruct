// from server: 100% by atomic.potato
struct Vector3 {
    float x, y, z;
};

struct Matrix3 {
    float m[9];
};

struct CoordinateFrame {
    Matrix3 rotation;
    Vector3 translation;
};

struct Camera {
    char pad[0xdc];
    CoordinateFrame cf;
    void setCoordinateFrame(const CoordinateFrame& other);
    void update();
};

void Camera::setCoordinateFrame(const CoordinateFrame& other) {
    CoordinateFrame* dst = &cf;
    dst->rotation = other.rotation;
    dst->translation.x = other.translation.x;
    dst->translation.y = other.translation.y;
    dst->translation.z = other.translation.z;
    update();
}
