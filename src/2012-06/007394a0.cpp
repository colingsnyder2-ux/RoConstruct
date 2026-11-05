// from server: 72% by colin
// roc-flags: /O2 /Ob2 /Oy /GF- /GS- /EHsc /MD
extern unsigned char g_007394a0; extern int s_007394a0; extern int (*cb_007394a0)(void*,void*,int); extern "C" void helper_007394a0(int,void*);
void* func_007394a0() { if(g_007394a0==0 && s_007394a0!=0x29 && cb_007394a0 && !cb_007394a0((void*)0xb42fa8,(void*)0xb440b8,253)) helper_007394a0(g_007394a0,(void*)0xb44040); return (void*)0xe18950; }
