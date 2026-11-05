// from server: 100% by tajop
struct Vector3 {
    float x, y, z;
    static const Vector3& unitY();
};

struct Matrix3 {
    float m[9];
    Matrix3(const Matrix3& other);
    static const Matrix3& identity();
};

struct CoordinateFrame {
    Matrix3 rotation;
    Vector3 translation;
    CoordinateFrame(const Vector3& t) : rotation(Matrix3::identity()), translation(t) {}
};

struct Settings {
    char pad[0x8c];
    int disabled;
};

struct Target;

Settings& settings();
void emitEffect(Target* target, const CoordinateFrame& frame, int a, float b, float c, const Vector3& axis, int d);

void onStatusEvent(Target* target, const Vector3& position)
{
    if (settings().disabled == 0) {
        CoordinateFrame frame(position);
        emitEffect(target, frame, 1, 0.2f, 1.0f, Vector3::unitY(), 1);
    }
}
