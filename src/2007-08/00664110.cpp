// from server: 100% by colin
struct VCXTPReportRows_CXTPHeapObjectT {
    char pad[0x20];
    int field20;
    int field24;
    int field28;
    char pad2[0x14];
    int field40;
    char pad3[0x0c];
    int field50;

    VCXTPReportRows_CXTPHeapObjectT* construct(int);
};

extern "C" void __fastcall sub_73833a(void*);
extern "C" void __fastcall sub_663dd0(void*);

VCXTPReportRows_CXTPHeapObjectT* VCXTPReportRows_CXTPHeapObjectT::construct(int arg) {
    sub_73833a(this);
    *(int*)this = 0x7c971c;
    this->field20 = arg;
    sub_663dd0((char*)this + 0x2c);
    this->field28 = 0;
    this->field40 = 0;
    this->field24 = -1;
    return this;
}
