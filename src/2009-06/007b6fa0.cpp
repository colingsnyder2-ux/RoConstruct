// from server: 100% by tester
struct CXTPMenuBar {
    char pad[52];
    int sub_6a6af0(int);
    int sub_6a2ce0(int);
    int sub_6301e4();
    void func(int);
};

void CXTPMenuBar::func(int arg) {
    int result = sub_6a6af0(arg);
    if (result != 0) {
        ((CXTPMenuBar*)((char*)this + 0x20))->sub_6a2ce0(arg);
        ((CXTPMenuBar*)result)->sub_6301e4();
    }
}
