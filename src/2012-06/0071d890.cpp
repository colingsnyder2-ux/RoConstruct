// from server: 73% by colin
// roc-flags: /O2 /Ob2 /Oy /GS- /EHsc /MD
extern "C" void helper_0071d890(void*,int,int,int);
void func_0071d890(void* a,void* b,volatile int c) { if(c!=4){ int old=c; c=0; helper_0071d890(b,(int)a,old,0); return; } *(int*)b=0xdad700; ((char*)b)[4]=0; ((char*)b)[5]=0; }
