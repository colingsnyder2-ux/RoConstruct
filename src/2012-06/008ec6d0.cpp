// from server: 72% by colin
// roc-flags: /O2 /Ob2 /Oy /GF- /GS- /EHsc /MD
extern unsigned char g_008ec6d0; extern int s_008ec6d0; extern int (*cb_008ec6d0)(void*,void*,int); extern "C" void helper_008ec6d0(int,void*);
void* func_008ec6d0() { if(g_008ec6d0==0 && s_008ec6d0!=0x29 && cb_008ec6d0 && !cb_008ec6d0((void*)0xb42fa8,(void*)0xb440b8,253)) helper_008ec6d0(g_008ec6d0,(void*)0xb44040); return (void*)0xe48a38; }
