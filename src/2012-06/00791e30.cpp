// from server: 72% by colin
// roc-flags: /O2 /Ob2 /Oy /GF- /GS- /EHsc /MD
extern unsigned char g_00791e30; extern int s_00791e30; extern int (*cb_00791e30)(void*,void*,int); extern "C" void helper_00791e30(int,void*);
void* func_00791e30() { if(g_00791e30==0 && s_00791e30!=0x29 && cb_00791e30 && !cb_00791e30((void*)0xb42fa8,(void*)0xb440b8,253)) helper_00791e30(g_00791e30,(void*)0xb44040); return (void*)0xe1a660; }
