// from server: 100% by EspClaude
// roc 2009-06 00673010  unit: RBX::VPants::?$FactoryProduct  size: 99 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00673010
//
// 00673010  56                   push esi
// 00673011  8b742408             mov esi, dword ptr [esp + 8]
// 00673015  8bce                 mov ecx, esi
// 00673017  e86439ffff           call 0x666980
// 0067301c  85c0                 test eax, eax
// 0067301e  7407                 je 0x673027
// 00673020  8bc8                 mov ecx, eax
// 00673022  e839d2feff           call 0x660260
// 00673027  8bce                 mov ecx, esi
// 00673029  e83238ffff           call 0x666860
// 0067302e  85c0                 test eax, eax
// 00673030  7407                 je 0x673039
// 00673032  8bc8                 mov ecx, eax
// 00673034  e827d2feff           call 0x660260
// 00673039  8bce                 mov ecx, esi
// 0067303b  e8b038ffff           call 0x6668f0
// 00673040  85c0                 test eax, eax
// 00673042  7407                 je 0x67304b
// 00673044  8bc8                 mov ecx, eax
// 00673046  e815d2feff           call 0x660260
// 0067304b  8bce                 mov ecx, esi
// 0067304d  e87e37ffff           call 0x6667d0
// 00673052  85c0                 test eax, eax
// 00673054  7407                 je 0x67305d
// 00673056  8bc8                 mov ecx, eax
// 00673058  e803d2feff           call 0x660260
// 0067305d  8bce                 mov ecx, esi
// 0067305f  e8dc36ffff           call 0x666740
// 00673064  5e                   pop esi
// 00673065  85c0                 test eax, eax
// 00673067  7407                 je 0x673070
// 00673069  8bc8                 mov ecx, eax
// 0067306b  e8f0d1feff           call 0x660260
// 00673070  c20400               ret 4
// copied from an identical function in another client (function ?f@ns_ROCX00000f@@YGXPAUS@1@@Z)

namespace ns_ROCX00000f {
struct Object {
    void release();
};

struct S {
    Object* first();
    Object* second();
    Object* third();
    Object* fourth();
    Object* fifth();
};

void __stdcall f(S* s)
{
    Object* p = s->first();
    if (p)
        p->release();

    p = s->second();
    if (p)
        p->release();

    p = s->third();
    if (p)
        p->release();

    p = s->fourth();
    if (p)
        p->release();

    p = s->fifth();
    if (p)
        p->release();
}
}
