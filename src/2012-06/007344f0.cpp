// from server: 100% by Xemicl
// roc-cl: 30729
// roc-flags: /O2 /GS- /EHsc /MD
struct E { ~E(); char d[0x84]; };
struct S { E* p; ~S(); };
S::~S() { delete[] p; }
