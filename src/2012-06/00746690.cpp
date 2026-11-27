// from server: 93% by Xemicl
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
struct B { int bits; bool f(int i); };
bool B::f(int i) { unsigned m = (i >= 0 && i <= 2) ? (1u << i) : 0u; return (bits & m) != 0; }
