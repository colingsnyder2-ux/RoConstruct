// from server: 100% by auto
// roc 2010-06 00704a40  unit: RBX::VInstance::?$NonFactoryProduct  size: 65 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00704a40
//
// 00704a40  83ec08               sub esp, 8
// 00704a43  53                   push ebx
// 00704a44  55                   push ebp
// 00704a45  56                   push esi
// 00704a46  8bf1                 mov esi, ecx
// 00704a48  8b5e10               mov ebx, dword ptr [esi + 0x10]
// 00704a4b  57                   push edi
// 00704a4c  395e0c               cmp dword ptr [esi + 0xc], ebx
// 00704a4f  7606                 jbe 0x704a57
// 00704a51  ff150ca99e00         call dword ptr [0x9ea90c]
// 00704a57  8b7e0c               mov edi, dword ptr [esi + 0xc]
// 00704a5a  8b2e                 mov ebp, dword ptr [esi]
// 00704a5c  3b7e10               cmp edi, dword ptr [esi + 0x10]
// 00704a5f  7606                 jbe 0x704a67
// 00704a61  ff150ca99e00         call dword ptr [0x9ea90c]
// 00704a67  8b06                 mov eax, dword ptr [esi]
// 00704a69  53                   push ebx
// 00704a6a  55                   push ebp
// 00704a6b  57                   push edi
// 00704a6c  50                   push eax
// 00704a6d  8d442420             lea eax, [esp + 0x20]
// 00704a71  50                   push eax
// 00704a72  8bce                 mov ecx, esi
// 00704a74  e807feffff           call 0x704880
// 00704a79  5f                   pop edi
// 00704a7a  5e                   pop esi
// 00704a7b  5d                   pop ebp
// 00704a7c  5b                   pop ebx
// 00704a7d  83c408               add esp, 8
// 00704a80  c3                   ret 
// standard library vector<ptr> (function ?clear@?$vector@PAUT@@V?$allocator@PAUT@@@std@@@std@@QAEXXZ)

// stl: vector<ptr>
struct T; typedef T* E;
#include <vector>
template class std::vector<E>;
