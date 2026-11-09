// from server: 72% by colin
// roc-flags: /O2 /Ob2 /Oy /GF- /GS- /EHsc /MD
extern unsigned char g_008ad890; extern int s_008ad890; extern int (*cb_008ad890)(void*,void*,int); extern "C" void helper_008ad890(int,void*);
void* func_008ad890() { if(g_008ad890==0 && s_008ad890!=0x29 && cb_008ad890 && !cb_008ad890((void*)0xb42fa8,(void*)0xb440b8,253)) helper_008ad890(g_008ad890,(void*)0xb44040); return (void*)0xe32b50; }
