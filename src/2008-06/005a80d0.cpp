// from server: 100% by king_originala
struct GUID {
    unsigned long Data1;
    unsigned short Data2;
    unsigned short Data3;
    unsigned char Data4[8];
};

struct String {};

extern "C" {
    extern long (__stdcall *CoCreateGuid)(GUID*);
    extern int (__stdcall *StringFromGUID2)(const GUID&, wchar_t*, int);
    extern int (__stdcall *WideCharToMultiByte)(
        unsigned int, unsigned long, const wchar_t*, int,
        char*, int, const char*, int*);
    extern String& (__thiscall *assignString)(String*, const char*);
    void* __cdecl memset(void*, int, unsigned int);
}

void __cdecl makeGuidString(String& result)
{
    GUID guid;
    char text[64];
    CoCreateGuid(&guid);
    wchar_t wide[64] = {0};
    StringFromGUID2(guid, wide, 64);
    WideCharToMultiByte(0, 0, wide, 64, text, 64, 0, 0);
    assignString(&result, text);
}
