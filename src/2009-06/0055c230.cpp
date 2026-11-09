// from server: 21% by atomic.potato
struct V2 { float x, y; };
struct V3 { float x, y, z; };

struct S {
    char pad0[4];
    void* field4;
    char pad8[0x10];
    float f18;
    float f1c;
    float f20;
    void method(int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11, int a12, int a13, int a14, int a15, int a16, int a17, int a18, int a19, int a20);
};

struct T {
    void sub_575590(V2* out);
    void sub_485980(const V3* a, const V3* b, const V3* c, const V3* d);
};

extern "C" void __cdecl sub_5787f0(V3* out, const V2* a, const V2* b);
extern "C" void __cdecl sub_682db0(V3* out, const V3* in);

extern float g_8bad4c;

void S::method(int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11, int a12, int a13, int a14, int a15, int a16, int a17, int a18, int a19, int a20)
{
    V2 v1, v2, v3, v4;
    V3 v5, v6, v7, v8, v9, v10, v11, v12;
    float f1, f2, f3, f4;
    float f5, f6;
    char flag;

    ((T*)((char*)this + 0x50))->sub_575590(&v1);
    ((T*)field4)->sub_575590(&v2);
    f1 = v2.x - v1.x;
    f2 = v2.y - v1.y;
    ((T*)((char*)this + 0x50))->sub_575590(&v3);
    ((T*)field4)->sub_575590(&v4);
    f3 = v3.x + v4.x;
    f4 = v3.y + v4.y;
    sub_5787f0(&v5, &v3, &v4);
    ((T*)((char*)this + 0x50))->sub_575590((V2*)&v6);
    ((T*)((char*)this + 0x50))->sub_485980(&v6, &v7, &v8, &v9);
    f5 = 0.0f;
    f6 = f1;
    if (f6 < f5) f5 = f5 - f6; else f5 = f5 + f6;
    f1 = f5;
    f5 = 0.0f;
    f6 = f2;
    if (f6 < f5) f5 = f5 - f6; else f5 = f5 + f6;
    f2 = f5;
    flag = *(char*)((char*)this + 0x94);
    if (flag) {
        v10.x = v3.x;
        v10.y = v3.y;
    }
    sub_682db0(&v11, &v10);
    sub_682db0(&v12, &v11);
    v12.x = f18 + v12.x;
    v12.y = f1c + v12.y;
    v12.z = f20 + v12.z;
    sub_682db0(&v11, &v12);
    sub_682db0(&v10, &v11);
    v10.x = v10.x * g_8bad4c;
    v10.y = v10.y * g_8bad4c;
    (*(void(__thiscall**)(void*))(*(char**)field4 + 0xc))(field4);
}
