// from server: 100% by EspClaude
// roc 2009-06 0063d2a0  unit: RBX::VHat::?$FactoryProduct  size: 64 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 0063d2a0
//
// 0063d2a0  56                   push esi
// 0063d2a1  8b742408             mov esi, dword ptr [esp + 8]
// 0063d2a5  57                   push edi
// 0063d2a6  56                   push esi
// 0063d2a7  e8840fffff           call 0x62e230
// 0063d2ac  8bf8                 mov edi, eax
// 0063d2ae  83c404               add esp, 4
// 0063d2b1  85ff                 test edi, edi
// 0063d2b3  7428                 je 0x63d2dd
// 0063d2b5  8bce                 mov ecx, esi
// 0063d2b7  e824feffff           call 0x63d0e0
// 0063d2bc  85c0                 test eax, eax
// 0063d2be  741d                 je 0x63d2dd
// 0063d2c0  53                   push ebx
// 0063d2c1  8b5c2414             mov ebx, dword ptr [esp + 0x14]
// 0063d2c5  3bc3                 cmp eax, ebx
// 0063d2c7  7408                 je 0x63d2d1
// 0063d2c9  57                   push edi
// 0063d2ca  8bc8                 mov ecx, eax
// 0063d2cc  e87f4bf9ff           call 0x5d1e50
// 0063d2d1  8bce                 mov ecx, esi
// 0063d2d3  e808feffff           call 0x63d0e0
// 0063d2d8  85c0                 test eax, eax
// 0063d2da  75e9                 jne 0x63d2c5
// 0063d2dc  5b                   pop ebx
// 0063d2dd  5f                   pop edi
// 0063d2de  5e                   pop esi
// 0063d2df  c3                   ret 
// copied from an identical function in another client (function ?fn_ROCX00000c_005b15e0@ns_ROCX00000c@@YAXPAUS@1@0@Z)

namespace ns_ROCX00000c {
struct S {
    S* next();
    void attach(S*);
};

extern S* __cdecl lookup(S*);

void __cdecl fn_ROCX00000c_005b15e0(S* source, S* excluded)
{
    S* parent = lookup(source);
    if (parent) {
        S* item = source->next();
        if (item) {
            do {
                if (item != excluded)
                    item->attach(parent);
                item = source->next();
            } while (item);
        }
    }
}
}
