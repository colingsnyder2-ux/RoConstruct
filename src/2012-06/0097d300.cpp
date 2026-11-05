// from server: 36% by atomic.potato
// roc 2012-06 0097d300  unit: boost::iostreams::zlib_error  size: 86 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 0097d300

struct S {
    void f(int);
};

extern "C" void __stdcall sub_53fd50();
extern "C" void __stdcall sub_983144();
extern "C" void __stdcall sub_97d220();

void S::f(int a) {
    if (a == -4) {
        char buf[0x30];
        sub_53fd50();
        sub_983144();
    } else if (a < 0 || a > 1) {
        char buf[0x30];
        sub_97d220();
        sub_983144();
    }
}
