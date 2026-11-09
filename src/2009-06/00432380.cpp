// from server: 100% by auto
// roc 2009-06 00432380  unit: IIHAAH::?$CMap  size: 72 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00432380
//
// 00432380  56                   push esi
// 00432381  33c0                 xor eax, eax
// 00432383  57                   push edi
// 00432384  8b7c240c             mov edi, dword ptr [esp + 0xc]
// 00432388  8bf1                 mov esi, ecx
// 0043238a  89460c               mov dword ptr [esi + 0xc], eax
// 0043238d  894610               mov dword ptr [esi + 0x10], eax
// 00432390  894614               mov dword ptr [esi + 0x14], eax
// 00432393  3bf8                 cmp edi, eax
// 00432395  7507                 jne 0x43239e
// 00432397  5f                   pop edi
// 00432398  32c0                 xor al, al
// 0043239a  5e                   pop esi
// 0043239b  c20400               ret 4
// 0043239e  81ffffffff3f         cmp edi, 0x3fffffff
// 004323a4  7605                 jbe 0x4323ab
// 004323a6  e8b5df0500           call 0x490360
// 004323ab  50                   push eax
// 004323ac  57                   push edi
// 004323ad  e84e661c00           call 0x5f8a00
// 004323b2  89460c               mov dword ptr [esi + 0xc], eax
// 004323b5  894610               mov dword ptr [esi + 0x10], eax
// 004323b8  83c408               add esp, 8
// 004323bb  8d04b8               lea eax, [eax + edi*4]
// 004323be  894614               mov dword ptr [esi + 0x14], eax
// 004323c1  5f                   pop edi
// 004323c2  b001                 mov al, 1
// 004323c4  5e                   pop esi
// 004323c5  c20400               ret 4
// standard library vector<ptr> (function ?_Buy@?$vector@PAUT@@V?$allocator@PAUT@@@std@@@std@@IAE_NI@Z)

// stl: vector<ptr>
struct T; typedef T* E;
#include <vector>
template class std::vector<E>;
