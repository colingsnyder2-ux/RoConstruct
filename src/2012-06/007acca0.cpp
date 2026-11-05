// from server: 72% by colin
// roc-flags: /O2 /Ob2 /Oy /GF- /GS- /EHsc /MD
extern unsigned char g_007acca0; extern int s_007acca0; extern int (*cb_007acca0)(void*,void*,int); extern "C" void helper_007acca0(int,void*);
void* func_007acca0() { if(g_007acca0==0 && s_007acca0!=0x29 && cb_007acca0 && !cb_007acca0((void*)0xb42fa8,(void*)0xb440b8,253)) helper_007acca0(g_007acca0,(void*)0xb44040); return (void*)0xe1c298; }
