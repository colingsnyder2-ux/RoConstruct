// from server: 100% by colin
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /fp:fast
#include <math.h>
namespace G3D {
class Vector3 {
public:
    float x, y, z;
    Vector3() {}
    float dot(const Vector3& r) const { return x * r.x + y * r.y + z * r.z; }
    Vector3& operator*=(float s) { x *= s; y *= s; z *= s; return *this; }
};
class Matrix3 {
public:
    float elt[3][3];
    Matrix3() {}
    float* operator[](int r) { return elt[r]; }
    const float* operator[](int r) const { return elt[r]; }
    Vector3 getColumn(int c) const;
    void setColumn(int c, const Vector3& v);
    static const Matrix3& identity();
};
}
namespace RBX {
class Math {
public:
    static G3D::Matrix3 snapToAxes(const G3D::Matrix3& align);
};

G3D::Matrix3 Math::snapToAxes(const G3D::Matrix3& align)
{
    G3D::Matrix3 unkMat;
    float aBest = 0.0f;
    int bestV = -1;
    int second = -1;

    for (int i = 0; i < 3; i++)
    {
        G3D::Vector3 loopColumn = align.getColumn(i);
        for (int j = 0; j < 3; j++)
        {
            float dotProd = G3D::Matrix3::identity().getColumn(j).dot(loopColumn);
            unkMat[i][j] = dotProd;
            if (fabs(dotProd) > fabs(aBest))
            {
                bestV = i;
                second = j;
                aBest = dotProd;
            }
        }
    }

    G3D::Vector3 myColumn = G3D::Matrix3::identity().getColumn(second);
    if (aBest < 0.0f)
    {
        myColumn *= -1.0f;
    }

    int v10 = -1;
    int v11 = -1;
    float v9 = 0.0f;

    for (int i = 0; i < 3; i++)
    {
        if (i != bestV)
        {
            for (int j = 0; j < 3; j++)
            {
                if (j != second)
                {
                    if (fabs(unkMat[i][j]) > fabs(v9))
                    {
                        v9 = unkMat[i][j];
                        v10 = i;
                        v11 = j;
                    }
                }
            }
        }
    }

    G3D::Vector3 myColumn2 = G3D::Matrix3::identity().getColumn(v11);
    if (v9 < 0.0f)
    {
        myColumn2 *= -1.0f;
    }

    int v15 = 3 - v10 - bestV;
    int calcColmTemp = 3 - v11 - second;
    G3D::Vector3 myColumn3 = G3D::Matrix3::identity().getColumn(calcColmTemp);
    if (unkMat[v15][calcColmTemp] < 0.0f)
    {
        myColumn3 *= -1.0f;
    }

    G3D::Matrix3 result;
    result.setColumn(bestV, myColumn);
    result.setColumn(v10, myColumn2);
    result.setColumn(v15, myColumn3);
    return result;
}
}
