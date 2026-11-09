// from server: 100% by colin
extern "C" long (__stdcall *InterlockedIncrement)(long volatile*);

struct CXTPReportRow_Batch
{
    char pad_0000[0x20];
    int* field_20;
    int field_24;
    int field_28;
    int field_2c;
    int field_30;
    int field_34;
    int field_38;
    char pad_003c[0x18];
    int field_54;
    int field_58;
    char pad_005c[0x0c];
    int field_68;

    void assign(CXTPReportRow_Batch* other);
};

void CXTPReportRow_Batch::assign(CXTPReportRow_Batch* other)
{
    field_24 = other->field_24;
    field_20 = other->field_20;
    InterlockedIncrement((long*)(field_20 + 1));
    field_2c = other->field_2c;
    field_30 = other->field_30;
    field_34 = other->field_34;
    field_38 = other->field_38;
    field_28 = other->field_28;
    field_68 = other->field_68;
    field_54 = other->field_54;
    field_58 = other->field_58;
}
