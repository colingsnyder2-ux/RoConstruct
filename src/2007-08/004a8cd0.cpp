// from server: 100% by EspClaude
// from server: 55% by tester
// roc 2007-08 004a8cd0  unit: RBX::Network::VClient::?$FactoryProduct  size: 33 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 004a8cd0
//
// 004a8cd0  51                   push ecx
// 004a8cd1  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 004a8cd5  8d0424               lea eax, [esp]
// 004a8cd8  50                   push eax
// 004a8cd9  51                   push ecx
// 004a8cda  e86179ffff           call 0x4a0640
// 004a8cdf  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 004a8ce3  83c408               add esp, 8
// 004a8ce6  8d1424               lea edx, [esp]
// 004a8ce9  52                   push edx
// 004a8cea  e811f4ffff           call 0x4a8100
// 004a8cef  59                   pop ecx
// 004a8cf0  c3                   ret 

struct Target {
    void* sub_4A8100(void** p);
};

extern "C" void __cdecl sub_4A0640(void*, void**);

void* __cdecl FactoryProduct_construct(Target* target, void* arg) {
    void* local;
    sub_4A0640(arg, &local);
    return target->sub_4A8100(&local);
}
