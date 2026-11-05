// from server: 96% by atomic.potato
struct S {
    char pad0[0x80];
    int field80;
    char pad1[0x0C];
    int field90;
    int field94;
    void f();
};

extern "C" int* __stdcall sub_799550(void*);

void S::f() {
    int tmp[2];
    field80 = 1;
    int* p = sub_799550(tmp);
    field90 = p[0];
    field94 = p[1];
}
