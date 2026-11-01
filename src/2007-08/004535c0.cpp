// from server: 100% by colin
struct CRobloxReportPaneView {
    CRobloxReportPaneView* construct(int);
};

extern "C" void __stdcall sub_005426b0(int);

CRobloxReportPaneView* CRobloxReportPaneView::construct(int a)
{
    sub_005426b0(a);
    *(int*)((char*)this + 0x00) = 0x791e6c;
    *(int*)((char*)this + 0x04) = 0x791e60;
    *(int*)((char*)this + 0x10) = 0x791e58;
    *(int*)((char*)this + 0x14) = 0x791e48;
    *(int*)((char*)this + 0x2c) = 0x791e38;
    *(int*)((char*)this + 0x44) = 0x791e28;
    *(int*)((char*)this + 0x5c) = 0x791e18;
    *(int*)((char*)this + 0x74) = 0x791e08;
    *(int*)((char*)this + 0x8c) = 0x791df8;
    return this;
}
