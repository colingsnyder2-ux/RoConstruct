// from server: 100% by auto
// roc 2010-06 004ed200  unit: RBX::Network::Replicator::NewInstanceItem  size: 50 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 004ed200
//
// 004ed200  83ec08               sub esp, 8
// 004ed203  56                   push esi
// 004ed204  8bf1                 mov esi, ecx
// 004ed206  8b461c               mov eax, dword ptr [esi + 0x1c]
// 004ed209  57                   push edi
// 004ed20a  8b7e18               mov edi, dword ptr [esi + 0x18]
// 004ed20d  03c7                 add eax, edi
// 004ed20f  3bf8                 cmp edi, eax
// 004ed211  7606                 jbe 0x4ed219
// 004ed213  ff150ca99e00         call dword ptr [0x9ea90c]
// 004ed219  8b0e                 mov ecx, dword ptr [esi]
// 004ed21b  894c2408             mov dword ptr [esp + 8], ecx
// 004ed21f  8d4c2408             lea ecx, [esp + 8]
// 004ed223  897c240c             mov dword ptr [esp + 0xc], edi
// 004ed227  e824250500           call 0x53f750
// 004ed22c  5f                   pop edi
// 004ed22d  5e                   pop esi
// 004ed22e  83c408               add esp, 8
// 004ed231  c3                   ret 
// standard library deque<ptr> (function ?front@?$deque@PAUT@@V?$allocator@PAUT@@@std@@@std@@QBEABQAUT@@XZ)

// stl: deque<ptr>
struct T; typedef T* E;
#include <deque>
template class std::deque<E>;
