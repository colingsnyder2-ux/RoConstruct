// from server: 71% by colin
// roc-flags: /O2 /Ob2 /Oy /GS- /EHsc /MD
extern "C" void helper_007e0820(void*,int,int,int);
void func_007e0820(void* a,void* b,volatile int c) { if(c!=4){ int old=c; c=0; helper_007e0820(b,(int)a,old,0); return; } *(int*)b=0xdd0fa0; ((char*)b)[4]=0; ((char*)b)[5]=0; }
