// from server: 100% by colin
struct CXTPStatusBar {
    int sub_6923D0();
    void sub_63023E();
    int func(int);
};

int CXTPStatusBar::func(int arg) {
    if (this->sub_6923D0() == 0) {
        this->sub_63023E();
    } else {
        return 1;
    }
}
