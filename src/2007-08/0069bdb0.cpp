// from server: 100% by colin
struct CXTPPropertyGridView {
    void sub_63023E();
    void* sub_69BCA0(int, int);
    void sub_69AAF0(int, void*);
    void InsertItem(int, int, int);
};

void CXTPPropertyGridView::InsertItem(int a, int b, int c) {
    sub_63023E();
    void* p = sub_69BCA0(b, c);
    if (p) {
        void** vt = *(void***)p;
        void (__thiscall *fn)(void*, int, int, int) = (void (__thiscall *)(void*, int, int, int))vt[0x2e];
        fn(p, a, b, c);
        if (p == sub_69BCA0(b, c)) {
            sub_69AAF0(8, p);
        }
    }
}
