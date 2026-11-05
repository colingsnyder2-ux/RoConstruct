// from server: 72% by colin
// roc-flags: /O2 /Ob2 /Oy /GF- /GS- /EHsc /MD
extern unsigned char g_00795400; extern int s_00795400; extern int (*cb_00795400)(void*,void*,int); extern "C" void helper_00795400(int,void*);
void* func_00795400() { if(g_00795400==0 && s_00795400!=0x29 && cb_00795400 && !cb_00795400((void*)0xb42fa8,(void*)0xb440b8,253)) helper_00795400(g_00795400,(void*)0xb44040); return (void*)0xe1a938; }
