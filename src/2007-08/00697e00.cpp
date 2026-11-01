// from server: 100% by colin
struct CXTPPropertyGridItem {
    int GetValue(int* p);
};

int CXTPPropertyGridItem::GetValue(int* p) {
    int v = *(int*)((char*)this + 0xf4);
    if (v != -1) {
        *(int*)((char*)p + 0x10) = v;
        return v;
    }
    int n = *(int*)((char*)this + 0xf8);
    if (n > 1) {
        int t = *(int*)((char*)p + 0x10);
        t = (t - 4) * n + 4;
        *(int*)((char*)p + 0x10) = t;
    }
    return n;
}
