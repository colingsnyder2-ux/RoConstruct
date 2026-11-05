// from server: 100% by auto
// roc 2009-06 00618570  unit: RBX::VChangeHistoryService::?$FactoryProduct  size: 53 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00618570
//
// 00618570  56                   push esi
// 00618571  8bf1                 mov esi, ecx
// 00618573  8b06                 mov eax, dword ptr [esi]
// 00618575  57                   push edi
// 00618576  8b3dace98900         mov edi, dword ptr [0x89e9ac]
// 0061857c  85c0                 test eax, eax
// 0061857e  7508                 jne 0x618588
// 00618580  ffd7                 call edi
// 00618582  8b06                 mov eax, dword ptr [esi]
// 00618584  85c0                 test eax, eax
// 00618586  7404                 je 0x61858c
// 00618588  8b00                 mov eax, dword ptr [eax]
// 0061858a  eb02                 jmp 0x61858e
// 0061858c  33c0                 xor eax, eax
// 0061858e  8b4e04               mov ecx, dword ptr [esi + 4]
// 00618591  3b4814               cmp ecx, dword ptr [eax + 0x14]
// 00618594  7502                 jne 0x618598
// 00618596  ffd7                 call edi
// 00618598  8b5604               mov edx, dword ptr [esi + 4]
// 0061859b  8b02                 mov eax, dword ptr [edx]
// 0061859d  894604               mov dword ptr [esi + 4], eax
// 006185a0  5f                   pop edi
// 006185a1  8bc6                 mov eax, esi
// 006185a3  5e                   pop esi
// 006185a4  c3                   ret 
// standard library list<ptr> (function ??E?$_Const_iterator@$00@?$list@PAUT@@V?$allocator@PAUT@@@std@@@std@@QAEAAV012@XZ)

// stl: list<ptr>
struct T; typedef T* E;
#include <list>
template class std::list<E>;
