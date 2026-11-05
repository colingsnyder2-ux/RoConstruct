// from server: 71% by colin
// roc-flags: /O2 /Ob2 /Oy /GS- /EHsc /MD
extern "C" void helper_00800760(void*,int,int,int);
void func_00800760(void* a,void* b,volatile int c) { if(c!=4){ int old=c; c=0; helper_00800760(b,(int)a,old,0); return; } *(int*)b=0xdd6ec0; ((char*)b)[4]=0; ((char*)b)[5]=0; }
