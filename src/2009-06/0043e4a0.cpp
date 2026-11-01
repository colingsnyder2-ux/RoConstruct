// from server: 78% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
struct N { N* find(int key); N* g(); };
struct Q { int x; int key; };
struct P { int a; int name; int b; Q* q; };
struct H { N* m; N* get(int k) const { return m ? m->find(k) : 0; } };
class C { char pad[0x8c]; H h; public: N* f(const P* p); };
N* C::f(const P* p) { if (N* r = h.get(p->q->key)) if (N* r2 = r->g()) return r2->find(p->name); return 0; }
