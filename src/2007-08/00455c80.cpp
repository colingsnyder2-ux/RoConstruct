// from server: 40% by Intel




struct CRobloxReportPaneView;

void __stdcall sub_4073F0(void* thisptr);
void __stdcall sub_455AB0(void* thisptr);

struct CRobloxReportPaneView {
    void func_00455C80();
};

void CRobloxReportPaneView::func_00455C80()
{
    CRobloxReportPaneView* esi = this;
    if (esi != 0) {
        sub_4073F0(reinterpret_cast<char*>(esi) + 0x318);
    } else {
        sub_4073F0(0);
    }
    sub_455AB0(esi);
}
