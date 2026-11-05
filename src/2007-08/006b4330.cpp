// from server: 100% by colin
struct CXTPControlGallery {
    char pad[0x178];
    void sub_6B3D90(int, int);
    void f();
};

void CXTPControlGallery::f() {
    ((CXTPControlGallery*)((char*)this - 0x178))->sub_6B3D90(0, 1);
}
