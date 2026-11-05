// from server: 46% by Intel
extern "C" int __stdcall FormatMessageA(unsigned int, const void*, unsigned int, unsigned int, char*, unsigned int, void*);

struct VStandardOut {
    void __cdecl func(int a1, int a2, int a3);
};

void VStandardOut::func(int a1, int a2, int a3) {
    char buffer1[256];
    char buffer2[256];
    int result;

    result = FormatMessageA(0x1000, 0, a3, 0, buffer1, 256, 0);
    if (!result) {
        int (__cdecl *vsprintf_ptr)(char*, const char*, ...);
        vsprintf_ptr = (int (__cdecl *)(char*, const char*, ...))0x972d70;
        vsprintf_ptr(buffer2, (const char*)0xb96330, a2, a1, a3);
        void (__cdecl *log_ptr)(const char*, const char*);
        log_ptr = (void (__cdecl *)(const char*, const char*))0x983144;
        log_ptr((const char*)0xcd806c, buffer2);
    }

    int (__cdecl *vsprintf_ptr2)(char*, const char*, ...);
    vsprintf_ptr2 = (int (__cdecl *)(char*, const char*, ...))0x972d70;
    vsprintf_ptr2(buffer2, (const char*)0xb96324, a3, a2, a1);
    void (__cdecl *log_ptr2)(const char*, const char*);
    log_ptr2 = (void (__cdecl *)(const char*, const char*))0x983144;
    log_ptr2((const char*)0xcd806c, buffer2);
}
