// from server: 72% by colin
// roc-flags: /O2 /Ob2 /Oy /GF- /GS- /EHsc /MD
extern unsigned char g_00735c00; extern int s_00735c00; extern int (*cb_00735c00)(void*,void*,int); extern "C" void helper_00735c00(int,void*);
void* func_00735c00() { if(g_00735c00==0 && s_00735c00!=0x29 && cb_00735c00 && !cb_00735c00((void*)0xb42fa8,(void*)0xb440b8,253)) helper_00735c00(g_00735c00,(void*)0xb44040); return (void*)0xe18954; }
