// from server: 100% by colin
// roc 2007-08 00697fd0  size: 49 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 00697fd0

extern "C" int __stdcall sub_6713d0(void*);

struct CPropertyGridItemBrickColor {
    int f(int, int, int, int, void*);
};

int CPropertyGridItemBrickColor::f(int a, int b, int c, int d, void* out) {
    unsigned short* p = (unsigned short*)out;
    *p = 0;
    int r = sub_6713d0(&a);
    if (r == 0) {
        *p = 3;
        *(int*)((char*)out + 8) = 0x1c;
        return 0;
    }
    return (int)0x80070057;
}
