// from server: 44% by atomic.potato
struct MainLogManager {
    char pad0[4];
    char pad4[0x28];
    char pad2c[4];
    char pad30[0x10];
    void construct(char*);
};

extern "C" {
    unsigned long __stdcall GetCurrentThreadId();
    void* __stdcall sub_9ea394();
    void __stdcall sub_9ea410(void*, const char*);
    void __stdcall sub_9ea404(void*);
    void __stdcall sub_9ea400(void*);
    void __stdcall sub_9ea420(void*, const char*);
    void __stdcall sub_9ea464(void*, void*);
    void __stdcall sub_9ea478(void*, unsigned int);
    void __stdcall sub_9ea874(void*, void*);
    void __cdecl sub_60a300(void*);
    void __cdecl sub_798500(void*);
    void __cdecl sub_798a90(void*);
    void __cdecl sub_798aa0(void*);
    void __cdecl sub_550150(void*);
    void __cdecl sub_550160(void*);
    void* __cdecl sub_7a79a0(unsigned int);
    void __cdecl sub_54f400(void*, void*, int);
    void __cdecl sub_423fd0(void*, void*);
    void __cdecl sub_426760(void*, const char*, int);
}

extern void* g_9ea460;
extern void* g_c00808;

void MainLogManager::construct(char* a1) {
    char* edi = (char*)this + 4;
    *(void**)edi = (void*)0xa044a8;
    *(void**)(edi + 4) = 0;
    *(void**)(edi + 8) = sub_9ea394();
    sub_9ea410(edi + 0xc, a1);
    *(void**)this = (void*)0xa04670;
    *(void**)edi = (void*)0xa04664;
    *(void**)((char*)this + 0x2c) = 0;
    char* ebp = (char*)this + 0x30;
    sub_9ea404(ebp);
    sub_60a300(ebp);
    sub_426760(this, (const char*)0xa04684, 0x20);
    sub_426760(this, (const char*)0xa031c8, 0x20);
    char buf[8];
    sub_423fd0(edi, buf);
    void* edx = g_9ea460;
    void* eax = *(void**)edx;
    sub_9ea464(buf, eax);
    unsigned int sz = *(unsigned int*)((char*)buf + 4);
    sub_9ea478(buf, sz - 4);
    sub_9ea420(buf, (const char*)0xa04678);
    void* mem = sub_7a79a0(0x28);
    if (mem) {
        sub_54f400(mem, buf, 0);
    }
    g_c00808 = this;
    sub_798500(this);
    sub_798a90((void*)0x4244a0);
    sub_798aa0((void*)0x424520);
    sub_550150((void*)0x424eb0);
    sub_550160((void*)0x424ed0);
    sub_9ea874((void*)0x4242f0, 0);
    sub_9ea400(buf);
}
