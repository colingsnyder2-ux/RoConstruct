// from server: 85% by colin
struct CWebToolbox {
    char pad[0xf4];
    void* field_f4;
    void sub_4667E0(int, int, int);
};

extern "C" void __stdcall sub_6300BE(int, int, int);
extern "C" void __stdcall sub_630004(void*);

void CWebToolbox::sub_4667E0(int a1, int a2, int a3) {
    sub_6300BE(a1, a2, a3);
    void* p = field_f4;
    if (p != 0) {
        sub_630004(p);
    }
}
