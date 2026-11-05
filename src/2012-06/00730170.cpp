// from server: 72% by colin
// roc-flags: /O2 /Ob2 /Oy /GF- /GS- /EHsc /MD
extern unsigned char g_00730170; extern int s_00730170; extern int (*cb_00730170)(void*,void*,int); extern "C" void helper_00730170(int,void*);
void* func_00730170() { if(g_00730170==0 && s_00730170!=0x29 && cb_00730170 && !cb_00730170((void*)0xb42fa8,(void*)0xb440b8,253)) helper_00730170(g_00730170,(void*)0xb44040); return (void*)0xe18964; }
