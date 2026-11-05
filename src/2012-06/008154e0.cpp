// from server: 72% by colin
// roc-flags: /O2 /Ob2 /Oy /GF- /GS- /EHsc /MD
extern unsigned char g_008154e0; extern int s_008154e0; extern int (*cb_008154e0)(void*,void*,int); extern "C" void helper_008154e0(int,void*);
void* func_008154e0() { if(g_008154e0==0 && s_008154e0!=0x29 && cb_008154e0 && !cb_008154e0((void*)0xb42fa8,(void*)0xb440b8,253)) helper_008154e0(g_008154e0,(void*)0xb44040); return (void*)0xe24e98; }
