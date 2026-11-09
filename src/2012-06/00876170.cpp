// from server: 72% by colin
// roc-flags: /O2 /Ob2 /Oy /GF- /GS- /EHsc /MD
extern unsigned char g_00876170; extern int s_00876170; extern int (*cb_00876170)(void*,void*,int); extern "C" void helper_00876170(int,void*);
void* func_00876170() { if(g_00876170==0 && s_00876170!=0x29 && cb_00876170 && !cb_00876170((void*)0xb42fa8,(void*)0xb440b8,253)) helper_00876170(g_00876170,(void*)0xb44040); return (void*)0xe300f4; }
