// from server: 72% by colin
// roc-flags: /O2 /Ob2 /Oy /GF- /GS- /EHsc /MD
extern unsigned char g_008d7400; extern int s_008d7400; extern int (*cb_008d7400)(void*,void*,int); extern "C" void helper_008d7400(int,void*);
void* func_008d7400() { if(g_008d7400==0 && s_008d7400!=0x29 && cb_008d7400 && !cb_008d7400((void*)0xb42fa8,(void*)0xb440b8,253)) helper_008d7400(g_008d7400,(void*)0xb44040); return (void*)0xe4887c; }
