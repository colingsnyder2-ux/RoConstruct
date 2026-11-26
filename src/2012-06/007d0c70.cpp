// from server: 100% by Xemicl
// roc 2012-06 007d0c70  unit: RBX::CharacterMesh  size: 99 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 007d0c70
//
// 007d0c70  56                   push esi
// 007d0c71  8b742408             mov esi, dword ptr [esp + 8]
// 007d0c75  8bce                 mov ecx, esi
// 007d0c77  e844a6fcff           call 0x79b2c0
// 007d0c7c  85c0                 test eax, eax
// 007d0c7e  7407                 je 0x7d0c87
// 007d0c80  8bc8                 mov ecx, eax
// 007d0c82  e87978f8ff           call 0x758500
// 007d0c87  8bce                 mov ecx, esi
// 007d0c89  e842a6fcff           call 0x79b2d0
// 007d0c8e  85c0                 test eax, eax
// 007d0c90  7407                 je 0x7d0c99
// 007d0c92  8bc8                 mov ecx, eax
// 007d0c94  e86778f8ff           call 0x758500
// 007d0c99  8bce                 mov ecx, esi
// 007d0c9b  e810a6fcff           call 0x79b2b0
// 007d0ca0  85c0                 test eax, eax
// 007d0ca2  7407                 je 0x7d0cab
// 007d0ca4  8bc8                 mov ecx, eax
// 007d0ca6  e85578f8ff           call 0x758500
// 007d0cab  8bce                 mov ecx, esi
// 007d0cad  e8de7bfcff           call 0x798890
// 007d0cb2  85c0                 test eax, eax
// 007d0cb4  7407                 je 0x7d0cbd
// 007d0cb6  8bc8                 mov ecx, eax
// 007d0cb8  e84378f8ff           call 0x758500
// 007d0cbd  8bce                 mov ecx, esi
// 007d0cbf  e8bc7bfcff           call 0x798880
// 007d0cc4  5e                   pop esi
// 007d0cc5  85c0                 test eax, eax
// 007d0cc7  7407                 je 0x7d0cd0
// 007d0cc9  8bc8                 mov ecx, eax
// 007d0ccb  e83078f8ff           call 0x758500
// 007d0cd0  c20400               ret 4
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