// from server: 100% by auto
// roc 2009-06 004e8460  unit: RBX::JointsService  size: 50 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 004e8460
//
// 004e8460  83ec08               sub esp, 8
// 004e8463  56                   push esi
// 004e8464  8bf1                 mov esi, ecx
// 004e8466  8b461c               mov eax, dword ptr [esi + 0x1c]
// 004e8469  57                   push edi
// 004e846a  8b7e18               mov edi, dword ptr [esi + 0x18]
// 004e846d  03c7                 add eax, edi
// 004e846f  3bf8                 cmp edi, eax
// 004e8471  7606                 jbe 0x4e8479
// 004e8473  ff15ace98900         call dword ptr [0x89e9ac]
// 004e8479  8b0e                 mov ecx, dword ptr [esi]
// 004e847b  894c2408             mov dword ptr [esp + 8], ecx
// 004e847f  8d4c2408             lea ecx, [esp + 8]
// 004e8483  897c240c             mov dword ptr [esp + 0xc], edi
// 004e8487  e894e3faff           call 0x496820
// 004e848c  5f                   pop edi
// 004e848d  5e                   pop esi
// 004e848e  83c408               add esp, 8
// 004e8491  c3                   ret 
// standard library deque<ptr> (function ?front@?$deque@PAUT@@V?$allocator@PAUT@@@std@@@std@@QBEABQAUT@@XZ)

// stl: deque<ptr>
struct T; typedef T* E;
#include <deque>
template class std::deque<E>;
