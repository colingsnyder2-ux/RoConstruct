// from server: 17% by atomic.potato
struct Vec3 { float x, y, z; };

extern "C" {
    void* __cdecl sub_542840();
    void* __cdecl sub_542880();
}

struct Mechanism {
    char pad[0x58];
    void sub_540100(int idx, float* v);
    void func(float a, float b, float c);
};

void Mechanism::sub_540100(int idx, float* v)
{
    float* p = (float*)this;
    p[idx] = v[0];
    p[idx + 3] = v[1];
    p[idx + 6] = v[2];
}

void Mechanism::func(float a, float b, float c)
{
    float* p1 = (float*)sub_542840();
    float v1x = p1[0], v1y = p1[1], v1z = p1[2];
    float* p2 = (float*)sub_542880();
    float v2x = p2[0], v2y = p2[1], v2z = p2[2];

    float d = a * v1x + b * v1y + c * v1z;

    float px = a * d;
    float py = b * d;
    float pz = c * d;

    float dx = v1x - px;
    float dy = v1y - py;
    float dz = v1z - pz;

    float len = dx*dx + dy*dy + dz*dz;
    float inv;

    if (len > 1e-6f) {
        inv = 1.0f / len;
        dx *= inv; dy *= inv; dz *= inv;
    } else {
        float d2 = a * v2x + b * v2y + c * v2z;
        float qx = a * d2;
        float qy = b * d2;
        float qz = c * d2;
        float ex = v2x - qx;
        float ey = v2y - qy;
        float ez = v2z - qz;
        float len2 = ex*ex + ey*ey + ez*ez;
        inv = 1.0f / len2;
        dx = ex * inv; dy = ey * inv; dz = ez * inv;
    }

    float r0 = b * dz - c * dy;
    float r1 = c * dx - a * dz;
    float r2 = a * dy - b * dx;

    sub_540100(0, &dx);
    sub_540100(1, &r0);
    sub_540100(2, &dx);
}
