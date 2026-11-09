// from server: 66% by colin
// roc-flags: /O2 /Ob2 /Oy /GF- /GS- /EHsc /MD
extern unsigned char g_00876d90; extern int s_00876d90; extern int (*cb_00876d90)(void*,void*,int); extern "C" void helper_00876d90(int,void*);
void* func_00876d90() { if(g_00876d90==0 && s_00876d90!=0x29 && cb_00876d90 && !cb_00876d90((void*)0xb42fa8,(void*)0xb440b8,253)) helper_00876d90(g_00876d90,(void*)0xb44040); return (void*)0xe300e8; }
