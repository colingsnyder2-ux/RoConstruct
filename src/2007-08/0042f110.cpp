// from server: 100% by colin
struct CMainFrame {
    char pad[0xe0];
    unsigned char flag0;
    unsigned char flag1;
    void sub_63023e();
    void func(unsigned int* p);
};

void CMainFrame::func(unsigned int* p) {
    sub_63023e();
    if (flag0 != 0 && flag1 == 0) {
        p[6] |= 3;
    }
}
