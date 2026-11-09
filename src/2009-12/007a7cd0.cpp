// from server: 75% by atomic.potato
struct S {
    int f0;
    int f4;
    char pad1[0x14];
    int f1c;
    int f20;
    char f24;
    char pad2[3];
    int f28;
    int f2c;
    S(int, char, int);
};

extern "C" void __stdcall sub_785a00(int);

S::S(int a, char b, int c) {
    sub_785a00(a);
    f0 = 0x9ed51c;
    f4 = 0x9ed500;
    f1c = 0;
    f20 = 0;
    f2c = 0;
    f24 = b;
    f28 = c;
}
