// from server: 92% by Intel
struct ConstraintSurfacePair {
    int vtable;
    char pad4[0x3C];
    int field40;

    void func(int a1);
};

extern "C" int __stdcall sub_983448(int a1, int a2, int a3, int a4, int a5, int a6);

void ConstraintSurfacePair::func(int a1) {
    int result = sub_983448(a1, 0, 0xD9AC9C, 0xD94C60, 0, 0);
    if (result) {
        this->field40 = *(int*)(result + 0x198);
    } else {
        this->field40 = 0;
    }
}
