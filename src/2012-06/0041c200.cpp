// from server: 100% by Xemicl
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
struct Base { virtual ~Base() {} }; struct VT { void (*manager)(void*, void*, int); void clear(void* b) { if (manager) manager(b, b, 2); } }; struct __declspec(novtable) D : Base { int pad[3]; bool engaged; int pad2; VT* vt; int pad3; char buf[16]; virtual ~D(); }; D::~D() { if (engaged) { if (vt) { vt->clear(buf); vt = 0; } engaged = false; } }
