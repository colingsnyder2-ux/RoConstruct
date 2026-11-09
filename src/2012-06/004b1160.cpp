// from server: 92% by atomic.potato
extern "C" int __stdcall func_005c9fe8(int, void*, int);

char g_flag_00dac769;
void* g_ptr_00b63990;

int __stdcall func_004b1160(int, int, int, int) {
    char al = g_flag_00dac769;
    if (al != 0) {
        func_005c9fe8((int)(unsigned char)al, &g_ptr_00b63990, 0);
    }
    return 0;
}
