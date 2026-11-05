// from server: 100% by tester
struct CNameItem {
    char pad[0x30];
    int field_0x30;
    int field_0x34;
    int field_0x38;
    int field_0x3c;
    void copyTo(int arg1, int* dst);
};

void CNameItem::copyTo(int arg1, int* dst) {
    int v;
    v = field_0x38;
    if (v != -1) {
        dst[10] = v;
    }
    v = field_0x34;
    if (v != -1) {
        dst[9] = v;
    }
    v = field_0x30;
    if (v == 0) {
        if (field_0x3c == 0) {
            return;
        }
        int* p = (int*)arg1;
        int* q = (int*)p[1];
        v = *(int*)((char*)q + 0xb0) + 0x28;
    }
    dst[8] = v;
}
