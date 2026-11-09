// from server: 100% by tester
struct CXTPReportColumn
{
    char pad0[0x64];
    int field_0x64;
    char pad1[0x38];
    int field_0xa0;
    int getSomething();
    int getValue();
};

int CXTPReportColumn::getValue()
{
    int r;
    if (field_0x64 == 0)
    {
        r = getSomething();
    }
    else
    {
        r = 0;
    }
    return field_0xa0 + r;
}
