// from server: 73% by atomic.potato
extern "C" void __stdcall func_00972290(unsigned char, const char*);
extern "C" void* __cdecl func_006c2a90(void*);
extern "C" void* __cdecl func_00746b00(void*);
extern "C" void __cdecl func_008d85f0(void*, void*, float, float);

extern unsigned char g_e580b3;
extern void* g_e5809c;

struct VArcHandles_EventDesc
{
    void invoke(void* a, void* b);
};

void VArcHandles_EventDesc::invoke(void* a, void* b)
{
    if (g_e580b3)
    {
        int count = (*(int*)((char*)a + 8) - *(int*)((char*)a + 4));
        int n = count / 24;
        if (n != 3)
        {
            if (g_e5809c)
            {
                if (((unsigned char (__cdecl*)(const char*, const char*, int))g_e5809c)((const char*)0xb710ec, (const char*)0xb70328, 0x130))
                    goto skip;
            }
            func_00972290(g_e580b3, (const char*)0xb71078);
        }
    }
skip:
    char* p = (char*)b;
    char* edi = p ? p - 0x1c : 0;
    char* base = *(char**)((char*)a + 4);
    float f1 = *(float*)func_006c2a90(base + 0x8c);
    float f2 = *(float*)func_006c2a90(base + 0x48);
    void* r = func_00746b00(base + 4);
    int v = *(int*)r;
    func_008d85f0((char*)this + 0x2c + (int)edi, (void*)v, f2, f1);
}
