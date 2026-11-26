// from server: 100% by Xemicl
// from server: 100% by atomic.potato
// roc 2012-06 00743130  unit: RBX::PartTool  size: 30 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00743130
//
// 00743130  8b4130               mov eax, dword ptr [ecx + 0x30]
// 00743133  85c0                 test eax, eax
// 00743135  7414                 je 0x74314b
// 00743137  8b542404             mov edx, dword ptr [esp + 4]
// 0074313b  8d889c000000         lea ecx, [eax + 0x9c]
// 00743141  8b01                 mov eax, dword ptr [ecx]
// 00743143  8b4020               mov eax, dword ptr [eax + 0x20]
// 00743146  6a00                 push 0
// 00743148  52                   push edx
// 00743149  ffd0                 call eax
// 0074314b  c20400               ret 4

struct Inner {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void Target(int arg, int arg2);
};

struct Holder {
    char pad[0x9c];
    Inner inner;
};

struct PartTool {
    char pad[0x30];
    Holder* h;
    void DoIt(int arg);
};

void PartTool::DoIt(int arg) {
    Holder* hp = this->h;
    if (hp) {
        hp->inner.Target(arg, 1);
    }
}
