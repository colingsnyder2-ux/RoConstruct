// from server: 100% by auto
// roc 2009-12 00434ee0  unit: IIHAAH::?$CMap  size: 65 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00434ee0
//
// 00434ee0  83ec08               sub esp, 8
// 00434ee3  53                   push ebx
// 00434ee4  55                   push ebp
// 00434ee5  56                   push esi
// 00434ee6  8bf1                 mov esi, ecx
// 00434ee8  8b5e10               mov ebx, dword ptr [esi + 0x10]
// 00434eeb  57                   push edi
// 00434eec  395e0c               cmp dword ptr [esi + 0xc], ebx
// 00434eef  7606                 jbe 0x434ef7
// 00434ef1  ff1560b79800         call dword ptr [0x98b760]
// 00434ef7  8b7e0c               mov edi, dword ptr [esi + 0xc]
// 00434efa  8b2e                 mov ebp, dword ptr [esi]
// 00434efc  3b7e10               cmp edi, dword ptr [esi + 0x10]
// 00434eff  7606                 jbe 0x434f07
// 00434f01  ff1560b79800         call dword ptr [0x98b760]
// 00434f07  8b06                 mov eax, dword ptr [esi]
// 00434f09  53                   push ebx
// 00434f0a  55                   push ebp
// 00434f0b  57                   push edi
// 00434f0c  50                   push eax
// 00434f0d  8d442420             lea eax, [esp + 0x20]
// 00434f11  50                   push eax
// 00434f12  8bce                 mov ecx, esi
// 00434f14  e8279d0700           call 0x4aec40
// 00434f19  5f                   pop edi
// 00434f1a  5e                   pop esi
// 00434f1b  5d                   pop ebp
// 00434f1c  5b                   pop ebx
// 00434f1d  83c408               add esp, 8
// 00434f20  c3                   ret 
// standard library vector<ptr> (function ?clear@?$vector@PAUT@@V?$allocator@PAUT@@@std@@@std@@QAEXXZ)

// stl: vector<ptr>
struct T; typedef T* E;
#include <vector>
template class std::vector<E>;
