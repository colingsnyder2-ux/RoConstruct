// from server: 72% by colin
// roc-flags: /O2 /Ob2 /Oy /GF- /GS- /EHsc /MD
extern unsigned char g_0080cb20; extern int s_0080cb20; extern int (*cb_0080cb20)(void*,void*,int); extern "C" void helper_0080cb20(int,void*);
void* func_0080cb20() { if(g_0080cb20==0 && s_0080cb20!=0x29 && cb_0080cb20 && !cb_0080cb20((void*)0xb42fa8,(void*)0xb440b8,253)) helper_0080cb20(g_0080cb20,(void*)0xb44040); return (void*)0xe24230; }
