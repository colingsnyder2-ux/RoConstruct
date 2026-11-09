// from server: 72% by colin
// roc-flags: /O2 /Ob2 /Oy /GF- /GS- /EHsc /MD
extern unsigned char g_007d12c0; extern int s_007d12c0; extern int (*cb_007d12c0)(void*,void*,int); extern "C" void helper_007d12c0(int,void*);
void* func_007d12c0() { if(g_007d12c0==0 && s_007d12c0!=0x29 && cb_007d12c0 && !cb_007d12c0((void*)0xb42fa8,(void*)0xb440b8,253)) helper_007d12c0(g_007d12c0,(void*)0xb44040); return (void*)0xe214fc; }
