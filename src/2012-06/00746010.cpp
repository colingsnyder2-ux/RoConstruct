// from server: 100% by Xemicl
// roc-cl: 30729
// roc-flags: /O2 /GS- /EHsc /MD /arch:SSE
struct S{float x; short s; S f() const; }; S S::f() const { S r; r.x=-x; r.s=-s; return r; }
