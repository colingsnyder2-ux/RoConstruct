// from server: 72% by colin
// roc-flags: /O2 /Ob2 /Oy /GF- /GS- /EHsc /MD
extern unsigned char g_00735450; extern int s_00735450; extern int (*cb_00735450)(void*,void*,int); extern "C" void helper_00735450(int,void*);
void* func_00735450() { if(g_00735450==0 && s_00735450!=0x29 && cb_00735450 && !cb_00735450((void*)0xb42fa8,(void*)0xb440b8,253)) helper_00735450(g_00735450,(void*)0xb44040); return (void*)0xe18958; }
