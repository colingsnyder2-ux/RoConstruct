// from server: 23% by atomic.potato
struct Sub {
    char pad[0x38];
    void init();
};

struct RbxMeshPartAdapter {
    char pad0[8];
    Sub sub1;
    char pad1[0x30];
    float f38;
    float f3c;
    char b40;
    char b41;
    char b42;
    char b43;
    char pad2[4];
    void* p48;
    void* p4c;
    void* p50;
    Sub sub2;
    char pad3[0x30];
    char b84;
    char b85;

    RbxMeshPartAdapter();
};

RbxMeshPartAdapter::RbxMeshPartAdapter() {
    *reinterpret_cast<int*>(this) = 0xaf7174;
    sub1.init();
    f38 = 0.0f;
    f3c = 0.0f;
    b40 = 0;
    b41 = 0;
    b42 = 0;
    b43 = 0;
    *reinterpret_cast<int*>(this) = 0xaf7424;
    p48 = 0;
    p4c = 0;
    p50 = 0;
    sub2.init();
    b84 = 0;
    b85 = 0;
}
