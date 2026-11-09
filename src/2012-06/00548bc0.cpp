// from server: 71% by colin
// roc-flags: /O2 /Ob2 /Oy /GS- /EHsc /MD
extern "C" void helper_00548bc0(void*,int,int,int);
void func_00548bc0(void* a,void* b,volatile int c) { if(c!=4){ int old=c; c=0; helper_00548bc0(b,(int)a,old,0); return; } *(int*)b=0xd83680; ((char*)b)[4]=0; ((char*)b)[5]=0; }
