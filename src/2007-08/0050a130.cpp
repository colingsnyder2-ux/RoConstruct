// from server: 100% by tajop
namespace G3D {

class Matrix3 {
public:
    float elt[3][3];
    Matrix3(float, float, float, float, float, float, float, float, float);
    void set(float, float, float, float, float, float, float, float, float);
};

__declspec(noinline) void Matrix3::set(float fEntry00, float fEntry01, float fEntry02,
                                       float fEntry10, float fEntry11, float fEntry12,
                                       float fEntry20, float fEntry21, float fEntry22)
{
    elt[0][0] = fEntry00;
    elt[0][1] = fEntry01;
    elt[0][2] = fEntry02;
    elt[1][0] = fEntry10;
    elt[1][1] = fEntry11;
    elt[1][2] = fEntry12;
    elt[2][0] = fEntry20;
    elt[2][1] = fEntry21;
    elt[2][2] = fEntry22;
}

Matrix3::Matrix3(float fEntry00, float fEntry01, float fEntry02,
                 float fEntry10, float fEntry11, float fEntry12,
                 float fEntry20, float fEntry21, float fEntry22)
{
    set(fEntry00, fEntry01, fEntry02,
        fEntry10, fEntry11, fEntry12,
        fEntry20, fEntry21, fEntry22);
}

}
