// from server: 39% by atomic.potato
struct S_func_006968d0 {
    char pad0[4];
    void* m_field4;
    void f(int, int, int, int, int, int, int, int, int, int);
};

extern "C" void* __cdecl func_00693a60(int, int, int, int, int, int, int, int, int, int);
extern "C" void __cdecl func_00982114(void*);
extern "C" void __cdecl func_00972290(unsigned char, const char*);
extern "C" void __cdecl func_0040cf10(void*, void*);
extern "C" void* __cdecl func_006963c0(int, int);

extern unsigned char g_e580b3;
extern void* g_e5809c;
extern void* g_b229ec;
extern void* g_b933c4;

void S_func_006968d0::f(int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10)
{
    void* p = func_00693a60(a1, a2, a3, a4, a5, a6, a7, a8, a9, a10);
    void* q = *(void**)p;
    *(void**)p = 0;
    void* r = func_006963c0(a1, a2);
    func_0040cf10(this, r);
    func_00982114((void*)a1);
    *(void**)this = &g_b933c4;
    if (g_e580b3 != 0) {
        if (((char (__stdcall*)(void*))g_b229ec)((void*)0xd9b498) == 0) {
            if (g_e5809c != 0) {
                if (((char (__stdcall*)(const char*, const char*, int))g_e5809c)((const char*)0xb44978, (const char*)0xb58618, 0xae) != 0)
                    return;
            }
            func_00972290(g_e580b3, (const char*)0xb58680);
        }
    }
}
