// from server: 100% by colin
// roc 2007-08 004668f0  unit: CWebToolbox  size: 19 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 004668f0

extern "C" void __cdecl helper_63023e();

struct CWebToolbox {
    void setValue(int* p);
};

void CWebToolbox::setValue(int* p) {
    helper_63023e();
    p[3] = 0x32;
}
