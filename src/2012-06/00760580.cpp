// from server: 72% by colin
// roc-flags: /O2 /Ob2 /Oy /GF- /GS- /EHsc /MD
extern unsigned char g_00760580; extern int s_00760580; extern int (*cb_00760580)(void*,void*,int); extern "C" void helper_00760580(int,void*);
void* func_00760580() { if(g_00760580==0 && s_00760580!=0x29 && cb_00760580 && !cb_00760580((void*)0xb42fa8,(void*)0xb440b8,253)) helper_00760580(g_00760580,(void*)0xb44040); return (void*)0xe1a43c; }
