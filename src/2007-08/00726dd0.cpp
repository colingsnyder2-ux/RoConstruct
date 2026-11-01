// from server: 100% by colin
extern "C" __declspec(dllimport) unsigned long __stdcall TlsFree(unsigned long);

extern "C" void __cdecl sub_725520(const char*, const char*);
extern "C" void __fastcall sub_725750(void*);
extern "C" void __fastcall sub_725770(void*);

extern void* g_8c98f8;
extern unsigned long g_8bab84;

struct boost_thread_resource_error {
    void __fastcall destroy();
};

void __fastcall boost_thread_resource_error::destroy()
{
    sub_725520((const char*)0x8c98fc, (const char*)0x726c80);
    void* p = g_8c98f8;
    sub_725750(p);
    unsigned long tls = g_8bab84;
    if (tls != 0xffffffff) {
        TlsFree(tls);
        g_8bab84 = 0xffffffff;
    }
    sub_725770(p);
}
