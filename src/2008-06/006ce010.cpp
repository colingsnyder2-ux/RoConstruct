// from server: 100% by tester
struct CXTPReportControl {
    void sub_738580();
    void sub_657410();
    void target();
};

void CXTPReportControl::target() {
    sub_738580();
    int* p = *(int**)((char*)this + 0x100);
    void (__thiscall *fn)(void*) = *(void (__thiscall **)(void*))((char*)*p + 0x58);
    fn(p);
    sub_657410();
}
