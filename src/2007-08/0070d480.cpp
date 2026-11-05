// from server: 52% by colin
// roc 2007-08 0070d480  unit: seg_00700000  size: 64 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 0070d480

extern "C" int __stdcall BitBlt(int, int, int, int, int, int, int, int, unsigned long);
extern "C" void __cdecl sub_680880();

struct CXTColorLum {
    void sub_70D480(int);
};

void CXTColorLum::sub_70D480(int a2) {
    BitBlt(0, a2, *(int*)(a2 + 4), 0, 0, 0, 0, 0, 0);
    *(int*)((char*)this + 0x80) = -1;
    sub_680880();
}
