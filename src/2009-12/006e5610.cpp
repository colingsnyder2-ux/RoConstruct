// from server: 86% by atomic.potato
struct S_6e4a50 { void* f(); };
struct S_53e5c0 { void g(); };
struct S_636d80 { void h(void* arg); };

extern "C" void* __cdecl sub_6e32e0();

void __stdcall sub_6e5610(void* arg)
{
    void* esi = sub_6e32e0();
    if (esi)
    {
        void* eax = ((S_6e4a50*)esi)->f();
        if (eax)
        {
            ((S_53e5c0*)eax)->g();
        }
        ((S_636d80*)esi)->h(arg);
    }
}
