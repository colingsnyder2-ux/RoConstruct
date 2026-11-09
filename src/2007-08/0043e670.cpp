// from server: 31% by colin
struct Vector3Item {
    char pad0[0x20];
    char pad20[0xe0];
    char pad100[0x1c];
    int field11c;
    float field120;
    float field124;
    float field128;
    char pad12c[0x7c];
    char fielda8[0x1c];
    int init(int a, int b, int c);
};

extern "C" void __stdcall sub_43cef0();
extern "C" void __stdcall sub_77dd6c();

int Vector3Item::init(int a, int b, int c) {
    sub_43cef0();
    field11c = c;
    *(int*)this = 0x78e8ec;
    *(int*)((char*)this + 0x20) = 0x78e88c;
    *(int*)((char*)this + 0x100) = 0x78e884;
    field120 = 0.0f;
    field124 = 0.0f;
    field128 = 0.0f;
    if (c == 0) {
        sub_77dd6c();
    } else if (c == 1) {
        sub_77dd6c();
    } else if (c == 2) {
        sub_77dd6c();
    }
    return (int)this;
}
