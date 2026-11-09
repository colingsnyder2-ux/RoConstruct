// from server: 100% by auto
// roc 2007-03 00593670  unit: seg_00590000  size: 98 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 00593670
//
// 00593670  53                   push ebx
// 00593671  55                   push ebp
// 00593672  56                   push esi
// 00593673  8b7104               mov esi, dword ptr [ecx + 4]
// 00593676  85f6                 test esi, esi
// 00593678  57                   push edi
// 00593679  8b7908               mov edi, dword ptr [ecx + 8]
// 0059367c  7506                 jne 0x593684
// 0059367e  ff1544e97700         call dword ptr [0x77e944]
// 00593684  8b460c               mov eax, dword ptr [esi + 0xc]
// 00593687  8b4c2414             mov ecx, dword ptr [esp + 0x14]
// 0059368b  8b5610               mov edx, dword ptr [esi + 0x10]
// 0059368e  03f9                 add edi, ecx
// 00593690  03d0                 add edx, eax
// 00593692  3bfa                 cmp edi, edx
// 00593694  7704                 ja 0x59369a
// 00593696  3bf8                 cmp edi, eax
// 00593698  7306                 jae 0x5936a0
// 0059369a  ff1544e97700         call dword ptr [0x77e944]
// 005936a0  8b4610               mov eax, dword ptr [esi + 0x10]
// 005936a3  03460c               add eax, dword ptr [esi + 0xc]
// 005936a6  8bdf                 mov ebx, edi
// 005936a8  8bef                 mov ebp, edi
// 005936aa  c1eb04               shr ebx, 4
// 005936ad  83e50f               and ebp, 0xf
// 005936b0  3bf8                 cmp edi, eax
// 005936b2  7206                 jb 0x5936ba
// 005936b4  ff1544e97700         call dword ptr [0x77e944]
// 005936ba  8b4608               mov eax, dword ptr [esi + 8]
// 005936bd  3bc3                 cmp eax, ebx
// 005936bf  7702                 ja 0x5936c3
// 005936c1  2bd8                 sub ebx, eax
// 005936c3  8b4e04               mov ecx, dword ptr [esi + 4]
// 005936c6  8b0499               mov eax, dword ptr [ecx + ebx*4]
// 005936c9  5f                   pop edi
// 005936ca  5e                   pop esi
// 005936cb  03c5                 add eax, ebp
// 005936cd  5d                   pop ebp
// 005936ce  5b                   pop ebx
// 005936cf  c20400               ret 4
// standard library deque<char> (function ??A?$_Deque_iterator@DV?$allocator@D@std@@$00@std@@QBEAADH@Z)

// stl: deque<char>
typedef char E;
#include <deque>
template class std::deque<E>;
