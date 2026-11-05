// from server: 45% by atomic.potato
struct RBX_WedgeBuilder {
    void* vtable;
    int field_4;
    float field_8;
    float field_c;
    float field_10;
    int field_14;
    int field_18;
    int field_1c;
    int field_20;
    float field_24;
    int field_28;
    int field_2c;
    int field_30;
    char field_34;
    void construct(int a1, float a2, float a3, float a4, int a5, int a6, int a7, int a8, int a9, char a10, float a11, int a12, int a13, int a14);
};

void RBX_WedgeBuilder::construct(int a1, float a2, float a3, float a4, int a5, int a6, int a7, int a8, int a9, char a10, float a11, int a12, int a13, int a14)
{
    field_4 = a1;
    field_8 = a2;
    field_c = a3;
    field_10 = a4;
    field_14 = a5;
    field_18 = a6;
    field_1c = a7;
    field_20 = a8;
    field_24 = a11;
    field_28 = a9;
    field_2c = a12;
    field_30 = a13;
    field_34 = a10;
    vtable = (void*)0xa8c488;
}
