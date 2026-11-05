// from server: 100% by colin
struct CXTPReportRow_Batch {
    char pad0[0x20];
    int field20;
    int field24;
    int field28;
    char pad2c[0x10];
    char field3c[0x10];
    int field4c;
    int field50;
    int field54;
    int field58;
    int field5c;
    int field60;
    int field64;
    int field68;
    int field6c;
    void sub_73833a();
    CXTPReportRow_Batch* construct();
};

extern void (__stdcall *g_SetRectEmpty)(void*);

CXTPReportRow_Batch* CXTPReportRow_Batch::construct()
{
    sub_73833a();
    void (__stdcall *fn)(void*) = g_SetRectEmpty;
    *(int*)this = 0x7d83d4;
    field20 = 0;
    field24 = 0;
    field4c = 0;
    field50 = 0;
    field54 = 0;
    field58 = 0;
    field5c = 0;
    field60 = 0;
    field64 = 1;
    fn((void*)((char*)this + 0x2c));
    fn((void*)((char*)this + 0x3c));
    field68 = 0;
    field28 = -1;
    field6c = -1;
    return this;
}
