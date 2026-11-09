// from server: 100% by EspClaude
// roc 2008-06 005b28d0  unit: RBX::Accoutrement  size: 366 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 005b28d0
//

//

extern "C" double __cdecl sqrt(double);
#pragma intrinsic(sqrt)
#pragma float_control(precise, off)

struct Vector3 {
    float x, y, z;
    Vector3() {}
    Vector3(float _x, float _y, float _z) : x(_x), y(_y), z(_z) {}
    float squaredMagnitude() const { return x * x + y * y + z * z; }
    Vector3 direction() const {
        const float lenSquared = squaredMagnitude();
        const float invSqrt = 1.0f / (float)sqrt(lenSquared);
        return Vector3(x * invSqrt, y * invSqrt, z * invSqrt);
    }
    Vector3 cross(const Vector3& rkVector) const {
        return Vector3(y * rkVector.z - z * rkVector.y, z * rkVector.x - x * rkVector.z,
                       x * rkVector.y - y * rkVector.x);
    }
    float unitize(float);
};

struct Matrix3 {
    float data[9];
    Matrix3(const Matrix3&);
    Vector3 column(int) const;
    void setColumn(int, const Vector3&);
};

struct Frame {
    Matrix3 rotation;
    Vector3 translation;

    Frame(const Frame& source)
        : rotation(source.rotation) {
        translation.x = source.translation.x;
        translation.y = source.translation.y;
        translation.z = source.translation.z;
    }
};

extern const float normalizationTolerance;

struct Tool {
    char padding[0x158];
    Frame frame;
    void setFrame(const Frame&);
    void orient(const Vector3&);
};

void Tool::orient(const Vector3& direction) {
    Frame result(frame);

    Vector3 right = result.rotation.column(0);
    Vector3 back = result.rotation.column(2);

    Vector3 up = direction.direction();
    Vector3 newBack = right.cross(up);
    newBack.unitize(normalizationTolerance);
    Vector3 newRight = up.cross(newBack);
    newRight.unitize(normalizationTolerance);

    result.rotation.setColumn(0, newRight);
    result.rotation.setColumn(1, up);
    result.rotation.setColumn(2, newBack);
    setFrame(result);
}
