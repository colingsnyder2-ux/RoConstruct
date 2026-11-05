// from server: 32% by Intel
struct Vector3 {
    float x, y, z;
};

struct Matrix3x3 {
    Vector3 rows[3];
};

struct Transform {
    Vector3 position;
    Matrix3x3 rotation;
};

extern "C" void __cdecl sub_94FA70(Matrix3x3* dst, const Matrix3x3* src);

Transform* __cdecl sub_94FF80(Transform* dst, const Transform* src, const Transform* end, Transform* out) {
    if (src == end) {
        return out;
    }

    const Transform* currentSrc = src;
    Transform* currentDst = out;

    do {
        currentDst->position = currentSrc->position;

        currentDst->rotation.rows[0].x = currentSrc->rotation.rows[0].x;
        currentDst->rotation.rows[0].y = currentSrc->rotation.rows[0].y;
        currentDst->rotation.rows[0].z = currentSrc->rotation.rows[0].z;

        sub_94FA70(&currentDst->rotation, &currentSrc->rotation);

        currentSrc++;
        currentDst++;
    } while (currentSrc != end);

    return currentDst;
}
