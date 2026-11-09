// from server: 100% by tajop
// roc 2007-08 0070a090  size: 61 bytes

extern "C" __declspec(dllimport) void* __stdcall GetFocus();
extern "C" void* __stdcall sub_6301C0(void*);

struct CXTColorHex {
    void sub_709F50(int, int);
    void sub_630004();
    void sub_63023E();
    void func(int, int, int);
};

void CXTColorHex::func(int a, int b, int c)
{
    if (sub_6301C0(GetFocus()) != (void*)this)
        sub_630004();
    sub_709F50(b, c);
    *(int*)((char*)this + 0x68) = 1;
    sub_63023E();
}
