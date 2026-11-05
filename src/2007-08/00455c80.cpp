// from server: 31% by colin
struct CRobloxReportPaneView
{
    char pad[0x318];
    int field_318;
    void sub_00455ab0();
    ~CRobloxReportPaneView();
};

extern "C" void __stdcall sub_004073f0(int* p);

CRobloxReportPaneView::~CRobloxReportPaneView()
{
    sub_004073f0(&field_318);
    sub_00455ab0();
}
