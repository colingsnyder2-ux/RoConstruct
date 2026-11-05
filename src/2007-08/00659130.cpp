// from server: 100% by colin
struct CXTPReportControl {
    void sub_63023E();
    void sub_657410();
    void Method(int arg);
};

void CXTPReportControl::Method(int arg) {
    sub_63023E();
    void (CXTPReportControl::*pmf)() = *(void (CXTPReportControl::**)())(*(int*)this + 0x1b8);
    (this->*pmf)();
    sub_657410();
}
