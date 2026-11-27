// from server: 100% by Xemicl
// roc-cl: 50727
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
void destroy(void*, void*, void*); struct V{ int pad; char* b; char* e; char* c; ~V(){ if(b){ destroy(b,e,this); delete b; } b=0; e=0; c=0; } }; void f(V* p){ delete p; }
