// from server: 100% by EspClaude
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
struct Val {
    int v;
    Val(const Val& o) : v(o.v) {}
};
#pragma pack(push, 2)
struct S {
    char pad[0x2a];
    Val value;
    Val get() const;
};
#pragma pack(pop)
Val S::get() const { return value; }
