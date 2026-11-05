// from server: 20% by atomic.potato
struct S {
    char pad[0x168];
    int field168;
    int f();
};

extern "C" int __cdecl sub_699880(int);
extern "C" int __cdecl sub_6cc860(int, int);
extern "C" int __cdecl sub_784020(int, int, int, int);
extern "C" void __cdecl sub_5ea3e0(int);

int S::f() {
    int v1 = sub_699880((int)this);
    if (v1 == 0)
        return 0;
    int a = 0;
    int b = 0;
    int c = 0;
    int d = 0;
    int e = this->field168;
    sub_6cc860((int)&a, (int)&d);
    if ((*(unsigned char*)0xb7cc2c & 1) == 0) {
        *(unsigned int*)0xb7cc2c |= 1;
        *(float*)0xb7cc20 = 0.0f;
        *(float*)0xb7cc24 = 0.0f;
        *(float*)0xb7cc28 = 0.0f;
    }
    sub_784020((int)&b, (int)&c, (int)0xb7cc20, v1);
    sub_5ea3e0(c);
    return 0;
}
