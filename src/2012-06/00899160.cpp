// from server: 72% by colin
// roc-flags: /O2 /Ob2 /Oy /GF- /GS- /EHsc /MD
extern unsigned char g_00899160; extern int s_00899160; extern int (*cb_00899160)(void*,void*,int); extern "C" void helper_00899160(int,void*);
void* func_00899160() { if(g_00899160==0 && s_00899160!=0x29 && cb_00899160 && !cb_00899160((void*)0xb42fa8,(void*)0xb440b8,253)) helper_00899160(g_00899160,(void*)0xb44040); return (void*)0xe30254; }
