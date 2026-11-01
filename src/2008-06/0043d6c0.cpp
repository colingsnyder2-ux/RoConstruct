// from server: 100% by colin
struct VColor3 {
    char pad[0x130];
    int field130;
    int field134;
    int field138;
    void baseInit(int a, int b);
    VColor3* init(int a, int b);
};

VColor3* VColor3::init(int a, int b) {
    baseInit(a, b);
    field138 = 0;
    field134 = 0;
    field130 = 0;
    *(int*)this = 0x81497c;
    *(int*)((char*)this + 0x20) = 0x81491c;
    *(int*)((char*)this + 0x10c) = 0x814914;
    return this;
}
