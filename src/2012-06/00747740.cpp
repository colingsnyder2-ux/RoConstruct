// from server: 72% by colin
// roc-flags: /O2 /Ob2 /Oy /GF- /GS- /EHsc /MD
extern unsigned char g_00747740; extern int s_00747740; extern int (*cb_00747740)(void*,void*,int); extern "C" void helper_00747740(int,void*);
void* func_00747740() { if(g_00747740==0 && s_00747740!=0x29 && cb_00747740 && !cb_00747740((void*)0xb42fa8,(void*)0xb440b8,253)) helper_00747740(g_00747740,(void*)0xb44040); return (void*)0xe18a1c; }
