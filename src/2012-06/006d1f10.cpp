// from server: 92% by Xemicl
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /arch:SSE
struct S { int n; int pad; double v; };
struct CB { double* b; double* e; double* f; double* l; int sz; void run(S* s); };
void CB::run(S* s) {
  double* p = sz ? f : 0;
  if (!p) return;
  do {
    if (*p > s->v) ++s->n;
    p += 1;
    if (p == e) p = b;
  } while (p != l && p);
}
