// from server: 79% by atomic.potato
struct CRobloxView
{
    char pad[0xa0];
    int field_a0;
    void func_0045f4f0(int);
};

extern "C" void __stdcall sub_7f468e(int);
extern "C" void* __stdcall sub_7f3b4e(int, void*);
extern "C" void __stdcall sub_7f4688(void*);
extern "C" void __stdcall sub_7f3c02(void*);

void CRobloxView::func_0045f4f0(int a1)
{
    sub_7f468e(a1);
    sub_7f4688(sub_7f3b4e(0, this));
    sub_7f3c02(&field_a0);
}
