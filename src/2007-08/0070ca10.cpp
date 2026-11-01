// from server: 83% by colin
extern "C" {
    void* __stdcall GetFocus();
    void* __stdcall SetCapture(void*);
}

struct CXTColorBase {
    void sub_63023E();
    void sub_6301C0(void*);
    void sub_630004();
    void method(int, int, int);
};

void CXTColorBase::method(int a, int b, int c) {
    sub_63023E();
    sub_6301C0(SetCapture(*(void**)((char*)this + 0x20)));
    void* (CXTColorBase::*fn)(int, int, int) = *(void* (CXTColorBase::**)(int, int, int))((*(char**)this) + 0x14c);
    (this->*fn)(a, b, 1);
    sub_6301C0(GetFocus());
    if (this != 0) {
        sub_630004();
    }
}
