// from server: 100% by tester
struct CXTPPropExchange
{
    char pad[0x20];
    int field_20;
    int field_24;
    int field_28;
    int field_2c;
    int field_30;
    int field_34;
    int field_38;
    int field_3c;
    void assign(CXTPPropExchange* other);
};

void CXTPPropExchange::assign(CXTPPropExchange* other)
{
    field_2c = 1;
    field_28 = other->field_28;
    field_20 = other->field_20;
    field_30 = other->field_30;
    field_38 = other->field_38;
    field_3c = other->field_3c;
}
