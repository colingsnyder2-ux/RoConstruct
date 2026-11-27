// from server: 84% by Xemicl
// roc-cl: 30729
// roc-flags: /O2 /GS- /EHsc /MD
struct Ring { char* buf; char* end; char* volatile cur; int pad; unsigned count; };
void f(Ring* r) { if (r) { unsigned i = 0; while (i < r->count) { i++; r->cur += 4; if (r->cur == r->end) r->cur = r->buf; } if (r->buf) delete r->buf; delete r; } }
