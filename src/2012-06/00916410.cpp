// from server: 8% by Intel
struct MegaClusterPoly {
    float m00, m01, m02, m03;
    float m10, m11, m12, m13;
    float m20, m21, m22, m23;
    float m30, m31, m32, m33;

    void __thiscall transform(float* out, const float* in) const;
};

void __thiscall MegaClusterPoly::transform(float* out, const float* in) const {
    out[0] = 0.0f;
    out[1] = 0.0f;
    out[2] = 0.0f;
    out[3] = 0.0f;
    out[4] = 0.0f;
    out[5] = 0.0f;
    out[6] = 0.0f;
    out[7] = 0.0f;
    out[8] = 0.0f;
    out[9] = 0.0f;
    out[10] = 0.0f;
    out[11] = 0.0f;

    float x = m00;
    float y = m01;
    float z = m02;
    float w = in[5];

    float t0 = x * in[0];
    float t1 = y * in[1];
    t0 += t1;
    float t2 = z * in[2];
    t0 += t2;
    t0 += in[9];

    float t3 = w * y;
    float t4 = w * in[7];
    float t5 = z * in[5];
    float t6 = z * in[8];
    t3 += t5;
    x = m00;
    x *= in[6];
    w *= in[3];
    x += w;
    t3 += w;
    t3 += in[10];
    x += t6;
    x += in[11];

    out[0] = t0;
    out[1] = t3;
    out[2] = x;

    float a = m10;
    float b = m11;
    float c = m12;
    float d = in[5];
    float e = in[3];
}
