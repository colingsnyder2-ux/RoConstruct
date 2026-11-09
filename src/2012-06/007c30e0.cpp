// from server: 54% by atomic.potato
struct MegaClusterInstance {
    char gap_31C;
    void f1();
    void f2(int);
};

extern "C" void __cdecl sub_759320(int);
extern "C" void sub_7C2220(MegaClusterInstance*);

void MegaClusterInstance::f2(int arg) {
    if (!this->gap_31C) {
        sub_759320(arg);
        this->gap_31C = 1;
        sub_7C2220(this);
    }
}
