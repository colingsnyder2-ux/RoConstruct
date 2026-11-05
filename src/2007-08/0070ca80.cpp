// from server: 100% by tajop
struct CXTColorBase {
    void sub_63023E();
    void sub_630004();
    void f(int, int, int);
};

extern "C" __declspec(dllimport) void* __stdcall GetFocus();
extern "C" void* __stdcall sub_6301C0(void*);

void CXTColorBase::f(int a, int b, int c)
{
    sub_63023E();
    if (a & 1) {
        (*(void (__thiscall**)(CXTColorBase*, int, int, int))(*(int*)this + 0x14c))(this, b, c, 1);
        if ((void*)sub_6301C0(GetFocus()) != this) {
            sub_630004();
        }
    }
}
