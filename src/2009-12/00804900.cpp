// from server: 68% by atomic.potato
extern "C" void __stdcall func_008048d0(int, int, int);
extern "C" void __stdcall func_007f39da(int, int, int, int);

struct CXTPCommandBar {
    void f(int, int, int, int);
};

void CXTPCommandBar::f(int a, int b, int c, int d)
{
    func_008048d0(a, b, c);
    func_007f39da(a, b, c, d);
}
