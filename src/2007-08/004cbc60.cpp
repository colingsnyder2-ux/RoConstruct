// from server: 100% by colin
struct seg_004c0000 {
    int field_0;
    int field_4;
    int field_8;
    int field_c;
    int field_10;
    int field_14;
    int field_18;
    int field_1c;
    seg_004c0000* init();
};

seg_004c0000* seg_004c0000::init()
{
    field_0 = 0x79efcc;
    field_4 = 0x67452301;
    field_8 = 0xefcdab89;
    field_c = 0x98badcfe;
    field_10 = 0x10325476;
    field_14 = 0xc3d2e1f0;
    field_18 = 0;
    field_1c = 0;
    return this;
}
