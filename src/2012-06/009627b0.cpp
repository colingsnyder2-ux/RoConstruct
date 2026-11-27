// from server: 100% by Xemicl
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
struct Stage; struct Item { void setStage(Stage*); virtual void v0(); virtual void v1(int); }; struct Stage { virtual void a(); virtual void b(); virtual int c(); void f(Item* it); }; void Stage::f(Item* it) { it->setStage(this); it->v1(c()); }
