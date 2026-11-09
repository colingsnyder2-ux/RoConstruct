// from server: 100% by atomic.potato
struct CXTColorHex_PAUHEXCOLOR_CELL_CList {
    char pad[0x70];
    int field_70;
    char pad2[0x4];
    int field_78;
    void sub_787A30(int);
    void sub_787A70(int);
};

void CXTColorHex_PAUHEXCOLOR_CELL_CList::sub_787A70(int a) {
    field_70 = a;
    int* node = (int*)field_78;
    int idx = -1;
    while (node != 0) {
        int* inner = (int*)node[2];
        if (inner != 0 && a == inner[6]) {
            sub_787A30(idx);
        }
        node = (int*)node[0];
        idx++;
    }
}
