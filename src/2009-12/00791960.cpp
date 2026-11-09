// from server: 52% by atomic.potato
extern "C" {
    int __cdecl sub_78A660(int a, int b, int c);
    float __cdecl sub_790310(int a, int b);
    void* __cdecl sub_7897F0(int a, int b);
    void __cdecl sub_788FF0(int a, int b, int c);
    void __cdecl sub_789380(int a, int b);
}

extern int dword_B62B44;

struct LuaArguments {
};

int __cdecl f(int a) {
    int v1;
    int v2;
    float f3;
    float fx, fy, fz;
    float bx, by, bz;
    float t;
    float rx, ry, rz;
    void* p;

    v1 = sub_78A660(a, 1, dword_B62B44);
    v2 = sub_78A660(a, 2, dword_B62B44);
    f3 = sub_790310(a, 3);

    fx = *(float*)(v1 + 0);
    fy = *(float*)(v1 + 4);
    fz = *(float*)(v1 + 8);

    bx = *(float*)(v2 + 0);
    by = *(float*)(v2 + 4);
    bz = *(float*)(v2 + 8);

    t = f3;

    rx = fx + (bx - fx) * t;
    ry = fy + (by - fy) * t;
    rz = fz + (bz - fz) * t;

    p = sub_7897F0(a, 12);
    if (p) {
        *(float*)((char*)p + 0) = rx;
        *(float*)((char*)p + 4) = ry;
        *(float*)((char*)p + 8) = rz;
    }

    sub_788FF0(a, -10000, dword_B62B44);
    sub_789380(a, -2);

    return 1;
}
