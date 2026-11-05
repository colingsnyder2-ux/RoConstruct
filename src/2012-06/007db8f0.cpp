// from server: 69% by atomic.potato
struct S {
    char pad[0x80];
    double value;
    char pad2[4];
    void method(int);
};

extern "C" void __stdcall sub_539620(double);

void S::method(int) {
    sub_539620(value);
}
