// from server: 72% by colin
// roc-flags: /O2 /Ob2 /Oy /GF- /GS- /EHsc /MD
extern unsigned char g_0070c410; extern int s_0070c410; extern int (*cb_0070c410)(void*,void*,int); extern "C" void helper_0070c410(int,void*);
void* func_0070c410() { if(g_0070c410==0 && s_0070c410!=0x29 && cb_0070c410 && !cb_0070c410((void*)0xb42fa8,(void*)0xb440b8,253)) helper_0070c410(g_0070c410,(void*)0xb44040); return (void*)0xe18118; }
