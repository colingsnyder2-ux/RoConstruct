// from server: 100% by colin
struct CXTPControlGallery {
    char pad[0x218];
    int field_218;
    void sub_670f70(int);
    void sub_63c4a0(int);
    void func(int);
};

void CXTPControlGallery::func(int a) {
    if (this->field_218 != 0) {
        sub_63c4a0(0x1011);
        this->field_218 = 0;
    }
    sub_670f70(a);
}
