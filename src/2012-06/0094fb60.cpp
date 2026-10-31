// from server: 22% by Intel
struct Vec3
{
    float x, y, z;
};

struct Matrix3x3
{
    Vec3 rows[3];
};

struct Transform
{
    Matrix3x3 rotation;
    Vec3 position;
};

extern "C" void __cdecl sub_94FA70(Vec3*, const Vec3*);

Transform* __cdecl sub_94FB60(Transform* dest, const Transform* src, const Transform* end)
{
    if (src == end)
        return dest;

    const Matrix3x3* srcMat = &src->rotation;
    const Matrix3x3* endMat = &end->rotation;
    Matrix3x3* destMat = &dest->rotation;

    do
    {
        destMat->rows[0] = srcMat->rows[0];
        destMat->rows[1] = srcMat->rows[1];
        sub_94FA70(&destMat->rows[2], &srcMat->rows[2]);
        --srcMat;
        --destMat;
    }
    while (srcMat != endMat);

    return dest;
}
