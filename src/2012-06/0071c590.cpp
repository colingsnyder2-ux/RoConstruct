// from server: 72% by colin
// roc-flags: /O2 /Ob2 /Oy /GF- /GS- /EHsc /MD
extern unsigned char g_0071c590; extern int s_0071c590; extern int (*cb_0071c590)(void*,void*,int); extern "C" void helper_0071c590(int,void*);
void* func_0071c590() { if(g_0071c590==0 && s_0071c590!=0x29 && cb_0071c590 && !cb_0071c590((void*)0xb42fa8,(void*)0xb440b8,253)) helper_0071c590(g_0071c590,(void*)0xb44040); return (void*)0xe18714; }
