// from server: 100% by atomic.potato
struct VCXTPReportRows
{
    void* vfptr;
    char pad0[0x1c];
    int field20;
    int field24;
    int field28;
    char pad1[0x14];
    int field40;
    int field44;
    char pad2[0x14];
    void sub_752b10();
    void sub_84bf2a();
    VCXTPReportRows* ctor(int);
};

VCXTPReportRows* VCXTPReportRows::ctor(int arg)
{
    sub_84bf2a();
    vfptr = (void*)0x8f5e8c;
    field20 = arg;
    ((VCXTPReportRows*)((char*)this + 0x2c))->sub_752b10();
    field28 = 0;
    field40 = 0;
    field44 = 0;
    field24 = -1;
    return this;
}
