// from server: 100% by colin
struct CBrowserView {
    void sub_40B070();

    void sub_40B2F0(int* a1, int* a2);
};

void CBrowserView::sub_40B2F0(int* a1, int* a2) {
    int* p = *(int**)((char*)a1 + 0xc);
    if (*(int*)((char*)p + 0xf8) == 5) {
        sub_40B070();
        *a2 = 1;
    }
}
