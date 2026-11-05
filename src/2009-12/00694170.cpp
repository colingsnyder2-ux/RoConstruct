// from server: 11% by atomic.potato
struct Mat3
{
    float m[9];
};

struct Vec3
{
    float x, y, z;
};

struct S
{
    char pad[0x13c];
    Mat3 m;
    void f(Vec3*);
};

extern "C" void __stdcall sub_5f3900(Mat3*, const Mat3*);
extern "C" void __stdcall sub_5f3990(Mat3*, float*, int);
extern "C" void __stdcall sub_5f39b0(Mat3*, int, float*);
extern "C" float __stdcall sub_5f4b70(Mat3*, float);
extern "C" void __stdcall sub_694070(S*, Vec3*);
extern "C" void* __stdcall sub_6f0240(float*, float*);

extern float g_9c0e4c;
extern float g_9b1610;

void S::f(Vec3* out)
{
    Mat3 local;
    sub_5f3900(&local, &m);

    float a, b, c;
    sub_5f3990(&local, &a, 0);
    sub_5f3990(&local, &b, 1);

    float d = *(float*)((char*)&m + 0x24);
    float e = *(float*)((char*)&m + 0x28);
    float f = *(float*)((char*)&m + 0x2c);

    float tmp[3];
    tmp[0] = d;
    tmp[1] = e;
    tmp[2] = f;

    float* r = (float*)sub_6f0240(tmp, &a);

    float neg = g_9b1610;
    float rx = r[0];
    float ry = r[1];
    float rz = r[2];

    rx = -rx;
    ry = -ry;
    rz = -rz;

    float v0 = a;
    float v1 = b;
    float v2 = c;

    float m00 = v0 * ry - rz * v1;
    float m01 = rx * v1 - v0 * rz;
    float m02 = v0 * rz - rx * v1;

    float m10 = v1 * rz - v2 * ry;
    float m11 = v2 * rx - v0 * rz;
    float m12 = v0 * ry - v1 * rx;

    Mat3 rot;
    rot.m[0] = m00;
    rot.m[1] = m01;
    rot.m[2] = m02;
    rot.m[3] = m10;
    rot.m[4] = m11;
    rot.m[5] = m12;
    rot.m[6] = rx;
    rot.m[7] = ry;
    rot.m[8] = rz;

    sub_5f4b70(&rot, g_9c0e4c);

    float q0 = rot.m[0];
    float q1 = rot.m[1];
    float q2 = rot.m[2];
    float q3 = rot.m[3];
    float q4 = rot.m[4];
    float q5 = rot.m[5];

    float n0 = q1 * q4 - q0 * q5;
    float n1 = q2 * q5 - q1 * q3;
    float n2 = q0 * q3 - q2 * q4;

    rot.m[0] = n0;
    rot.m[1] = n1;
    rot.m[2] = n2;

    sub_5f4b70(&rot, g_9c0e4c);

    sub_5f39b0(&local, 0, &rot.m[0]);
    sub_5f39b0(&local, 1, &rot.m[3]);
    sub_5f39b0(&local, 2, &rot.m[6]);

    sub_694070(this, out);
}
