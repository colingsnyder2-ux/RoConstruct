// from server: 45% by atomic.potato
struct S {
    void* field0;
    void f(char);
};

extern "C" void __stdcall sub_40bb90(void*, char);

void S::f(char c) {
    void* p = field0;
    if (p) {
        sub_40bb90((void*)0x5d5fe0, c);
    }
}
