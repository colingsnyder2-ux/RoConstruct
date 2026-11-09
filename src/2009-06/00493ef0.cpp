// from server: 30% by colin
struct RbxString {
    char data[16];
    RbxString();
    ~RbxString();
};

struct RbxVector3 {
    float x, y, z;
};

struct RbxMaterialAdapter {
    char pad0[8];
    char name[0x98];
    char pad1[0x100];
    void setMaterial(const RbxVector3& v, const RbxString& s);
};

extern "C" {
    void __stdcall sub_490d40();
    void __stdcall sub_493ba0();
    void __stdcall sub_4929a0();
    void __stdcall sub_48c100();
    void __stdcall sub_89e4c4();
    void __stdcall sub_89e3e0();
}

void RbxMaterialAdapter::setMaterial(const RbxVector3& v, const RbxString& s) {
    RbxString tmp1;
    RbxString tmp2;
    RbxString tmp3;
    sub_490d40();
    sub_493ba0();
    sub_89e4c4();
    sub_89e4c4();
    sub_4929a0();
    sub_48c100();
    sub_89e3e0();
    sub_89e4c4();
}
