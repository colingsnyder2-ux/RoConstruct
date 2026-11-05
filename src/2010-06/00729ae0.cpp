// from server: 24% by atomic.potato
extern "C" {
    float __stdcall sub_7289E0(int, int);
    int __stdcall sub_7291F0(int, int, float*);
    void __stdcall sub_60BFD0(int, float*);
    float* __stdcall sub_722E10(int, int, int);
}

extern int dword_BE2A50;

struct LuaArguments {
    int method_729AE0(int a);
};

int LuaArguments::method_729AE0(int a)
{
    float v1[3];
    float v2[3];
    float v3[3];
    v1[0] = 0.0f; v1[1] = 0.0f; v1[2] = 0.0f;
    if (!sub_7291F0(a, 1, v1)) {
        float* p = sub_722E10(a, 2, dword_BE2A50);
        v2[0] = p[0]; v2[1] = p[1]; v2[2] = p[2];
        float s = sub_7289E0(a, 1);
        v3[0] = v2[0] * s;
        v3[1] = v2[1] * s;
        v3[2] = v2[2] * s;
        sub_60BFD0(a, v3);
        return 1;
    }
    v2[0] = 0.0f; v2[1] = 0.0f; v2[2] = 0.0f;
    if (!sub_7291F0(a, 2, v2)) {
        float s = sub_7289E0(a, 2);
        v3[0] = v1[0] * s;
        v3[1] = v1[1] * s;
        v3[2] = v1[2] * s;
        sub_60BFD0(a, v3);
        return 1;
    }
    v3[0] = v2[0] * v1[0];
    v3[1] = v2[1] * v1[1];
    v3[2] = v2[2] * v1[2];
    sub_60BFD0(a, v3);
    return 1;
}
