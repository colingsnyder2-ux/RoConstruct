// from server: 100% by colin
// roc-flags: /O2 /Ob2 /Oy /GS- /EHsc /MD
extern "C" void helper_006b6a80(void*,int,int,int);
void func_006b6a80(void* a,void* b,int c) { if(c!=4){ int old=c; *(volatile unsigned char*)&c=0; helper_006b6a80((void*)a,(int)b,old,c); return; } *(int*)b=0xc69158; ((char*)b)[4]=0; ((char*)b)[5]=0; }
