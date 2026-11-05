// from server: 72% by colin
// roc-flags: /O2 /Ob2 /Oy /GF- /GS- /EHsc /MD
extern unsigned char g_00777200; extern int s_00777200; extern int (*cb_00777200)(void*,void*,int); extern "C" void helper_00777200(int,void*);
void* func_00777200() { if(g_00777200==0 && s_00777200!=0x29 && cb_00777200 && !cb_00777200((void*)0xb42fa8,(void*)0xb440b8,253)) helper_00777200(g_00777200,(void*)0xb44040); return (void*)0xe1c974; }
