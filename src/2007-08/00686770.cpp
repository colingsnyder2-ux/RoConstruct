// from server: 100% by colin
struct CXTPPropExchange
{
    void Construct();
    int field_0;
    int field_4;
    int field_8;
    int field_c;
    int field_10;
    int field_14;
    int field_18;
    int field_1c;
    int field_20;
    int field_24;
    int field_28;
    int field_2c;
    int field_30;
    int field_34;
    int field_38;
    int field_3c;
    int field_40;
    CXTPPropExchange* Init(int* p);
};

CXTPPropExchange* CXTPPropExchange::Init(int* p)
{
    Construct();
    field_40 = (int)p;
    field_0 = 0x7cf56c;
    field_24 = p[6] & 1;
    return this;
}
