// from server: 72% by colin
// roc-flags: /O2 /Ob2 /Oy /GF- /GS- /EHsc /MD
extern unsigned char g_008e5ab0; extern int s_008e5ab0; extern int (*cb_008e5ab0)(void*,void*,int); extern "C" void helper_008e5ab0(int,void*);
void* func_008e5ab0() { if(g_008e5ab0==0 && s_008e5ab0!=0x29 && cb_008e5ab0 && !cb_008e5ab0((void*)0xb42fa8,(void*)0xb440b8,253)) helper_008e5ab0(g_008e5ab0,(void*)0xb44040); return (void*)0xe4873c; }
