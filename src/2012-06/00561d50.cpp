// from server: 94% by Xemicl
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
int __stdcall inner(int, int);
int gA, gB;
int __stdcall f(unsigned char v) { if (v == 4) { return inner(gA, 0); } else { return inner(gB, 0); } }
