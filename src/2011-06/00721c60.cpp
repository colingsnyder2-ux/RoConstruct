// from server: 100% by colin
// roc-flags: /O2 /Ob2 /Oy /GF- /GS- /EHsc /MD
extern "C" int helper(void*,int,void*,void*,int);
bool __stdcall func(void* p){return helper(p,0,(void*)0xc071f8,(void*)0xc52794,0)!=0;}
