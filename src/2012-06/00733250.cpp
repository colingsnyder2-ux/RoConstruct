// from server: 72% by colin
// roc-flags: /O2 /Ob2 /Oy /GF- /GS- /EHsc /MD
extern unsigned char g_00733250; extern int s_00733250; extern int (*cb_00733250)(void*,void*,int); extern "C" void helper_00733250(int,void*);
void* func_00733250() { if(g_00733250==0 && s_00733250!=0x29 && cb_00733250 && !cb_00733250((void*)0xb42fa8,(void*)0xb440b8,253)) helper_00733250(g_00733250,(void*)0xb44040); return (void*)0xe1895c; }
