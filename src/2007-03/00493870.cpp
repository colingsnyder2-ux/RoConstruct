// from server: 100% by auto
// roc 2007-03 00493870  unit: seg_00490000  size: 73 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 00493870
//
// 00493870  53                   push ebx
// 00493871  55                   push ebp
// 00493872  56                   push esi
// 00493873  8bf1                 mov esi, ecx
// 00493875  8b4610               mov eax, dword ptr [esi + 0x10]
// 00493878  57                   push edi
// 00493879  8b7e0c               mov edi, dword ptr [esi + 0xc]
// 0049387c  03c7                 add eax, edi
// 0049387e  3bf8                 cmp edi, eax
// 00493880  7606                 jbe 0x493888
// 00493882  ff1544e97700         call dword ptr [0x77e944]
// 00493888  8b4e10               mov ecx, dword ptr [esi + 0x10]
// 0049388b  034e0c               add ecx, dword ptr [esi + 0xc]
// 0049388e  8bdf                 mov ebx, edi
// 00493890  8bef                 mov ebp, edi
// 00493892  c1eb02               shr ebx, 2
// 00493895  83e503               and ebp, 3
// 00493898  3bf9                 cmp edi, ecx
// 0049389a  7206                 jb 0x4938a2
// 0049389c  ff1544e97700         call dword ptr [0x77e944]
// 004938a2  8b4608               mov eax, dword ptr [esi + 8]
// 004938a5  3bc3                 cmp eax, ebx
// 004938a7  7702                 ja 0x4938ab
// 004938a9  2bd8                 sub ebx, eax
// 004938ab  8b5604               mov edx, dword ptr [esi + 4]
// 004938ae  8b049a               mov eax, dword ptr [edx + ebx*4]
// 004938b1  5f                   pop edi
// 004938b2  5e                   pop esi
// 004938b3  8d04a8               lea eax, [eax + ebp*4]
// 004938b6  5d                   pop ebp
// 004938b7  5b                   pop ebx
// 004938b8  c3                   ret 
// standard library deque<ptr> (function ?front@?$deque@PAUT@@V?$allocator@PAUT@@@std@@@std@@QBEABQAUT@@XZ)

// stl: deque<ptr>
struct T; typedef T* E;
#include <deque>
template class std::deque<E>;
