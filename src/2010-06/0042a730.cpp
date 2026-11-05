// from server: 68% by atomic.potato
// roc 2010-06 0042a730  unit: CWrapperView  size: 146 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 0042a730

extern "C" __declspec(dllimport) int __stdcall OffsetRect(int*, int, int);

struct CRect {
    int left;
    int top;
    int right;
    int bottom;
};

struct CWrapperView {
    char pad0[0xec];
    int field_ec;
    char pad1[0x100 - 0xf0];
    int field_100;
    char pad2[0x180 - 0x104];
    int field_180;

    void func(int a, int b);
};

extern "C" int __stdcall sub_7a83a8(int, int, int, int, int, int, int);
extern "C" void __stdcall sub_7ff2b0(CRect*, int);
extern "C" void __stdcall sub_7c8270(int, int, int, int);

void CWrapperView::func(int a, int b)
{
    CRect r1;
    CRect r2;
    sub_7a83a8(0xe800, 0xe8ff, 0xe900, 0, 0, 0, 1);
    sub_7ff2b0(&r1, a);
    int v = *(int*)((char*)a + 0x100);
    if (v == 2 || v == 3 || v == 5) {
        int w = r1.right - r1.left;
        OffsetRect((int*)&r2, 0, w);
    } else {
        int h = r1.bottom - r1.top;
        OffsetRect((int*)&r2, h, 0);
    }
    sub_7c8270(field_ec, b, *(int*)((char*)a + 0x180), *(int*)&r2);
}
