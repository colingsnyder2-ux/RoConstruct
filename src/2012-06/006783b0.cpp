// from server: 100% by Xemicl
// roc-cl: 30729
// roc-flags: /O2 /GS- /EHsc /MD
struct String;
extern void (__thiscall *destroyString)(String*);
struct String { char b[28]; ~String() { destroyString(this); } };
struct DummyArbiter {
    char pad[0xc]; String a; char pad2[0x30 - 0xc - 28]; String b;
    ~DummyArbiter();
};
DummyArbiter::~DummyArbiter() {}