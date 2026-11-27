// from server: 86% by Xemicl
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
struct VT{ void (*mgr)(void*,void*,int); }; struct F{ char pad[0x10]; bool on; char p2[7]; VT* vt; char p3[4]; char buf[16]; void reset(); }; void F::reset(){ if(on){ if(vt){ if(vt->mgr) vt->mgr(buf,buf,2); vt=0; } on=false; } }
