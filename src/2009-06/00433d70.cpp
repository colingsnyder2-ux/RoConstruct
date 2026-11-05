// from server: 100% by auto
// roc 2009-06 00433d70  unit: IIHAAH::?$CMap  size: 101 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00433d70
//
// 00433d70  83ec08               sub esp, 8
// 00433d73  56                   push esi
// 00433d74  8bf1                 mov esi, ecx
// 00433d76  8b4e0c               mov ecx, dword ptr [esi + 0xc]
// 00433d79  57                   push edi
// 00433d7a  85c9                 test ecx, ecx
// 00433d7c  7504                 jne 0x433d82
// 00433d7e  33c0                 xor eax, eax
// 00433d80  eb08                 jmp 0x433d8a
// 00433d82  8b4614               mov eax, dword ptr [esi + 0x14]
// 00433d85  2bc1                 sub eax, ecx
// 00433d87  c1f802               sar eax, 2
// 00433d8a  8b7e10               mov edi, dword ptr [esi + 0x10]
// 00433d8d  8bd7                 mov edx, edi
// 00433d8f  2bd1                 sub edx, ecx
// 00433d91  c1fa02               sar edx, 2
// 00433d94  3bd0                 cmp edx, eax
// 00433d96  7316                 jae 0x433dae
// 00433d98  8b442414             mov eax, dword ptr [esp + 0x14]
// 00433d9c  8b08                 mov ecx, dword ptr [eax]
// 00433d9e  890f                 mov dword ptr [edi], ecx
// 00433da0  83c704               add edi, 4
// 00433da3  897e10               mov dword ptr [esi + 0x10], edi
// 00433da6  5f                   pop edi
// 00433da7  5e                   pop esi
// 00433da8  83c408               add esp, 8
// 00433dab  c20400               ret 4
// 00433dae  3bcf                 cmp ecx, edi
// 00433db0  7606                 jbe 0x433db8
// 00433db2  ff15ace98900         call dword ptr [0x89e9ac]
// 00433db8  8b542414             mov edx, dword ptr [esp + 0x14]
// 00433dbc  8b06                 mov eax, dword ptr [esi]
// 00433dbe  52                   push edx
// 00433dbf  57                   push edi
// 00433dc0  50                   push eax
// 00433dc1  8d442414             lea eax, [esp + 0x14]
// 00433dc5  50                   push eax
// 00433dc6  8bce                 mov ecx, esi
// 00433dc8  e893a92c00           call 0x6fe760
// 00433dcd  5f                   pop edi
// 00433dce  5e                   pop esi
// 00433dcf  83c408               add esp, 8
// 00433dd2  c20400               ret 4
// standard library vector<ptr> (function ?push_back@?$vector@PAUT@@V?$allocator@PAUT@@@std@@@std@@QAEXABQAUT@@@Z)

// stl: vector<ptr>
struct T; typedef T* E;
#include <vector>
template class std::vector<E>;
