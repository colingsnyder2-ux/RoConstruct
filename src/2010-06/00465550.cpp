// from server: 100% by tester
struct CRobloxView {
    char pad[0x1f0];
    void* field_198;
    void sub_004566C0(int, int);
    void sub_004666E0(int);
    void func_00456820();
};

void CRobloxView::func_00456820()
{
    sub_004566C0(1, 1);
    ((CRobloxView*)field_198)->sub_004666E0(9);
}
