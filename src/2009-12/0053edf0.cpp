// from server: 100% by auto
// roc 2009-12 0053edf0  unit: RBX::Network::Replicator::NewInstanceItem  size: 50 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0053edf0
//
// 0053edf0  83ec08               sub esp, 8
// 0053edf3  56                   push esi
// 0053edf4  8bf1                 mov esi, ecx
// 0053edf6  8b461c               mov eax, dword ptr [esi + 0x1c]
// 0053edf9  57                   push edi
// 0053edfa  8b7e18               mov edi, dword ptr [esi + 0x18]
// 0053edfd  03c7                 add eax, edi
// 0053edff  3bf8                 cmp edi, eax
// 0053ee01  7606                 jbe 0x53ee09
// 0053ee03  ff1560b79800         call dword ptr [0x98b760]
// 0053ee09  8b0e                 mov ecx, dword ptr [esi]
// 0053ee0b  894c2408             mov dword ptr [esp + 8], ecx
// 0053ee0f  8d4c2408             lea ecx, [esp + 8]
// 0053ee13  897c240c             mov dword ptr [esp + 0xc], edi
// 0053ee17  e8941aefff           call 0x4308b0
// 0053ee1c  5f                   pop edi
// 0053ee1d  5e                   pop esi
// 0053ee1e  83c408               add esp, 8
// 0053ee21  c3                   ret 
// standard library deque<ptr> (function ?front@?$deque@PAUT@@V?$allocator@PAUT@@@std@@@std@@QBEABQAUT@@XZ)

// stl: deque<ptr>
struct T; typedef T* E;
#include <deque>
template class std::deque<E>;
