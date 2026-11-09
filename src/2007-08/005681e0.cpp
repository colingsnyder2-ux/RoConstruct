// from server: 31% by colin
struct Vector3 {
    float x, y, z;
};

struct Extents {
    Vector3 min;
    Vector3 max;
};

struct Instance;

struct RootInstance {
    char pad[0x228];
    void* field228;

    Vector3 insertInstances(const Instance* instances, int mode, const Vector3* positionHint);
};

extern "C" {
    void* __cdecl sub_495840(void*);
    void __cdecl sub_506ae0(void*);
    void __cdecl sub_509640(void*, void*);
    float __cdecl sub_50f3a0(float);
    void __cdecl sub_576f60(void*, void*, void*);
    void __cdecl sub_5bad30(void*, void*);
    void __cdecl sub_5e1060(void*, void*);
    void __cdecl sub_62fc62(void*);
    void __cdecl sub_567d60(void*, void*, void*, void*);
    void __cdecl sub_567b50(void*, void*);
}

extern float g_7a32e8;
extern float g_79fe50;
extern float g_797e9c;
extern float g_78d394;
extern float g_7a9968;

Vector3 RootInstance::insertInstances(const Instance* instances, int mode, const Vector3* positionHint)
{
    Vector3 result;
    void* p = sub_495840((void*)instances);
    if (p != 0) {
        sub_567b50(this, &result);
        return result;
    }

    void* vtable = *(void**)((char*)this + 0x228);
    void* fn = *(void**)((char*)vtable + 8);
    void* tmp;
    ((void (__thiscall*)(void*, void*))fn)((char*)this + 0x228, &tmp);
    sub_506ae0(tmp);

    float f = g_7a32e8;
    float f2 = f;
    float f3 = f;
    float f4 = f;

    Vector3 v;
    sub_509640(&v, &f2);

    float a = v.x * f2;
    float b = v.z * f2;
    float c = 0.0f;

    float d = g_79fe50;
    sub_50f3a0(d);

    Extents ext;
    ext.min.x = 0.0f;
    ext.min.y = 0.0f;
    ext.min.z = 0.0f;

    float ex = *(float*)((char*)p + 0xc) - *(float*)((char*)p + 0);
    float ey = *(float*)((char*)p + 0x14) - *(float*)((char*)p + 8);
    float ez = 0.0f;

    float scale = g_797e9c;
    ex *= scale;
    ey *= scale;

    Vector3 pos;
    pos.x = 0.0f;
    pos.y = 0.0f;
    pos.z = 0.0f;

    sub_576f60(p, &pos, &ext);

    Vector3 out;
    sub_5bad30(&out, &pos);

    float m1 = out.x * g_78d394;
    float m2 = out.y * g_78d394;
    float m3 = out.z * g_78d394;

    float s1 = g_7a9968;
    float s2 = g_7a9968;
    float s3 = g_7a9968;

    float r1 = out.x + pos.x;
    float r2 = out.y + pos.y;
    float r3 = out.z + pos.z;

    float q1 = r1 * g_797e9c;
    float q2 = r2 * g_797e9c;
    float q3 = r3 * g_797e9c;

    Vector3 final;
    final.x = q1;
    final.y = q2;
    final.z = q3;

    sub_5e1060(&final, &out);

    result.x = out.x;
    result.y = out.y;
    result.z = out.z;

    if (p != 0) {
        sub_567d60(p, &out, &final, &result);
        sub_62fc62(p);
    }

    return result;
}
