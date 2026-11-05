// from server: 72% by colin
// roc-flags: /O2 /Ob2 /Oy /GF- /GS- /EHsc /MD
extern unsigned char g_0077e540; extern int s_0077e540; extern int (*cb_0077e540)(void*,void*,int); extern "C" void helper_0077e540(int,void*);
void* func_0077e540() { if(g_0077e540==0 && s_0077e540!=0x29 && cb_0077e540 && !cb_0077e540((void*)0xb42fa8,(void*)0xb440b8,253)) helper_0077e540(g_0077e540,(void*)0xb44040); return (void*)0xe48d04; }
