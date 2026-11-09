// from server: 45% by atomic.potato
extern "C" void __stdcall sub_401630(int, int);
extern "C" void __cdecl sub_423b20();
extern "C" void __cdecl sub_40cde0();

extern void* g_98de94;
extern void* g_98ddb4;
extern void* g_98d25c;
extern void* g_98c978;
extern void* g_98d260;
extern void* g_98de80;
extern void* g_98b26c;
extern void* g_98dec0;
extern void* g_98b268;

struct ThreadLogManager {
    bool f();
};

bool ThreadLogManager::f()
{
    char buf1[0x14];
    char buf2[0x14];
    char buf3[0x120];
    int hFind;

    sub_401630(0xb7a280, 0x423bf0);
    sub_423b20();
    ((void (__stdcall*)(char*))g_98de94)(buf1);
    ((void (__stdcall*)(char*))g_98ddb4)(buf2);
    ((void (__stdcall*)(char*, int))g_98d25c)(buf2, 0);
    ((void (__stdcall*)(char*))g_98c978)(buf2);
    ((void (__stdcall*)(char*, int))g_98d260)(buf2, -1);
    ((void (__cdecl*)(char*, char*, int))sub_40cde0)(buf3, buf2, 0x9a3848);
    ((void (__stdcall*)(char*, char*))g_98de80)(buf3, buf1);
    hFind = ((int (__stdcall*)(char*, char*))g_98b26c)(buf1, buf3);
    ((void (__stdcall*)(char*))g_98dec0)(buf1);

    if (hFind == -1) {
        ((void (__stdcall*)(char*))g_98dec0)(buf2);
        return false;
    }

    while (true) {
        if (!(buf1[0] & 0x10))
            break;
        if (!((int (__stdcall*)(int, char*))g_98b268)(hFind, buf1))
            break;
    }

    ((void (__stdcall*)(char*))g_98dec0)(buf2);
    return true;
}
