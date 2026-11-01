// from server: 87% by colin
struct CRobloxWnd {
    void sub_458560(int);
};

extern "C" void __stdcall sub_630922(int);
extern "C" void __stdcall sub_463af0(int);

void CRobloxWnd::sub_458560(int a) {
    sub_630922(a);
    int* p = *(int**)((char*)this + 0x74);
    if (p != 0) {
        sub_463af0(1);
    }
}
