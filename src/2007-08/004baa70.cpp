// from server: 100% by colin
struct RakPeer {
    char pad0[0x80];
    unsigned char field80;
    char pad1[3];
    unsigned int field84;
    unsigned int field88;
    unsigned int field8c;
    unsigned int field90;
    unsigned int field94;
    unsigned int field98;
    unsigned int field9c;
    unsigned int fielda0;
    char pad2[0x20];
    unsigned int fieldc4;
    unsigned int fieldc8;
    unsigned int fieldcc;
    unsigned int fieldd0;
    char pad3[0x20];
    unsigned int fieldf4;
    unsigned int fieldf8;
    unsigned int fieldfc;
    unsigned int field100;
    char pad4[0x20];
    unsigned int field124;
    unsigned int field128;
    unsigned int field12c;
    unsigned int field130;

    void init();
};

void RakPeer::init()
{
    field84 = 0;
    field88 = 0;
    field8c = 0;
    field90 = 0;
    field94 = 0;
    field98 = 0;
    field9c = 0;
    fielda0 = 0;
    fieldc4 = 0;
    fieldc8 = 0;
    fieldcc = 0;
    fieldd0 = 0;
    fieldf4 = 0;
    fieldf8 = 0;
    fieldfc = 0;
    field100 = 0;
    field124 = 0;
    field128 = 0;
    field12c = 0;
    field130 = 0;
    field80 = 0;
}
