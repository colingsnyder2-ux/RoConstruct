// from server: 100% by auto
// roc 2009-06 00440ad0  unit: RBX::Reflection::M::?$TypedPropertyDescriptor  size: 65 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00440ad0
//
// 00440ad0  83ec08               sub esp, 8
// 00440ad3  53                   push ebx
// 00440ad4  55                   push ebp
// 00440ad5  56                   push esi
// 00440ad6  8bf1                 mov esi, ecx
// 00440ad8  8b5e10               mov ebx, dword ptr [esi + 0x10]
// 00440adb  57                   push edi
// 00440adc  395e0c               cmp dword ptr [esi + 0xc], ebx
// 00440adf  7606                 jbe 0x440ae7
// 00440ae1  ff15ace98900         call dword ptr [0x89e9ac]
// 00440ae7  8b7e0c               mov edi, dword ptr [esi + 0xc]
// 00440aea  8b2e                 mov ebp, dword ptr [esi]
// 00440aec  3b7e10               cmp edi, dword ptr [esi + 0x10]
// 00440aef  7606                 jbe 0x440af7
// 00440af1  ff15ace98900         call dword ptr [0x89e9ac]
// 00440af7  8b06                 mov eax, dword ptr [esi]
// 00440af9  53                   push ebx
// 00440afa  55                   push ebp
// 00440afb  57                   push edi
// 00440afc  50                   push eax
// 00440afd  8d442420             lea eax, [esp + 0x20]
// 00440b01  50                   push eax
// 00440b02  8bce                 mov ecx, esi
// 00440b04  e8e7fcffff           call 0x4407f0
// 00440b09  5f                   pop edi
// 00440b0a  5e                   pop esi
// 00440b0b  5d                   pop ebp
// 00440b0c  5b                   pop ebx
// 00440b0d  83c408               add esp, 8
// 00440b10  c3                   ret 
// standard library vector<ptr> (function ?clear@?$vector@PAUT@@V?$allocator@PAUT@@@std@@@std@@QAEXXZ)

// stl: vector<ptr>
struct T; typedef T* E;
#include <vector>
template class std::vector<E>;
