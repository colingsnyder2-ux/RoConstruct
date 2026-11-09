// from server: 72% by colin
// roc-flags: /O2 /Ob2 /Oy /GF- /GS- /EHsc /MD
extern unsigned char g_00693e60; extern int s_00693e60; extern int (*cb_00693e60)(void*,void*,int); extern "C" void helper_00693e60(int,void*);
void* func_00693e60() { if(g_00693e60==0 && s_00693e60!=0x29 && cb_00693e60 && !cb_00693e60((void*)0xb42fa8,(void*)0xb440b8,253)) helper_00693e60(g_00693e60,(void*)0xb44040); return (void*)0xe2cd14; }
