// from server: 100% by colin
struct CRobloxReportView {
    CRobloxReportView* construct(int arg);
};

extern "C" void __stdcall sub_4552B0(int arg);

CRobloxReportView* CRobloxReportView::construct(int arg) {
    sub_4552B0(arg);
    *(int*)((char*)this + 0x00) = 0x792594;
    *(int*)((char*)this + 0x04) = 0x79258c;
    *(int*)((char*)this + 0x10) = 0x792584;
    *(int*)((char*)this + 0x14) = 0x792574;
    *(int*)((char*)this + 0x2c) = 0x792564;
    *(int*)((char*)this + 0x44) = 0x792554;
    *(int*)((char*)this + 0x5c) = 0x792544;
    *(int*)((char*)this + 0x74) = 0x792534;
    *(int*)((char*)this + 0x8c) = 0x792524;
    return this;
}
