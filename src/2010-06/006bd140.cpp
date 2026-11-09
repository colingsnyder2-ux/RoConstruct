// from server: 100% by Yeetserama
// roc 2010-06 006bd140  unit: RBX::CharacterMesh  size: 99 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 006bd140
//
// 006bd140  56                   push esi
// 006bd141  8b742408             mov esi, dword ptr [esp + 8]
// 006bd145  8bce                 mov ecx, esi
// 006bd147  e844f9faff           call 0x66ca90
// 006bd14c  85c0                 test eax, eax
// 006bd14e  7407                 je 0x6bd157
// 006bd150  8bc8                 mov ecx, eax
// 006bd152  e809f2f7ff           call 0x63c360
// 006bd157  8bce                 mov ecx, esi
// 006bd159  e8f2f7faff           call 0x66c950
// 006bd15e  85c0                 test eax, eax
// 006bd160  7407                 je 0x6bd169
// 006bd162  8bc8                 mov ecx, eax
// 006bd164  e8f7f1f7ff           call 0x63c360
// 006bd169  8bce                 mov ecx, esi
// 006bd16b  e8e058fbff           call 0x672a50
// 006bd170  85c0                 test eax, eax
// 006bd172  7407                 je 0x6bd17b
// 006bd174  8bc8                 mov ecx, eax
// 006bd176  e8e5f1f7ff           call 0x63c360
// 006bd17b  8bce                 mov ecx, esi
// 006bd17d  e84ef7faff           call 0x66c8d0
// 006bd182  85c0                 test eax, eax
// 006bd184  7407                 je 0x6bd18d
// 006bd186  8bc8                 mov ecx, eax
// 006bd188  e8d3f1f7ff           call 0x63c360
// 006bd18d  8bce                 mov ecx, esi
// 006bd18f  e8bcf6faff           call 0x66c850
// 006bd194  5e                   pop esi
// 006bd195  85c0                 test eax, eax
// 006bd197  7407                 je 0x6bd1a0
// 006bd199  8bc8                 mov ecx, eax
// 006bd19b  e8c0f1f7ff           call 0x63c360
// 006bd1a0  c20400               ret 4
// copied from an identical function in another client (function ?f@ns_ROCX000013@@YGXPAUS@1@@Z)

namespace ns_ROCX000013 {
// from server: 100% by king_originala
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
