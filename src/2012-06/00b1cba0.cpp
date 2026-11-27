// from server: 100% by Xemicl
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
struct Base { char pad[0x3c]; ~Base(); };
struct G : Base { char* a; char* b; char* c; char* d; ~G() { delete d; delete c; delete b; if (a) delete a; } };
static G g;