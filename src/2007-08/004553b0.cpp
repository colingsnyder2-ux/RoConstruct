// from server: 100% by colin
struct CRobloxReportView {
    char pad[0x90];
    CRobloxReportView* ctor();
};

extern "C" void __stdcall sub_455350(void*);

CRobloxReportView* CRobloxReportView::ctor()
{
    sub_455350((void*)0x792690);
    *(int*)((char*)this + 0x00) = 0x79264c;
    *(int*)((char*)this + 0x04) = 0x792644;
    *(int*)((char*)this + 0x10) = 0x79263c;
    *(int*)((char*)this + 0x14) = 0x79262c;
    *(int*)((char*)this + 0x2c) = 0x79261c;
    *(int*)((char*)this + 0x44) = 0x79260c;
    *(int*)((char*)this + 0x5c) = 0x7925fc;
    *(int*)((char*)this + 0x74) = 0x7925ec;
    *(int*)((char*)this + 0x8c) = 0x7925dc;
    return this;
}
