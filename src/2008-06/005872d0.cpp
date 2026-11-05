// from server: 100% by auto
// roc 2008-06 005872d0  unit: RBX::VChangeHistoryService::?$FactoryProduct  size: 53 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 005872d0
//
// 005872d0  56                   push esi
// 005872d1  8bf1                 mov esi, ecx
// 005872d3  8b06                 mov eax, dword ptr [esi]
// 005872d5  57                   push edi
// 005872d6  8b3d90288000         mov edi, dword ptr [0x802890]
// 005872dc  85c0                 test eax, eax
// 005872de  7508                 jne 0x5872e8
// 005872e0  ffd7                 call edi
// 005872e2  8b06                 mov eax, dword ptr [esi]
// 005872e4  85c0                 test eax, eax
// 005872e6  7404                 je 0x5872ec
// 005872e8  8b00                 mov eax, dword ptr [eax]
// 005872ea  eb02                 jmp 0x5872ee
// 005872ec  33c0                 xor eax, eax
// 005872ee  8b4e04               mov ecx, dword ptr [esi + 4]
// 005872f1  3b4814               cmp ecx, dword ptr [eax + 0x14]
// 005872f4  7502                 jne 0x5872f8
// 005872f6  ffd7                 call edi
// 005872f8  8b5604               mov edx, dword ptr [esi + 4]
// 005872fb  8b02                 mov eax, dword ptr [edx]
// 005872fd  894604               mov dword ptr [esi + 4], eax
// 00587300  5f                   pop edi
// 00587301  8bc6                 mov eax, esi
// 00587303  5e                   pop esi
// 00587304  c3                   ret 
// standard library list<ptr> (function ??E?$_Const_iterator@$00@?$list@PAUT@@V?$allocator@PAUT@@@std@@@std@@QAEAAV012@XZ)

// stl: list<ptr>
struct T; typedef T* E;
#include <list>
template class std::list<E>;
