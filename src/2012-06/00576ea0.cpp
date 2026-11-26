// from server: 100% by Xemicl
// roc 2012-06 00576ea0  unit: RBX::Network::Replicator::RockyItem  size: 29 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00576ea0
//
// 00576ea0  8b4c2404             mov ecx, dword ptr [esp + 4]
// 00576ea4  e8b7e7ffff           call 0x575660
// 00576ea9  8b442408             mov eax, dword ptr [esp + 8]
// 00576ead  83ec08               sub esp, 8
// 00576eb0  dd1c24               fstp qword ptr [esp]
// 00576eb3  50                   push eax
// 00576eb4  e8b756ffff           call 0x56c570
// 00576eb9  83c40c               add esp, 0xc
// 00576ebc  c3                   ret 
// copied from an identical function in another client (function ?serialize@ns_ROCX0000a9@@YAXPAUS@1@PAX@Z)

namespace ns_ROCX0000a9 {
struct S {
    double getValue();
};

void __cdecl writeValue(void* output, double value);

void __cdecl serialize(S* object, void* output)
{
    writeValue(output, object->getValue());
}
}