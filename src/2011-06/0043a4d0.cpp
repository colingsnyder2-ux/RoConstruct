// from server: 90% by atomic.potato
struct S {
    char pad[0x100];
    char flag;
    void f();
};

extern "C" void __stdcall sub_43a3a0(unsigned char);

void S::f() {
    sub_43a3a0((unsigned char)(flag == 0));
}
