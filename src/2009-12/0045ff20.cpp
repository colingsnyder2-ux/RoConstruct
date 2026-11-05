// from server: 47% by atomic.potato
struct CRobloxView
{
    int field_210;
    void f();
};

extern "C" void __stdcall target(int, int);

void CRobloxView::f()
{
    int value = (field_210 == 0) ? 1 : 0;
    target(value, 1);
}
