// from server: 24% by Intel
struct VScriptContext {
    int f();
};

extern "C" int __stdcall sub_53A540(int, int, int);

int VScriptContext::f() {
    int v1;
    int v2 = *(int*)((char*)&v1 + 12);
    *(int*)&v1 = 0;
    if (!v2)
        return *(int*)((char*)&v1 + 8) = 0, 0;
    int v3 = *(int*)((char*)&v1 + 16);
    int v4 = *(int*)((char*)this + 44);
    int v5 = *(int*)((char*)&v1 + 12);
    v4 += v2 - 28;
    sub_53A540(v4, v5, v3);
    return v5;
}
