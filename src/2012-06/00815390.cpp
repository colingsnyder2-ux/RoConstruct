// from server: 72% by colin
// roc-flags: /O2 /Ob2 /Oy /GF- /GS- /EHsc /MD
extern unsigned char g_00815390; extern int s_00815390; extern int (*cb_00815390)(void*,void*,int); extern "C" void helper_00815390(int,void*);
void* func_00815390() { if(g_00815390==0 && s_00815390!=0x29 && cb_00815390 && !cb_00815390((void*)0xb42fa8,(void*)0xb440b8,253)) helper_00815390(g_00815390,(void*)0xb44040); return (void*)0xe24e8c; }
