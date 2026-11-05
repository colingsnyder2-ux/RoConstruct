// from server: 72% by colin
// roc-flags: /O2 /Ob2 /Oy /GF- /GS- /EHsc /MD
extern unsigned char g_008e1d90; extern int s_008e1d90; extern int (*cb_008e1d90)(void*,void*,int); extern "C" void helper_008e1d90(int,void*);
void* func_008e1d90() { if(g_008e1d90==0 && s_008e1d90!=0x29 && cb_008e1d90 && !cb_008e1d90((void*)0xb42fa8,(void*)0xb440b8,253)) helper_008e1d90(g_008e1d90,(void*)0xb44040); return (void*)0xe48afc; }
