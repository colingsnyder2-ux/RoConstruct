// from server: 24% by atomic.potato
struct Vec2 { float x, y; };
struct Vec4 { float x, y, z, w; };

struct RbxMeshPartAdapter
{
    float data[17];
    RbxMeshPartAdapter& copy(const float* src);
};

struct VerticalCylinderBuilder
{
    RbxMeshPartAdapter* build(RbxMeshPartAdapter* result, const float* a, const float* b, int n);
};

extern "C" Vec2* __stdcall sub_71FA00(Vec2* out, const float* a, int n, const float* b);
extern "C" Vec4* __stdcall sub_5F6CF0(Vec4* out, const Vec2* a, const Vec2* b);
extern "C" Vec2* __stdcall sub_5F4CF0(Vec2* out, const Vec2* src);

RbxMeshPartAdapter& RbxMeshPartAdapter::copy(const float* src)
{
    data[0] = src[0];
    data[1] = src[1];
    data[2] = src[2];
    data[3] = src[3];
    data[4] = src[4];
    return *this;
}

RbxMeshPartAdapter* VerticalCylinderBuilder::build(RbxMeshPartAdapter* result, const float* a, const float* b, int n)
{
    Vec2 v0;
    Vec2 v1;
    Vec2 v2;
    Vec2 v3;
    Vec4 v4;

    sub_71FA00(&v0, a, 3, b);
    Vec2 t0;
    sub_5F4CF0(&t0, &v0);

    sub_71FA00(&v1, a, 3, b);
    Vec2 t1;
    sub_5F4CF0(&t1, &v1);

    Vec2 d;
    d.x = t1.x - t0.x;
    d.y = t1.y - t0.y;

    sub_5F6CF0(&v4, &d, &v2);

    float tmp[5];
    tmp[0] = v4.x;
    tmp[1] = v4.y;
    tmp[2] = v4.z;
    tmp[3] = v4.w;
    tmp[4] = v3.x;
    tmp[5] = v3.y;

    result->copy(tmp);
    return result;
}
