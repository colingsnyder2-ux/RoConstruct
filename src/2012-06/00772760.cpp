// from server: 72% by colin
// roc-flags: /O2 /Ob2 /Oy /GF- /GS- /EHsc /MD
extern unsigned char g_00772760; extern int s_00772760; extern int (*cb_00772760)(void*,void*,int); extern "C" void helper_00772760(int,void*);
void* func_00772760() { if(g_00772760==0 && s_00772760!=0x29 && cb_00772760 && !cb_00772760((void*)0xb42fa8,(void*)0xb440b8,253)) helper_00772760(g_00772760,(void*)0xb44040); return (void*)0xe48a3c; }
