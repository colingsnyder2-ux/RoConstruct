// from server: 80% by atomic.potato
extern "C" int __stdcall sub_972290(unsigned char, const char*);
extern "C" void* __stdcall sub_4019d0(void*);
extern "C" void __stdcall sub_4a11d0(void*, void*);
extern "C" void __stdcall sub_574a30(void*);

extern unsigned char byte_E580B3;
extern int dword_E246B4;
extern int dword_E5809C;

struct S {
    void ctor();
};

void S::ctor()
{
    *(int*)this = 0xB76ED8;
    if (byte_E580B3 != 0 && dword_E246B4 != 0x29A) {
        int f = dword_E5809C;
        if (f != 0) {
            char r = ((char (__stdcall*)(const char*, const char*, int))f)((const char*)0xB42F90, (const char*)0xB42FA8, 0xE2);
            if (r != 0)
                goto skip;
        }
        sub_972290(byte_E580B3, (const char*)0xB43368);
    }
skip:
    sub_574a30(this);
    void* p = sub_4019d0(&p);
    sub_4a11d0(p, 0);
}
