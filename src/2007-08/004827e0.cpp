// from server: 100% by colin
struct G3D_Shader {
    int f();
};

int G3D_Shader::f() {
    return *(int*)(this + 0xC) + 0x11C;
}
