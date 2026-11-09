// from server: 100% by tester
struct CXTPPropertyGrid {
    void f(int, int, int);
    void g();
    void* h();
};

extern "C" void __stdcall func_0063023e();

void CXTPPropertyGrid::f(int a, int b, int c)
{
    func_0063023e();
    void* p = h();
    if (p != 0 && *(int*)((char*)p + 0x20) != 0) {
        void (__thiscall *fn)(CXTPPropertyGrid*, int, int) =
            *(void (__thiscall **)(CXTPPropertyGrid*, int, int))((*(char**)this) + 0x158);
        fn(this, b, c);
    }
}
