// from server: 100% by colin
struct FactoryProduct {
    void construct(int);
    int field0;
    int field4;
    int field8;
    int fieldC;
    int field10;
    int field14;
    int field18;
    int field1C;
    int field20;
    int field24;
    int field28;
    int field2C;
    int field30;
    int field34;
    int field38;
    int field3C;
    int field40;
    int field44;
    int field48;
    int field4C;
    int field50;
    int field54;
    int field58;
    int field5C;
    int field60;
    int field64;
    int field68;
    int field6C;
    int field70;
    int field74;
    int field78;
    int field7C;
    int field80;
    int field84;
    int field88;
    int field8C;
    FactoryProduct* init(int);
};

FactoryProduct* FactoryProduct::init(int arg) {
    construct(arg);
    field0 = 0x7c1ce4;
    field4 = 0x7c1cdc;
    field10 = 0x7c1cd4;
    field14 = 0x7c1cc4;
    field2C = 0x7c1cb4;
    field44 = 0x7c1ca4;
    field5C = 0x7c1c94;
    field74 = 0x7c1c84;
    field8C = 0x7c1c74;
    return this;
}
