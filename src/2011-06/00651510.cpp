// from server: 22% by atomic.potato
extern "C" {
    int __stdcall sub_6504B0(int, int);
    int __stdcall sub_6500B0(void*, void*);
    void __stdcall sub_A404B0();
    void __stdcall sub_A404B8();
    void __stdcall sub_A404D0();
}

struct S {
    char pad0[4];
    short field4;
    char pad6[0x2A];
    char field30;
    char pad31[3];
    void* field34;
    char pad38[8];
    int __cdecl method(int a, int b);
};

int S::method(int a, int b) {
    sub_6504B0(a, b);
    sub_A404B0();
    int v = field4;
    sub_6500B0(&v, &field30);
    sub_A404B8();
    sub_A404D0();
    return a;
}
