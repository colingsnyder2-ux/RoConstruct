// from server: 100% by auto
// roc 2008-06 004146d0  unit: CopyVerb  size: 112 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 004146d0
//
// 004146d0  6aff                 push -1
// 004146d2  6828d97b00           push 0x7bd928
// 004146d7  64a100000000         mov eax, dword ptr fs:[0]
// 004146dd  50                   push eax
// 004146de  64892500000000       mov dword ptr fs:[0], esp
// 004146e5  83ec0c               sub esp, 0xc
// 004146e8  56                   push esi
// 004146e9  8bf1                 mov esi, ecx
// 004146eb  89742404             mov dword ptr [esp + 4], esi
// 004146ef  8b4618               mov eax, dword ptr [esi + 0x18]
// 004146f2  8b0e                 mov ecx, dword ptr [esi]
// 004146f4  8b10                 mov edx, dword ptr [eax]
// 004146f6  50                   push eax
// 004146f7  51                   push ecx
// 004146f8  52                   push edx
// 004146f9  51                   push ecx
// 004146fa  8d442418             lea eax, [esp + 0x18]
// 004146fe  50                   push eax
// 004146ff  8bce                 mov ecx, esi
// 00414701  c744242c00000000     mov dword ptr [esp + 0x2c], 0
// 00414709  e802feffff           call 0x414510
// 0041470e  8b4e18               mov ecx, dword ptr [esi + 0x18]
// 00414711  51                   push ecx
// 00414712  e863bf2800           call 0x6a067a
// 00414717  8b16                 mov edx, dword ptr [esi]
// 00414719  52                   push edx
// 0041471a  c7461800000000       mov dword ptr [esi + 0x18], 0
// 00414721  c7461c00000000       mov dword ptr [esi + 0x1c], 0
// 00414728  e84dbf2800           call 0x6a067a
// 0041472d  8b4c2418             mov ecx, dword ptr [esp + 0x18]
// 00414731  83c408               add esp, 8
// 00414734  5e                   pop esi
// 00414735  64890d00000000       mov dword ptr fs:[0], ecx
// 0041473c  83c418               add esp, 0x18
// 0041473f  c3                   ret 
// standard library set<ptr> (function ??1?$_Tree@V?$_Tset_traits@PAUT@@U?$less@PAUT@@@std@@V?$allocator@PAUT@@@3@$0A@@std@@@std@@QAE@XZ)

// stl: set<ptr>
struct T; typedef T* E;
#include <set>
template class std::set<E>;
