// from server: 100% by auto
// roc 2008-06 0042a8f0  unit: boost::detail::H::?$sp_counted_impl_p  size: 49 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 0042a8f0
//
// 0042a8f0  56                   push esi
// 0042a8f1  8bf1                 mov esi, ecx
// 0042a8f3  8b06                 mov eax, dword ptr [esi]
// 0042a8f5  57                   push edi
// 0042a8f6  8b3d90288000         mov edi, dword ptr [0x802890]
// 0042a8fc  85c0                 test eax, eax
// 0042a8fe  7508                 jne 0x42a908
// 0042a900  ffd7                 call edi
// 0042a902  8b06                 mov eax, dword ptr [esi]
// 0042a904  85c0                 test eax, eax
// 0042a906  7404                 je 0x42a90c
// 0042a908  8b00                 mov eax, dword ptr [eax]
// 0042a90a  eb02                 jmp 0x42a90e
// 0042a90c  33c0                 xor eax, eax
// 0042a90e  8b4e04               mov ecx, dword ptr [esi + 4]
// 0042a911  3b4814               cmp ecx, dword ptr [eax + 0x14]
// 0042a914  7502                 jne 0x42a918
// 0042a916  ffd7                 call edi
// 0042a918  8b4604               mov eax, dword ptr [esi + 4]
// 0042a91b  5f                   pop edi
// 0042a91c  83c008               add eax, 8
// 0042a91f  5e                   pop esi
// 0042a920  c3                   ret 
// standard library list<ptr> (function ??D?$_Const_iterator@$00@?$list@PAUT@@V?$allocator@PAUT@@@std@@@std@@QBEABQAUT@@XZ)

// stl: list<ptr>
struct T; typedef T* E;
#include <list>
template class std::list<E>;
