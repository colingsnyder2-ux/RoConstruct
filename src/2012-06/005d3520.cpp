// from server: 72% by colin
// roc-flags: /O2 /Ob2 /Oy /GF- /GS- /EHsc /MD
extern unsigned char g_005d3520; extern int s_005d3520; extern int (*cb_005d3520)(void*,void*,int); extern "C" void helper_005d3520(int,void*);
void* func_005d3520() { if(g_005d3520==0 && s_005d3520!=0x29 && cb_005d3520 && !cb_005d3520((void*)0xb42fa8,(void*)0xb440b8,253)) helper_005d3520(g_005d3520,(void*)0xb44040); return (void*)0xe27d9c; }
