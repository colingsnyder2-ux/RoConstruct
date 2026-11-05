// from server: 77% by Intel
struct CRobloxApp {
    int field_20;
    int field_110;
    int field_111;
    int method_46d940();
};

extern "C" void __stdcall sub_982d80();

int CRobloxApp::method_46d940() {
    int eax = this->field_20;
    if (!eax) {
        sub_982d80();
    }
    if (!*(char*)(eax + 0x110)) {
        if (!*(char*)(eax + 0x111)) {
            sub_982d80();
        }
    }
    return 0;
}
