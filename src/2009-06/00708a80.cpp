// from server: 100% by why2
extern "C" unsigned long (__stdcall *TlsAlloc)();
void __cdecl sub_6749e0();

unsigned long g_tlsIndex;

void __cdecl sub_708a80()
{
    sub_6749e0();
    g_tlsIndex = TlsAlloc();
}
