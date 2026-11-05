// from server: 72% by colin
// roc-flags: /O2 /Ob2 /Oy /GF- /GS- /EHsc /MD
extern unsigned char g_006d3170; extern int s_006d3170; extern int (*cb_006d3170)(void*,void*,int); extern "C" void helper_006d3170(int,void*);
void* func_006d3170() { if(g_006d3170==0 && s_006d3170!=0x29 && cb_006d3170 && !cb_006d3170((void*)0xb42fa8,(void*)0xb440b8,253)) helper_006d3170(g_006d3170,(void*)0xb44040); return (void*)0xe300ec; }
