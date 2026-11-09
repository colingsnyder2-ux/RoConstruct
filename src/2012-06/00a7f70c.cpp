// from server: 35% by Intel
struct Matrix4x4 {
    float m[4][4];
};

struct Vec2 {
    float x, y;
};

struct Vec4 {
    float x, y, z, w;
};

int __stdcall func_00a7f70c(Vec4* out, int count, const Vec2* src, int srcStride, const Matrix4x4* mat, int matStride) {
    if (count <= 0) {
        return reinterpret_cast<int>(out);
    }

    const Vec2* currentSrc = src;
    const Matrix4x4* currentMat = mat;
    Vec4* currentOut = out;

    do {
        float tx = currentMat->m[0][2] * currentSrc->y + currentMat->m[0][0] * currentSrc->x + currentMat->m[0][3];
        float ty = currentMat->m[1][2] * currentSrc->y + currentMat->m[1][0] * currentSrc->x + currentMat->m[1][3];
        float tz = currentMat->m[2][2] * currentSrc->y + currentMat->m[2][0] * currentSrc->x + currentMat->m[2][3];
        float tw = currentMat->m[3][2] * currentSrc->y + currentMat->m[3][0] * currentSrc->x + currentMat->m[3][3];

        currentOut->x = tx;
        currentOut->y = ty;
        currentOut->z = tz;
        currentOut->w = tw;

        currentSrc = reinterpret_cast<const Vec2*>(reinterpret_cast<const char*>(currentSrc) + srcStride);
        currentMat = reinterpret_cast<const Matrix4x4*>(reinterpret_cast<const char*>(currentMat) + matStride);
        ++currentOut;
        --count;
    } while (count != 0);

    return reinterpret_cast<int>(out);
}
