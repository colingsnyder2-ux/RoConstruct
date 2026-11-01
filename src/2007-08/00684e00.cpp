// from server: 100% by colin
struct CXTPPropExchange {
    CXTPPropExchange* Construct();
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
};

extern "C" void __stdcall sub_73833a();

CXTPPropExchange* CXTPPropExchange::Construct()
{
    sub_73833a();
    field24 = 0;
    field20 = 0;
    field2C = 0;
    field34 = 0;
    field30 = 0;
    field38 = 1;
    field3C = 1;
    *(int*)this = 0x7cf42c;
    field28 = 0x17;
    return this;
}
