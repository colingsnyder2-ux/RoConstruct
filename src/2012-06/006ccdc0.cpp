// from server: 100% by Xemicl
// roc-cl: 30729
// roc-flags: /O2 /GS- /EHsc /MD
struct Settings { bool check(void*); };
struct S { void* a; void* b; void* c; Settings* settings; };
void* get();
void* f(S* p) { if (!p) return 0; Settings* s = p->settings; bool ok = s->check(get()); return ok ? (char*)p - 0x1c : 0; }
