// from server: 72% by colin
// roc-flags: /O2 /Ob2 /Oy /GF- /GS- /EHsc /MD
extern unsigned char g_008c8270; extern int s_008c8270; extern int (*cb_008c8270)(void*,void*,int); extern "C" void helper_008c8270(int,void*);
void* func_008c8270() { if(g_008c8270==0 && s_008c8270!=0x29 && cb_008c8270 && !cb_008c8270((void*)0xb42fa8,(void*)0xb440b8,253)) helper_008c8270(g_008c8270,(void*)0xb44040); return (void*)0xe488c8; }
