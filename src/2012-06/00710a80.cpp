// from server: 72% by colin
// roc-flags: /O2 /Ob2 /Oy /GF- /GS- /EHsc /MD
extern unsigned char g_00710a80; extern int s_00710a80; extern int (*cb_00710a80)(void*,void*,int); extern "C" void helper_00710a80(int,void*);
void* func_00710a80() { if(g_00710a80==0 && s_00710a80!=0x29 && cb_00710a80 && !cb_00710a80((void*)0xb42fa8,(void*)0xb440b8,253)) helper_00710a80(g_00710a80,(void*)0xb44040); return (void*)0xe18114; }
