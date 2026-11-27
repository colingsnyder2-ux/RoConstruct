// from server: 100% by Xemicl
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
namespace G3D {
class Matrix3 {
    float m[3][3];
public:
    Matrix3(float, float, float, float, float, float, float, float, float);
};
}
const G3D::Matrix3& matrixTiltX()
{
    static G3D::Matrix3 tiltX(1, 0, 0, 0, 0, -1, 0, 1, 0);
    return tiltX;
}
