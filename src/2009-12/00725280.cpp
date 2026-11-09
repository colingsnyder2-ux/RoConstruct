// roc 2009-12 00725280  unit: boost::iostreams::Uoutput::?$filtering_stream  size: 59 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00725280
//
// 00725280  56                   push esi
// 00725281  8bf1                 mov esi, ecx
// 00725283  e8f8f3ffff           call 0x724680
// 00725288  8b0da4b49800         mov ecx, dword ptr [0x98b4a4]
// 0072528e  8d4614               lea eax, [esi + 0x14]
// 00725291  8908                 mov dword ptr [eax], ecx
// 00725293  8b15a0b49800         mov edx, dword ptr [0x98b4a0]
// 00725299  50                   push eax
// 0072529a  8910                 mov dword ptr [eax], edx
// 0072529c  ff1594b49800         call dword ptr [0x98b494]
// 007252a2  83c404               add esp, 4
// 007252a5  f644240801           test byte ptr [esp + 8], 1
// 007252aa  7409                 je 0x7252b5
// 007252ac  56                   push esi
// 007252ad  e8a8e50c00           call 0x7f385a
// 007252b2  83c404               add esp, 4
// 007252b5  8bc6                 mov eax, esi
// 007252b7  5e                   pop esi
// 007252b8  c20400               ret 4
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
