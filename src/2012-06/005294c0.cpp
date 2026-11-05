// from server: 72% by colin
// roc-flags: /O2 /Ob2 /Oy /GF- /GS- /EHsc /MD
extern unsigned char g_005294c0; extern int s_005294c0; extern int (*cb_005294c0)(void*,void*,int); extern "C" void helper_005294c0(int,void*);
void* func_005294c0() { if(g_005294c0==0 && s_005294c0!=0x29 && cb_005294c0 && !cb_005294c0((void*)0xb42fa8,(void*)0xb440b8,253)) helper_005294c0(g_005294c0,(void*)0xb44040); return (void*)0xe214ec; }
