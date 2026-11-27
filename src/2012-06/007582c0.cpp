// from server: 85% by Xemicl
// roc-cl: 30729
// roc-flags: /O2 /GS- /EHsc /MD /arch:SSE /fp:fast
struct O { void setF(float); };
static int g1, g2;
struct D {
  char pad[0x198]; O* o; int pad2[2]; int v;
  float compute(); void notify(void*); void set(int);
};
void D::set(int a) { if (v != a) { O* p = o; v = a; p->setF(compute()); notify(&g1); notify(&g2); } }