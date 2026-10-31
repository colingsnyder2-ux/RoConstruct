// from server: 100% by EspClaude
// roc 2009-06 004e67f0  unit: RBX::Network::Replicator::ChangePropertyItem  size: 29 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 004e67f0
//
// 004e67f0  8b4c2404             mov ecx, dword ptr [esp + 4]
// 004e67f4  e857f3ffff           call 0x4e5b50
// 004e67f9  8b442408             mov eax, dword ptr [esp + 8]
// 004e67fd  83ec08               sub esp, 8
// 004e6800  dd1c24               fstp qword ptr [esp]
// 004e6803  50                   push eax
// 004e6804  e8076cffff           call 0x4dd410
// 004e6809  83c40c               add esp, 0xc
// 004e680c  c3                   ret 
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
