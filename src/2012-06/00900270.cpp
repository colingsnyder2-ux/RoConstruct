// from server: 100% by Xemicl
// roc-cl: 30729
// roc-flags: /O2 /GS- /EHsc /MD /arch:SSE
struct Q{ bool g(); }; struct A{ int p; Q* q; float f10_[1]; }; struct X{ char p[8]; Q* q; char r[4]; float v; bool f(){ if(q->g()){ v=0.0f; return true;} return false; } }; bool k(X*x){return x->f();}
