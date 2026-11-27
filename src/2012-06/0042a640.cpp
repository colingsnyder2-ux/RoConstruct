// from server: 85% by Xemicl
// roc-cl: 30729
// roc-flags: /O2 /GS- /EHsc /MD
struct W { virtual ~W(); };
struct T : W { char pad[0x34]; W* w38; char pad2[0x64]; void* a0; void* f(); };
void* T::f() { if (a0) return a0; if (dynamic_cast<T*>(w38) && dynamic_cast<T*>(w38)->f()) return (void*)1; return 0; }
