// from server: 100% by EspClaude
// roc 2009-06 004e6810  unit: RBX::Network::Replicator::ChangePropertyItem  size: 43 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 004e6810
//
// 004e6810  8b4c2408             mov ecx, dword ptr [esp + 8]
// 004e6814  83ec08               sub esp, 8
// 004e6817  8d0424               lea eax, [esp]
// 004e681a  50                   push eax
// 004e681b  51                   push ecx
// 004e681c  e80f6cffff           call 0x4dd430
// 004e6821  8b4c2414             mov ecx, dword ptr [esp + 0x14]
// 004e6825  83c408               add esp, 8
// 004e6828  83790400             cmp dword ptr [ecx + 4], 0
// 004e682c  7409                 je 0x4e6837
// 004e682e  8d1424               lea edx, [esp]
// 004e6831  52                   push edx
// 004e6832  e879f3ffff           call 0x4e5bb0
// 004e6837  83c408               add esp, 8
// 004e683a  c3                   ret 
// copied from an identical function in another client (function ?f@ns_ROCX0000aa@@YAXPAUS@1@PAX@Z)

namespace ns_ROCX0000aa {
struct Value {
    void* first;
    void* second;
};

struct S {
    int first;
    int enabled;
    void apply(Value*);
};

extern void __cdecl convert(void*, Value*);

void __cdecl f(S* object, void* source)
{
    Value value;
    convert(source, &value);
    if (object->enabled != 0)
        object->apply(&value);
}
}
