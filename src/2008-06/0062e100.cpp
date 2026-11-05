// from server: 100% by king_originala
struct Matrix3 {
    float data[9];
    Matrix3(const Matrix3&);
};

struct Vector3 {
    float x, y, z;
};

struct Cofm {
    const Matrix3& getMoment() const;
};

extern "C" void __cdecl diagonal(Vector3&, const Matrix3&);

struct GeometryService {
    char padding0[0x28];
    Cofm* cofm;
    char padding1[0x3C];
    Matrix3 moment;

    Vector3 getMomentDiagonal() const;
};

Vector3 GeometryService::getMomentDiagonal() const {
    Matrix3 matrix(cofm ? cofm->getMoment() : moment);
    Vector3 result;
    diagonal(result, matrix);
    return result;
}
