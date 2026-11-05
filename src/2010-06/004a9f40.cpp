// from server: 100% by auto
// roc 2010-06 004a9f40  unit: RBX::VBrickColor::?$TypedPropertyDescriptor  size: 65 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 004a9f40
//
// 004a9f40  83ec08               sub esp, 8
// 004a9f43  53                   push ebx
// 004a9f44  55                   push ebp
// 004a9f45  56                   push esi
// 004a9f46  8bf1                 mov esi, ecx
// 004a9f48  8b5e10               mov ebx, dword ptr [esi + 0x10]
// 004a9f4b  57                   push edi
// 004a9f4c  395e0c               cmp dword ptr [esi + 0xc], ebx
// 004a9f4f  7606                 jbe 0x4a9f57
// 004a9f51  ff150ca99e00         call dword ptr [0x9ea90c]
// 004a9f57  8b7e0c               mov edi, dword ptr [esi + 0xc]
// 004a9f5a  8b2e                 mov ebp, dword ptr [esi]
// 004a9f5c  3b7e10               cmp edi, dword ptr [esi + 0x10]
// 004a9f5f  7606                 jbe 0x4a9f67
// 004a9f61  ff150ca99e00         call dword ptr [0x9ea90c]
// 004a9f67  8b06                 mov eax, dword ptr [esi]
// 004a9f69  53                   push ebx
// 004a9f6a  55                   push ebp
// 004a9f6b  57                   push edi
// 004a9f6c  50                   push eax
// 004a9f6d  8d442420             lea eax, [esp + 0x20]
// 004a9f71  50                   push eax
// 004a9f72  8bce                 mov ecx, esi
// 004a9f74  e887c6f9ff           call 0x446600
// 004a9f79  5f                   pop edi
// 004a9f7a  5e                   pop esi
// 004a9f7b  5d                   pop ebp
// 004a9f7c  5b                   pop ebx
// 004a9f7d  83c408               add esp, 8
// 004a9f80  c3                   ret 
// standard library vector<ptr> (function ?clear@?$vector@PAUT@@V?$allocator@PAUT@@@std@@@std@@QAEXXZ)

// stl: vector<ptr>
struct T; typedef T* E;
#include <vector>
template class std::vector<E>;
