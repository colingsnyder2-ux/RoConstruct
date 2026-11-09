// from server: 43% by colin
struct S {
    int f();
};

extern "C" void __cdecl sub_4015A0(int, int);
extern "C" void __cdecl sub_9831F5(int);

int S::f() {
    *(int*)this = 0;
    sub_4015A0(0xe25c1c, 0x5ab850);
    if (!(*(unsigned char*)0xe25c0c & 1)) {
        *(unsigned int*)0xe25c0c |= 1;
        *(unsigned int*)0xe25c04 = 0;
        *(unsigned int*)0xe25c08 = 0;
        sub_9831F5(0xb14a30);
    }
    return (int)this;
}
