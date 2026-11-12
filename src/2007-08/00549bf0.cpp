// from server: 50% by EspClaude
// from server: 43% by colin
// roc 2007-08 00549bf0  unit: RBX::VInstance::?$NonFactoryProduct  size: 144 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 00549bf0
//
// 00549bf0  56                   push esi
// 00549bf1  8bf1                 mov esi, ecx
// 00549bf3  c706c0717a00         mov dword ptr [esi], 0x7a71c0
// 00549bf9  8b4608               mov eax, dword ptr [esi + 8]
// 00549bfc  85c0                 test eax, eax
// 00549bfe  7409                 je 0x549c09
// 00549c00  50                   push eax
// 00549c01  e85c600e00           call 0x62fc62
// 00549c06  83c404               add esp, 4
// 00549c09  c7460800000000       mov dword ptr [esi + 8], 0
// 00549c10  c7460c00000000       mov dword ptr [esi + 0xc], 0
// 00549c17  c7461000000000       mov dword ptr [esi + 0x10], 0
// 00549c1e  5e                   pop esi
// 00549c1f  c3                   ret 
// 00549c20  56                   push esi
// 00549c21  8bf1                 mov esi, ecx
// 00549c23  c706d0717a00         mov dword ptr [esi], 0x7a71d0
// 00549c29  8b4608               mov eax, dword ptr [esi + 8]
// 00549c2c  85c0                 test eax, eax
// 00549c2e  7409                 je 0x549c39
// 00549c30  50                   push eax
// 00549c31  e82c600e00           call 0x62fc62
// 00549c36  83c404               add esp, 4
// 00549c39  c7460800000000       mov dword ptr [esi + 8], 0
// 00549c40  c7460c00000000       mov dword ptr [esi + 0xc], 0
// 00549c47  c7461000000000       mov dword ptr [esi + 0x10], 0
// 00549c4e  5e                   pop esi
// 00549c4f  c3                   ret 
// 00549c50  56                   push esi
// 00549c51  8bf1                 mov esi, ecx
// 00549c53  c706e0717a00         mov dword ptr [esi], 0x7a71e0
// 00549c59  8b4608               mov eax, dword ptr [esi + 8]
// 00549c5c  85c0                 test eax, eax
// 00549c5e  7409                 je 0x549c69
// 00549c60  50                   push eax
// 00549c61  e8fc5f0e00           call 0x62fc62
// 00549c66  83c404               add esp, 4
// 00549c69  c7460800000000       mov dword ptr [esi + 8], 0
// 00549c70  c7460c00000000       mov dword ptr [esi + 0xc], 0
// 00549c77  c7461000000000       mov dword ptr [esi + 0x10], 0
// 00549c7e  5e                   pop esi
// 00549c7f  c3                   ret 


#include <vector>

struct NonFactoryProduct {
    virtual void f();
    ~NonFactoryProduct();
    std::vector<int> items;
};

NonFactoryProduct::~NonFactoryProduct()
{
}
