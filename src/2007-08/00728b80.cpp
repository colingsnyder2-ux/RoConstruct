// from server: 100% by auto
// roc 2007-08 00728b80  unit: boost::signals::detail::Ubasic_connection::?$sp_counted_impl_p  size: 40 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 00728b80
//
// 00728b80  56                   push esi
// 00728b81  8bf1                 mov esi, ecx
// 00728b83  833e00               cmp dword ptr [esi], 0
// 00728b86  57                   push edi
// 00728b87  8b3dd8e67700         mov edi, dword ptr [0x77e6d8]
// 00728b8d  7502                 jne 0x728b91
// 00728b8f  ffd7                 call edi
// 00728b91  8b4604               mov eax, dword ptr [esi + 4]
// 00728b94  8b4004               mov eax, dword ptr [eax + 4]
// 00728b97  8b0e                 mov ecx, dword ptr [esi]
// 00728b99  894604               mov dword ptr [esi + 4], eax
// 00728b9c  3b4104               cmp eax, dword ptr [ecx + 4]
// 00728b9f  7502                 jne 0x728ba3
// 00728ba1  ffd7                 call edi
// 00728ba3  5f                   pop edi
// 00728ba4  8bc6                 mov eax, esi
// 00728ba6  5e                   pop esi
// 00728ba7  c3                   ret 
// standard library list<ptr> (function ??F?$_Const_iterator@$00@?$list@PAUT@@V?$allocator@PAUT@@@std@@@std@@QAEAAV012@XZ)

// stl: list<ptr>
struct T; typedef T* E;
#include <list>
template class std::list<E>;
