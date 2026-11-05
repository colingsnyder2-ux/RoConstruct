// from server: 72% by colin
// roc-flags: /O2 /Ob2 /Oy /GF- /GS- /EHsc /MD
extern unsigned char g_006878f0; extern int s_006878f0; extern int (*cb_006878f0)(void*,void*,int); extern "C" void helper_006878f0(int,void*);
void* func_006878f0() { if(g_006878f0==0 && s_006878f0!=0x29 && cb_006878f0 && !cb_006878f0((void*)0xb42fa8,(void*)0xb440b8,253)) helper_006878f0(g_006878f0,(void*)0xb44040); return (void*)0xe16424; }
