// from server: 100% by auto
// roc 2010-06 006e4af0  unit: RBX::VLuaDragger::?$FactoryProduct  size: 65 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 006e4af0
//
// 006e4af0  83ec08               sub esp, 8
// 006e4af3  53                   push ebx
// 006e4af4  55                   push ebp
// 006e4af5  56                   push esi
// 006e4af6  8bf1                 mov esi, ecx
// 006e4af8  8b5e10               mov ebx, dword ptr [esi + 0x10]
// 006e4afb  57                   push edi
// 006e4afc  395e0c               cmp dword ptr [esi + 0xc], ebx
// 006e4aff  7606                 jbe 0x6e4b07
// 006e4b01  ff150ca99e00         call dword ptr [0x9ea90c]
// 006e4b07  8b7e0c               mov edi, dword ptr [esi + 0xc]
// 006e4b0a  8b2e                 mov ebp, dword ptr [esi]
// 006e4b0c  3b7e10               cmp edi, dword ptr [esi + 0x10]
// 006e4b0f  7606                 jbe 0x6e4b17
// 006e4b11  ff150ca99e00         call dword ptr [0x9ea90c]
// 006e4b17  8b06                 mov eax, dword ptr [esi]
// 006e4b19  53                   push ebx
// 006e4b1a  55                   push ebp
// 006e4b1b  57                   push edi
// 006e4b1c  50                   push eax
// 006e4b1d  8d442420             lea eax, [esp + 0x20]
// 006e4b21  50                   push eax
// 006e4b22  8bce                 mov ecx, esi
// 006e4b24  e8b7feffff           call 0x6e49e0
// 006e4b29  5f                   pop edi
// 006e4b2a  5e                   pop esi
// 006e4b2b  5d                   pop ebp
// 006e4b2c  5b                   pop ebx
// 006e4b2d  83c408               add esp, 8
// 006e4b30  c3                   ret 
// standard library vector<ptr> (function ?clear@?$vector@PAUT@@V?$allocator@PAUT@@@std@@@std@@QAEXXZ)

// stl: vector<ptr>
struct T; typedef T* E;
#include <vector>
template class std::vector<E>;
