// from server: 100% by Xemicl
// roc-cl: 50727
// roc-flags: /O2 /Ob2 /Oi /Ot /Oy /GF /GS- /EHsc /MT
struct S{char pad[0x60];int a;char pad2[0xf4];int arr[1]; int f(unsigned i);}; int S::f(unsigned i){ if(i==0) return a; return arr[i]; }
