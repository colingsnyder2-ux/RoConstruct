// from server: 72% by colin
// roc-flags: /O2 /Ob2 /Oy /GF- /GS- /EHsc /MD
extern unsigned char g_00790a40; extern int s_00790a40; extern int (*cb_00790a40)(void*,void*,int); extern "C" void helper_00790a40(int,void*);
void* func_00790a40() { if(g_00790a40==0 && s_00790a40!=0x29 && cb_00790a40 && !cb_00790a40((void*)0xb42fa8,(void*)0xb440b8,253)) helper_00790a40(g_00790a40,(void*)0xb44040); return (void*)0xe1a668; }
