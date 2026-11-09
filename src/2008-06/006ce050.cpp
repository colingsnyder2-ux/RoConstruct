// from server: 100% by tester
struct CXTPReportControl {
    void sub_63023E();
    void sub_657410();
    void Method(int arg);
};

void CXTPReportControl::Method(int arg) {
    sub_63023E();
    void (CXTPReportControl::*pmf)() = *(void (CXTPReportControl::**)())(*(int*)this + 0x214);
    (this->*pmf)();
    sub_657410();
}
