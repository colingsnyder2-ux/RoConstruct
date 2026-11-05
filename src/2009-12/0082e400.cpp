// from server: 100% by atomic.potato
struct S {
    char pad0[0x20];
    int f20;
    int f24;
    int f28;
    char pad2c[0x14];
    int f40;
    int f44;
    S(int);
};

extern "C" void __fastcall sub_926442(void*);
extern "C" void __fastcall sub_82d860(void*);

S::S(int a) {
    sub_926442(this);
    *(int*)this = 0x9f6334;
    f20 = a;
    sub_82d860((char*)this + 0x2c);
    f28 = 0;
    f40 = 0;
    f44 = 0;
    f24 = -1;
}
