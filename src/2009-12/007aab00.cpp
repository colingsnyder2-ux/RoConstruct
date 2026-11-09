// from server: 32% by atomic.potato
struct Vec3
{
    float x;
    float y;
    float z;
};

struct Mat4
{
    float m[16];
};

struct RotateConnector
{
    void __cdecl compute(Vec3* out, const Mat4* a, const Mat4* b, int idx);
};

struct Mat4Helper
{
    void copyFrom(const Mat4* src);
    void combine(const Mat4* src);
    void getRow(Vec3* out, int idx);
};

extern "C" void __cdecl sub_7AA9F0(Mat4* m);

void RotateConnector::compute(Vec3* out, const Mat4* a, const Mat4* b, int idx)
{
    Mat4 t1;
    Mat4 t2;
    Mat4 t3;
    Mat4 t4;
    Vec3 v;

    ((Mat4Helper*)&t1)->copyFrom(a);
    ((Mat4Helper*)&t2)->copyFrom(b);
    ((Mat4Helper*)&t3)->combine(&t1);
    ((Mat4Helper*)&t4)->copyFrom(&t3);
    ((Mat4Helper*)&t4)->getRow(&v, idx);
    out->x = v.x;
    out->y = v.y;
    out->z = v.z;
    sub_7AA9F0(&t4);
}
