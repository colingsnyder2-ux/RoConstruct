// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
namespace G3D {
class Matrix3 {
public:
    float elt[3][3];
    Matrix3(float fEntry00, float fEntry01, float fEntry02,
            float fEntry10, float fEntry11, float fEntry12,
            float fEntry20, float fEntry21, float fEntry22);
};
}
namespace RBX {
class Math {
public:
    static const G3D::Matrix3& matrixTiltZ();
};
const G3D::Matrix3& Math::matrixTiltZ()
{
    static G3D::Matrix3 tiltZ(0, -1, 0, 1, 0, 0, 0, 0, 1);
    return tiltZ;
}
}
