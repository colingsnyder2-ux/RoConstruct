// from server: 42% by Intel
struct Matrix4x4 {
    float m[4][4];
};

float __stdcall func_00a7d1c5(Matrix4x4* mat) {
    float t0 = mat->m[2][0] * mat->m[3][3] - mat->m[3][0] * mat->m[2][3];
    float t1 = mat->m[3][0] * mat->m[2][2] - mat->m[2][0] * mat->m[3][2];
    float t2 = mat->m[2][0] * mat->m[3][1] - mat->m[3][0] * mat->m[2][1];
    float t3 = mat->m[3][0] * mat->m[2][1] - mat->m[2][0] * mat->m[3][1];
    float t4 = mat->m[2][0] * mat->m[3][2] - mat->m[3][0] * mat->m[2][2];
    float t5 = mat->m[3][0] * mat->m[2][3] - mat->m[2][0] * mat->m[3][3];

    float det = mat->m[0][0] * (mat->m[1][1] * t0 + mat->m[1][2] * t1 + mat->m[1][3] * t2)
              - mat->m[0][1] * (mat->m[1][0] * t0 + mat->m[1][2] * t3 + mat->m[1][3] * t4)
              + mat->m[0][2] * (mat->m[1][0] * t1 + mat->m[1][1] * t3 + mat->m[1][3] * t5)
              - mat->m[0][3] * (mat->m[1][0] * t2 + mat->m[1][1] * t4 + mat->m[1][2] * t5);

    return det;
}
