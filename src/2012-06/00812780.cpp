// from server: 72% by colin
// roc-flags: /O2 /Ob2 /Oy /GF- /GS- /EHsc /MD
extern unsigned char g_00812780; extern int s_00812780; extern int (*cb_00812780)(void*,void*,int); extern "C" void helper_00812780(int,void*);
void* func_00812780() { if(g_00812780==0 && s_00812780!=0x29 && cb_00812780 && !cb_00812780((void*)0xb42fa8,(void*)0xb440b8,253)) helper_00812780(g_00812780,(void*)0xb44040); return (void*)0xe24e94; }
