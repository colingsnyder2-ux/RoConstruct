// from server: 72% by colin
// roc-flags: /O2 /Ob2 /Oy /GF- /GS- /EHsc /MD
extern unsigned char g_007a7520; extern int s_007a7520; extern int (*cb_007a7520)(void*,void*,int); extern "C" void helper_007a7520(int,void*);
void* func_007a7520() { if(g_007a7520==0 && s_007a7520!=0x29 && cb_007a7520 && !cb_007a7520((void*)0xb42fa8,(void*)0xb440b8,253)) helper_007a7520(g_007a7520,(void*)0xb44040); return (void*)0xe1c198; }
