// from server: 39% by tester
struct VMoveResizeJoinTool {
    char pad[0x7c];
    int field_7c;
    int field_80;
    int field_84;
    int field_88;
    char field_8c;
    char pad2[7];
    float field_94;
    float field_98;
    float field_9c;
    unsigned short field_a0;
    unsigned short field_a2;
    float field_a4;
    int field_a8;
    char field_ac;
    char pad3[3];
    float field_b0;
    float field_b4;
    float field_b8;
    float field_bc;
    float field_c0;
    float field_c4;
    char pad4[4];
    char field_c8[0x20];
    VMoveResizeJoinTool(int);
};

extern "C" void __stdcall sub_71eed0(int);
extern "C" void __stdcall sub_b22648(char*);

VMoveResizeJoinTool::VMoveResizeJoinTool(int arg) {
    sub_71eed0(arg);
    field_7c = 0;
    field_80 = 0;
    field_84 = 0;
    field_88 = 0;
    field_8c = 0;
    field_94 = 0.0f;
    field_98 = 0.0f;
    field_9c = 0.0f;
    field_a0 = 0;
    field_a2 = 0;
    field_a4 = 0.0f;
    field_a8 = 0;
    field_ac = 0;
    field_b0 = 0.0f;
    field_b4 = 0.0f;
    field_b8 = 0.0f;
    field_bc = 0.0f;
    field_c0 = 0.0f;
    field_c4 = 0.0f;
    sub_b22648(field_c8);
}
