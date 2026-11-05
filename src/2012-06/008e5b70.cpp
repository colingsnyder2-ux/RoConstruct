// from server: 72% by colin
// roc-flags: /O2 /Ob2 /Oy /GF- /GS- /EHsc /MD
extern unsigned char g_008e5b70; extern int s_008e5b70; extern int (*cb_008e5b70)(void*,void*,int); extern "C" void helper_008e5b70(int,void*);
void* func_008e5b70() { if(g_008e5b70==0 && s_008e5b70!=0x29 && cb_008e5b70 && !cb_008e5b70((void*)0xb42fa8,(void*)0xb440b8,253)) helper_008e5b70(g_008e5b70,(void*)0xb44040); return (void*)0xe487dc; }
