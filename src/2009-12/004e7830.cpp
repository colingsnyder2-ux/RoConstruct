// from server: 31% by atomic.potato
// roc 2009-12 004e7830  unit: seg_004e0000  size: 60 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 004e7830

extern "C" void __stdcall _invalid_parameter_noinfo();

struct S {
    void* field0;
    void* field4;
    void init(void* a, void* b);
};

void S::init(void* a, void* b) {
    field0 = 0;
    field4 = a;
    if (b == 0) {
        _invalid_parameter_noinfo();
    }
    field0 = *(void**)b;
}
