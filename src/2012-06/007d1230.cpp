// from server: 72% by colin
// roc-flags: /O2 /Ob2 /Oy /GF- /GS- /EHsc /MD
extern unsigned char g_007d1230; extern int s_007d1230; extern int (*cb_007d1230)(void*,void*,int); extern "C" void helper_007d1230(int,void*);
void* func_007d1230() { if(g_007d1230==0 && s_007d1230!=0x29 && cb_007d1230 && !cb_007d1230((void*)0xb42fa8,(void*)0xb440b8,253)) helper_007d1230(g_007d1230,(void*)0xb44040); return (void*)0xe214f8; }
