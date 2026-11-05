// from server: 100% by atomic.potato
struct CXTColorHex_PAUHEXCOLOR_CELL_CList {
    char pad[0x74];
    int field_74;
    void sub_787820(int, int);
    void sub_787A30(int);
};

struct Sub6E5270 {
    int sub_6E5270(int);
};

void CXTColorHex_PAUHEXCOLOR_CELL_CList::sub_787A30(int a) {
    if (a != -1) {
        int r = ((Sub6E5270*)&field_74)->sub_6E5270(a);
        int* p = *(int**)(r + 8);
        if (p != 0) {
            int* q = *(int**)((char*)p + 0x14);
            int v0 = q[0];
            int v1 = q[1];
            sub_787820(v0, v1);
        }
    }
}
