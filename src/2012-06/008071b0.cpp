// from server: 51% by atomic.potato
extern "C" void __stdcall G1_func_00972290(unsigned char, const char*);
extern "C" void __stdcall G1_func_0041ce00(void*, void*);
extern "C" void __stdcall G1_func_00805540(void*);

extern unsigned char g_e580b3;
extern void* g_e5809c;

struct EventDesc {
    void func_008071b0(void* a, void* b);
};

void EventDesc::func_008071b0(void* a, void* b)
{
    if (g_e580b3 != 0) {
        int* p = (int*)a;
        int diff = p[2] - p[1];
        int cnt = diff / 0x44;
        if (cnt == 2)
            goto skip;
    }
    if (g_e5809c != 0) {
        unsigned char r = ((unsigned char (__stdcall*)(const char*, const char*, int))g_e5809c)((const char*)0xb70a94, (const char*)0xb70328, 0x111);
        if (r != 0)
            goto skip;
    }
    G1_func_00972290(g_e580b3, (const char*)0xb70a20);
skip:
    char* edi = 0;
    if (b != 0)
        edi = (char*)b - 0x1c;
    int* p = (int*)a;
    char* base = (char*)p[1];
    char tmp1[0x1c];
    G1_func_0041ce00(base + 0x44, tmp1);
    char tmp2[0x1c];
    G1_func_0041ce00(base, tmp2);
    char* ecx = (char*)this + 0x2c;
    G1_func_00805540(ecx + (int)edi);
}
