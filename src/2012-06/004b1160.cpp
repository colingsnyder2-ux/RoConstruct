// from server: 100% by Xemicl
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
extern "C" int __cdecl func_005c9fe8(int, void*, int);
extern char g_flag_00dac769;
extern void* g_ptr_00b63990;
int __stdcall func_004b1160(int, int, int, int) {
    char al = g_flag_00dac769;
    if (al != 0) {
        func_005c9fe8((int)(unsigned char)al, &g_ptr_00b63990, 0);
    }
    return 0;
}
