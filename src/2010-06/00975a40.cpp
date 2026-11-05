// from server: 100% by auto
// roc 2010-06 00975a40  unit: RBX::RightAngleRampBuilder  size: 65 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00975a40
//
// 00975a40  83ec08               sub esp, 8
// 00975a43  53                   push ebx
// 00975a44  55                   push ebp
// 00975a45  56                   push esi
// 00975a46  8bf1                 mov esi, ecx
// 00975a48  8b5e10               mov ebx, dword ptr [esi + 0x10]
// 00975a4b  57                   push edi
// 00975a4c  395e0c               cmp dword ptr [esi + 0xc], ebx
// 00975a4f  7606                 jbe 0x975a57
// 00975a51  ff150ca99e00         call dword ptr [0x9ea90c]
// 00975a57  8b7e0c               mov edi, dword ptr [esi + 0xc]
// 00975a5a  8b2e                 mov ebp, dword ptr [esi]
// 00975a5c  3b7e10               cmp edi, dword ptr [esi + 0x10]
// 00975a5f  7606                 jbe 0x975a67
// 00975a61  ff150ca99e00         call dword ptr [0x9ea90c]
// 00975a67  8b06                 mov eax, dword ptr [esi]
// 00975a69  53                   push ebx
// 00975a6a  55                   push ebp
// 00975a6b  57                   push edi
// 00975a6c  50                   push eax
// 00975a6d  8d442420             lea eax, [esp + 0x20]
// 00975a71  50                   push eax
// 00975a72  8bce                 mov ecx, esi
// 00975a74  e8d7aff6ff           call 0x8e0a50
// 00975a79  5f                   pop edi
// 00975a7a  5e                   pop esi
// 00975a7b  5d                   pop ebp
// 00975a7c  5b                   pop ebx
// 00975a7d  83c408               add esp, 8
// 00975a80  c3                   ret 
// standard library vector<ptr> (function ?clear@?$vector@PAUT@@V?$allocator@PAUT@@@std@@@std@@QAEXXZ)

// stl: vector<ptr>
struct T; typedef T* E;
#include <vector>
template class std::vector<E>;
