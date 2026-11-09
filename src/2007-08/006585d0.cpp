// from server: 100% by colin
struct CXTPReportControl {
    void sub_660740();
    void sub_63023e();
    void func(int);
};

void CXTPReportControl::func(int) {
    if (*(int*)((char*)this + 0x168) != 0) {
        (*(CXTPReportControl**)((char*)this + 0x200))->sub_660740();
    }
    sub_63023e();
}
