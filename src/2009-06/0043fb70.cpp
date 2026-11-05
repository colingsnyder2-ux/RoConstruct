// from server: 100% by EspClaude
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
struct V { int v; V(const V& o) : v(o.v) {} };
#pragma pack(push,1)
struct S {
    char pad[0x2e];
    V value;
    V get() const;
};
#pragma pack(pop)
V S::get() const { return value; }
