// from server: 72% by colin
// roc-flags: /O2 /Ob2 /Oy /GF- /GS- /EHsc /MD
extern unsigned char g_00529080; extern int s_00529080; extern int (*cb_00529080)(void*,void*,int); extern "C" void helper_00529080(int,void*);
void* func_00529080() { if(g_00529080==0 && s_00529080!=0x29 && cb_00529080 && !cb_00529080((void*)0xb42fa8,(void*)0xb440b8,253)) helper_00529080(g_00529080,(void*)0xb44040); return (void*)0xe214e8; }
