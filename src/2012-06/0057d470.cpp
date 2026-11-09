// from server: 78% by atomic.potato
struct VManualWeld {
    void* vtable;
    void construct();
    void* sub_5748e0();
};

extern "C" void __stdcall sub_972290(unsigned char, const char*);
extern "C" void* __cdecl sub_4019d0(void*);
extern "C" void __cdecl sub_4a11d0(void*);

extern unsigned char byte_E580B3;
extern int dword_E246A8;
extern int (__stdcall *dword_E5809C)(unsigned int, const char*, const char*);

void VManualWeld::construct()
{
    vtable = (void*)0xB76E84;
    if (byte_E580B3 != 0 && dword_E246A8 != 0x29A) {
        if (dword_E5809C != 0) {
            if (dword_E5809C(0xE2, "C:\\TeamCity\\buildAgent\\work\\8348b47e373515f7\\Client\\App\\include\\Util\\Object.h", "wasConstructed()")) {
                goto skip;
            }
        }
        sub_972290(byte_E580B3, "wasConstructed() file: C:\\TeamCity\\buildAgent\\work\\8348b47e373515f7\\Client\\App\\include\\Util\\Object.h line: 226");
    }
skip:
    void* p = sub_5748e0();
    void* q = sub_4019d0(&p);
    sub_4a11d0(q);
}
