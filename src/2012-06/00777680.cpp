// from server: 72% by colin
// roc-flags: /O2 /Ob2 /Oy /GF- /GS- /EHsc /MD
extern unsigned char g_00777680; extern int s_00777680; extern int (*cb_00777680)(void*,void*,int); extern "C" void helper_00777680(int,void*);
void* func_00777680() { if(g_00777680==0 && s_00777680!=0x29 && cb_00777680 && !cb_00777680((void*)0xb42fa8,(void*)0xb440b8,253)) helper_00777680(g_00777680,(void*)0xb44040); return (void*)0xe487c4; }
