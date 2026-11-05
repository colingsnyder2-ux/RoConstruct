// roc 2009-12 007297d0  unit: boost::iostreams::Uoutput::V?$chain::?$filtering_stream_base  size: 59 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 007297d0
//
// 007297d0  56                   push esi
// 007297d1  8bf1                 mov esi, ecx
// 007297d3  e848a4ffff           call 0x723c20
// 007297d8  8b0da4b49800         mov ecx, dword ptr [0x98b4a4]
// 007297de  8d4614               lea eax, [esi + 0x14]
// 007297e1  8908                 mov dword ptr [eax], ecx
// 007297e3  8b15a0b49800         mov edx, dword ptr [0x98b4a0]
// 007297e9  50                   push eax
// 007297ea  8910                 mov dword ptr [eax], edx
// 007297ec  ff1594b49800         call dword ptr [0x98b494]
// 007297f2  83c404               add esp, 4
// 007297f5  f644240801           test byte ptr [esp + 8], 1
// 007297fa  7409                 je 0x729805
// 007297fc  56                   push esi
// 007297fd  e858a00c00           call 0x7f385a
// 00729802  83c404               add esp, 4
// 00729805  8bc6                 mov eax, esi
// 00729807  5e                   pop esi
// 00729808  c20400               ret 4
// copied from an identical function in another client (function ?f@S@ns_ROCX000005@@QAEPAU12@H@Z)

namespace ns_ROCX000005 {
extern "C" void __cdecl sub_54D430();
extern "C" void __cdecl sub_62FC62(void*);

extern void* g_77E4DC;
extern void* g_77E4E0;
extern void (__cdecl *g_77E4E4)(void*);

struct S {
    S* f(int);
};

S* S::f(int a) {
    sub_54D430();
    void** p = (void**)((char*)this + 0x14);
    *p = g_77E4DC;
    *p = g_77E4E0;
    g_77E4E4(p);
    if (a & 1) {
        sub_62FC62(this);
    }
    return this;
}
}
