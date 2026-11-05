// from server: 72% by colin
// roc-flags: /O2 /Ob2 /Oy /GF- /GS- /EHsc /MD
extern unsigned char g_008e3330; extern int s_008e3330; extern int (*cb_008e3330)(void*,void*,int); extern "C" void helper_008e3330(int,void*);
void* func_008e3330() { if(g_008e3330==0 && s_008e3330!=0x29 && cb_008e3330 && !cb_008e3330((void*)0xb42fa8,(void*)0xb440b8,253)) helper_008e3330(g_008e3330,(void*)0xb44040); return (void*)0xe48d0c; }
