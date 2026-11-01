// from server: 100% by Yeetserama
// roc 2011-06 006f01f0  unit: RBX::CharacterMesh  size: 99 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 006f01f0
//
// 006f01f0  56                   push esi
// 006f01f1  8b742408             mov esi, dword ptr [esp + 8]
// 006f01f5  8bce                 mov ecx, esi
// 006f01f7  e854e1f8ff           call 0x67e350
// 006f01fc  85c0                 test eax, eax
// 006f01fe  7407                 je 0x6f0207
// 006f0200  8bc8                 mov ecx, eax
// 006f0202  e8191ff8ff           call 0x672120
// 006f0207  8bce                 mov ecx, esi
// 006f0209  e842e2f8ff           call 0x67e450
// 006f020e  85c0                 test eax, eax
// 006f0210  7407                 je 0x6f0219
// 006f0212  8bc8                 mov ecx, eax
// 006f0214  e8071ff8ff           call 0x672120
// 006f0219  8bce                 mov ecx, esi
// 006f021b  e8b0e1f8ff           call 0x67e3d0
// 006f0220  85c0                 test eax, eax
// 006f0222  7407                 je 0x6f022b
// 006f0224  8bc8                 mov ecx, eax
// 006f0226  e8f51ef8ff           call 0x672120
// 006f022b  8bce                 mov ecx, esi
// 006f022d  e89ee0f8ff           call 0x67e2d0
// 006f0232  85c0                 test eax, eax
// 006f0234  7407                 je 0x6f023d
// 006f0236  8bc8                 mov ecx, eax
// 006f0238  e8e31ef8ff           call 0x672120
// 006f023d  8bce                 mov ecx, esi
// 006f023f  e80ce0f8ff           call 0x67e250
// 006f0244  5e                   pop esi
// 006f0245  85c0                 test eax, eax
// 006f0247  7407                 je 0x6f0250
// 006f0249  8bc8                 mov ecx, eax
// 006f024b  e8d01ef8ff           call 0x672120
// 006f0250  c20400               ret 4
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
