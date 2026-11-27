// from server: 100% by Xemicl
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
struct C4 { float r, g, b, a; };
extern const C4 k;
C4 g = k;
