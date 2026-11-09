// from server: 100% by auto
// roc 2010-06 00742b10  unit: RBX::VHttp::?$sp_counted_impl_p  size: 65 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00742b10
//
// 00742b10  83ec08               sub esp, 8
// 00742b13  53                   push ebx
// 00742b14  55                   push ebp
// 00742b15  56                   push esi
// 00742b16  8bf1                 mov esi, ecx
// 00742b18  8b5e10               mov ebx, dword ptr [esi + 0x10]
// 00742b1b  57                   push edi
// 00742b1c  395e0c               cmp dword ptr [esi + 0xc], ebx
// 00742b1f  7606                 jbe 0x742b27
// 00742b21  ff150ca99e00         call dword ptr [0x9ea90c]
// 00742b27  8b7e0c               mov edi, dword ptr [esi + 0xc]
// 00742b2a  8b2e                 mov ebp, dword ptr [esi]
// 00742b2c  3b7e10               cmp edi, dword ptr [esi + 0x10]
// 00742b2f  7606                 jbe 0x742b37
// 00742b31  ff150ca99e00         call dword ptr [0x9ea90c]
// 00742b37  8b06                 mov eax, dword ptr [esi]
// 00742b39  53                   push ebx
// 00742b3a  55                   push ebp
// 00742b3b  57                   push edi
// 00742b3c  50                   push eax
// 00742b3d  8d442420             lea eax, [esp + 0x20]
// 00742b41  50                   push eax
// 00742b42  8bce                 mov ecx, esi
// 00742b44  e8d7faffff           call 0x742620
// 00742b49  5f                   pop edi
// 00742b4a  5e                   pop esi
// 00742b4b  5d                   pop ebp
// 00742b4c  5b                   pop ebx
// 00742b4d  83c408               add esp, 8
// 00742b50  c3                   ret 
// standard library vector<ptr> (function ?clear@?$vector@PAUT@@V?$allocator@PAUT@@@std@@@std@@QAEXXZ)

// stl: vector<ptr>
struct T; typedef T* E;
#include <vector>
template class std::vector<E>;
