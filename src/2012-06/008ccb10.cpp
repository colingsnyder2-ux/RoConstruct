// from server: 72% by colin
// roc-flags: /O2 /Ob2 /Oy /GF- /GS- /EHsc /MD
extern unsigned char g_008ccb10; extern int s_008ccb10; extern int (*cb_008ccb10)(void*,void*,int); extern "C" void helper_008ccb10(int,void*);
void* func_008ccb10() { if(g_008ccb10==0 && s_008ccb10!=0x29 && cb_008ccb10 && !cb_008ccb10((void*)0xb42fa8,(void*)0xb440b8,253)) helper_008ccb10(g_008ccb10,(void*)0xb44040); return (void*)0xe48730; }
