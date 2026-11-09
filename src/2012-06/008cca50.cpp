// from server: 72% by colin
// roc-flags: /O2 /Ob2 /Oy /GF- /GS- /EHsc /MD
extern unsigned char g_008cca50; extern int s_008cca50; extern int (*cb_008cca50)(void*,void*,int); extern "C" void helper_008cca50(int,void*);
void* func_008cca50() { if(g_008cca50==0 && s_008cca50!=0x29 && cb_008cca50 && !cb_008cca50((void*)0xb42fa8,(void*)0xb440b8,253)) helper_008cca50(g_008cca50,(void*)0xb44040); return (void*)0xe48798; }
