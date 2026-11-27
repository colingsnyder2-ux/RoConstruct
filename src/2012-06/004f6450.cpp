// from server: 100% by Xemicl
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
struct T { char pad[0x20]; T(int a, int b, int c); };
T* make(int a, int b, int c) { return new T(a, b, c); }
