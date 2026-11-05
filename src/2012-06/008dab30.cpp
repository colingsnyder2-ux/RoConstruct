// from server: 72% by colin
// roc-flags: /O2 /Ob2 /Oy /GF- /GS- /EHsc /MD
extern unsigned char g_008dab30; extern int s_008dab30; extern int (*cb_008dab30)(void*,void*,int); extern "C" void helper_008dab30(int,void*);
void* func_008dab30() { if(g_008dab30==0 && s_008dab30!=0x29 && cb_008dab30 && !cb_008dab30((void*)0xb42fa8,(void*)0xb440b8,253)) helper_008dab30(g_008dab30,(void*)0xb44040); return (void*)0xe48a4c; }
