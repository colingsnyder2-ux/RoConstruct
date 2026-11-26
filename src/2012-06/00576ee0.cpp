// from server: 100% by Xemicl
// roc 2012-06 00576ee0  unit: RBX::Network::Replicator::RockyItem  size: 43 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00576ee0
//
// 00576ee0  8b4c2408             mov ecx, dword ptr [esp + 8]
// 00576ee4  83ec08               sub esp, 8
// 00576ee7  8d0424               lea eax, [esp]
// 00576eea  50                   push eax
// 00576eeb  51                   push ecx
// 00576eec  e8df56ffff           call 0x56c5d0
// 00576ef1  8b4c2414             mov ecx, dword ptr [esp + 0x14]
// 00576ef5  83c408               add esp, 8
// 00576ef8  83790400             cmp dword ptr [ecx + 4], 0
// 00576efc  7409                 je 0x576f07
// 00576efe  8d1424               lea edx, [esp]
// 00576f01  52                   push edx
// 00576f02  e849e8ffff           call 0x575750
// 00576f07  83c408               add esp, 8
// 00576f0a  c3                   ret 
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