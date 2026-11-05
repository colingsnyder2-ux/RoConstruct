// from server: 72% by colin
// roc-flags: /O2 /Ob2 /Oy /GF- /GS- /EHsc /MD
extern unsigned char g_00815460; extern int s_00815460; extern int (*cb_00815460)(void*,void*,int); extern "C" void helper_00815460(int,void*);
void* func_00815460() { if(g_00815460==0 && s_00815460!=0x29 && cb_00815460 && !cb_00815460((void*)0xb42fa8,(void*)0xb440b8,253)) helper_00815460(g_00815460,(void*)0xb44040); return (void*)0xe24e78; }
