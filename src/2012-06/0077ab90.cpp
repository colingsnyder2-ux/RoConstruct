// from server: 74% by colin
// roc-flags: /O2 /Ob2 /Oy /GF- /GS- /EHsc /MD
extern unsigned char g_0077ab90; extern int s_0077ab90; extern int (*cb_0077ab90)(void*,void*,int); extern "C" void helper_0077ab90(int,void*);
void* func_0077ab90() { if(g_0077ab90==0 && s_0077ab90!=0x29 && cb_0077ab90 && !cb_0077ab90((void*)0xb42fa8,(void*)0xb440b8,253)) helper_0077ab90(g_0077ab90,(void*)0xb44040); return (void*)0xe48b00; }
