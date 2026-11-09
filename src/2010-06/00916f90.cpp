// from server: 27% by atomic.potato
struct GfxBinding {
    char pad0[4];
    int field4;
    void sub_916a30();

    void sub_916f90(int a, int b);
};

extern "C" int __cdecl sub_916f20(int);
extern "C" void __cdecl sub_401a30(int);

void GfxBinding::sub_916f90(int a, int b) {
    if (!sub_916f20(this->field4)) {
        this->sub_916a30();
    }
    if (a) {
        sub_401a30(a);
    }
}
