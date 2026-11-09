// from server: 100% by Yeetserama
// roc 2010-06 005fa3f0  unit: G3D::VVector3::?$TypedPropertyDescriptor  size: 54 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 005fa3f0
//
// 005fa3f0  56                   push esi
// 005fa3f1  8b742408             mov esi, dword ptr [esp + 8]
// 005fa3f5  57                   push edi
// 005fa3f6  56                   push esi
// 005fa3f7  e8a4ab0000           call 0x604fa0
// 005fa3fc  8bf8                 mov edi, eax
// 005fa3fe  83c404               add esp, 4
// 005fa401  85ff                 test edi, edi
// 005fa403  741e                 je 0x5fa423
// 005fa405  8bce                 mov ecx, esi
// 005fa407  e8c4faffff           call 0x5f9ed0
// 005fa40c  85c0                 test eax, eax
// 005fa40e  7413                 je 0x5fa423
// 005fa410  57                   push edi
// 005fa411  8bc8                 mov ecx, eax
// 005fa413  e878e9f9ff           call 0x598d90
// 005fa418  8bce                 mov ecx, esi
// 005fa41a  e8b1faffff           call 0x5f9ed0
// 005fa41f  85c0                 test eax, eax
// 005fa421  75ed                 jne 0x5fa410
// 005fa423  5f                   pop edi
// 005fa424  5e                   pop esi
// 005fa425  c3                   ret 
// copied from an identical function in another client (function ?fn_ROCX000007_005fdfa0@ns_ROCX000007@@YAXPAUSource@1@@Z)

namespace ns_ROCX000007 {
// from server: 100% by king_originala
struct Item {
    void consume(void* product);
};

struct Source {
    Item* next();
};

extern void* __cdecl fn_ROCX000007_005a3380(Source* source);

void __cdecl fn_ROCX000007_005fdfa0(Source* source)
{
    void* product = fn_ROCX000007_005a3380(source);
    if (product) {
        Item* item = source->next();
        while (item) {
            item->consume(product);
            item = source->next();
        }
    }
}
}
