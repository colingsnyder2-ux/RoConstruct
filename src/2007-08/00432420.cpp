// from server: 100% by colin
struct CDataModelPropGrid {
    char pad[0xe0];
    unsigned char flag0;
    unsigned char flag1;
    void sub_4320E0();
    void sub_62FF4A(int);
    void sub_6305B6(void*, void*, void*);
    void target(void*, void*, void*);
};

void CDataModelPropGrid::target(void* a, void* b, void* c) {
    sub_6305B6(a, b, c);
    if (flag0 != 0 && flag1 == 0 && a != 0) {
        sub_4320E0();
        sub_62FF4A(9);
    }
}
