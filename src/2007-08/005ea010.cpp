// from server: 100% by auto
// roc 2007-08 005ea010  unit: RBX::VFlagStand::?$FactoryProduct  size: 143 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 005ea010
//
// 005ea010  83ec0c               sub esp, 0xc
// 005ea013  53                   push ebx
// 005ea014  55                   push ebp
// 005ea015  8be9                 mov ebp, ecx
// 005ea017  8b4504               mov eax, dword ptr [ebp + 4]
// 005ea01a  56                   push esi
// 005ea01b  8b30                 mov esi, dword ptr [eax]
// 005ea01d  57                   push edi
// 005ea01e  89442410             mov dword ptr [esp + 0x10], eax
// 005ea022  8bfd                 mov edi, ebp
// 005ea024  85ff                 test edi, edi
// 005ea026  7404                 je 0x5ea02c
// 005ea028  3bfd                 cmp edi, ebp
// 005ea02a  740a                 je 0x5ea036
// 005ea02c  8b1dd8e67700         mov ebx, dword ptr [0x77e6d8]
// 005ea032  ffd3                 call ebx
// 005ea034  eb06                 jmp 0x5ea03c
// 005ea036  8b1dd8e67700         mov ebx, dword ptr [0x77e6d8]
// 005ea03c  3b742410             cmp esi, dword ptr [esp + 0x10]
// 005ea040  7453                 je 0x5ea095
// 005ea042  85ff                 test edi, edi
// 005ea044  7502                 jne 0x5ea048
// 005ea046  ffd3                 call ebx
// 005ea048  3b7704               cmp esi, dword ptr [edi + 4]
// 005ea04b  7502                 jne 0x5ea04f
// 005ea04d  ffd3                 call ebx
// 005ea04f  8b4608               mov eax, dword ptr [esi + 8]
// 005ea052  8b4c2420             mov ecx, dword ptr [esp + 0x20]
// 005ea056  3b01                 cmp eax, dword ptr [ecx]
// 005ea058  7530                 jne 0x5ea08a
// 005ea05a  3b7704               cmp esi, dword ptr [edi + 4]
// 005ea05d  89742418             mov dword ptr [esp + 0x18], esi
// 005ea061  7502                 jne 0x5ea065
// 005ea063  ffd3                 call ebx
// 005ea065  3b7504               cmp esi, dword ptr [ebp + 4]
// 005ea068  8b1e                 mov ebx, dword ptr [esi]
// 005ea06a  741a                 je 0x5ea086
// 005ea06c  8b5604               mov edx, dword ptr [esi + 4]
// 005ea06f  891a                 mov dword ptr [edx], ebx
// 005ea071  8b06                 mov eax, dword ptr [esi]
// 005ea073  8b4e04               mov ecx, dword ptr [esi + 4]
// 005ea076  56                   push esi
// 005ea077  894804               mov dword ptr [eax + 4], ecx
// 005ea07a  e8e35b0400           call 0x62fc62
// 005ea07f  83c404               add esp, 4
// 005ea082  834508ff             add dword ptr [ebp + 8], -1
// 005ea086  8bf3                 mov esi, ebx
// 005ea088  eb9a                 jmp 0x5ea024
// 005ea08a  3b7704               cmp esi, dword ptr [edi + 4]
// 005ea08d  7502                 jne 0x5ea091
// 005ea08f  ffd3                 call ebx
// 005ea091  8b36                 mov esi, dword ptr [esi]
// 005ea093  eb8f                 jmp 0x5ea024
// 005ea095  5f                   pop edi
// 005ea096  5e                   pop esi
// 005ea097  5d                   pop ebp
// 005ea098  5b                   pop ebx
// 005ea099  83c40c               add esp, 0xc
// 005ea09c  c20400               ret 4
// standard library list<ptr> (function ?remove@?$list@PAUT@@V?$allocator@PAUT@@@std@@@std@@QAEXABQAUT@@@Z)

// stl: list<ptr>
struct T; typedef T* E;
#include <list>
template class std::list<E>;
