// from server: 100% by Xemicl
// from server: 100% by Intel
// roc 2012-06 008e3f80  unit: RBX::Reflection::_N::?$TypedPropertyDescriptor  size: 43 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 008e3f80
//
// 008e3f80  56                   push esi
// 008e3f81  8bf1                 mov esi, ecx
// 008e3f83  8b4628               mov eax, dword ptr [esi + 0x28]
// 008e3f86  50                   push eax
// 008e3f87  e888e10900           call 0x982114
// 008e3f8c  83c404               add esp, 4
// 008e3f8f  f644240801           test byte ptr [esp + 8], 1
// 008e3f94  c7062c3cb400         mov dword ptr [esi], 0xb43c2c
// 008e3f9a  7409                 je 0x8e3fa5
// 008e3f9c  56                   push esi
// 008e3f9d  e872e10900           call 0x982114
// 008e3fa2  83c404               add esp, 4
// 008e3fa5  8bc6                 mov eax, esi
// 008e3fa7  5e                   pop esi
// 008e3fa8  c20400               ret 4

extern "C" void __cdecl external_func(void* param);

struct TypedPropertyDescriptor {
    char pad[0x2c];
    void* field_28;
    
    TypedPropertyDescriptor* method(int arg);
};

TypedPropertyDescriptor* TypedPropertyDescriptor::method(int arg) {
    external_func(field_28);
    
    *(void**)this = (void*)0xB43C2C;
    
    if (arg & 1) {
        external_func(this);
    }
    
    return this;
}
