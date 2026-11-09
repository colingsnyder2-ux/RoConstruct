// from server: 72% by colin
// roc-flags: /O2 /Ob2 /Oy /GF- /GS- /EHsc /MD
extern unsigned char g_007479c0; extern int s_007479c0; extern int (*cb_007479c0)(void*,void*,int); extern "C" void helper_007479c0(int,void*);
void* func_007479c0() { if(g_007479c0==0 && s_007479c0!=0x29 && cb_007479c0 && !cb_007479c0((void*)0xb42fa8,(void*)0xb440b8,253)) helper_007479c0(g_007479c0,(void*)0xb44040); return (void*)0xe18a18; }
