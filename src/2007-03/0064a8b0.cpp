// from server: 100% by tester
typedef unsigned long DWORD;

struct CXTPReportControl {
    char pad[0x90];
    DWORD field_90;

    void SomeMethod();
};

void __stdcall sub_65e4a0(DWORD);

void CXTPReportControl::SomeMethod() {
    sub_65e4a0(this->field_90);
}
