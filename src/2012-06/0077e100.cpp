// from server: 72% by colin
// roc-flags: /O2 /Ob2 /Oy /GF- /GS- /EHsc /MD
extern unsigned char g_0077e100; extern int s_0077e100; extern int (*cb_0077e100)(void*,void*,int); extern "C" void helper_0077e100(int,void*);
void* func_0077e100() { if(g_0077e100==0 && s_0077e100!=0x29 && cb_0077e100 && !cb_0077e100((void*)0xb42fa8,(void*)0xb440b8,253)) helper_0077e100(g_0077e100,(void*)0xb44040); return (void*)0xe48af8; }
