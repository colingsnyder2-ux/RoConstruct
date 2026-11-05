// from server: 100% by colin
struct CWrapperView {
    char pad[0xe0];
    unsigned char flag0;
    unsigned char flag1;
    void sub_63023E();
    void sub_430800();
    void sub_62FF4A(int);
    void func(int, int);
};

void CWrapperView::func(int a, int b) {
    sub_63023E();
    if (flag0 != 0 && flag1 == 0 && a == 0) {
        sub_430800();
        sub_62FF4A(7);
    }
}
