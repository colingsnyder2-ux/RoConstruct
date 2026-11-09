// from server: 100% by auto
// roc 2009-06 0070b8e0  unit: RBX::VCEvent::?$sp_counted_impl_p  size: 112 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 0070b8e0
//
// 0070b8e0  6aff                 push -1
// 0070b8e2  68485e8500           push 0x855e48
// 0070b8e7  64a100000000         mov eax, dword ptr fs:[0]
// 0070b8ed  50                   push eax
// 0070b8ee  64892500000000       mov dword ptr fs:[0], esp
// 0070b8f5  83ec0c               sub esp, 0xc
// 0070b8f8  56                   push esi
// 0070b8f9  8bf1                 mov esi, ecx
// 0070b8fb  89742404             mov dword ptr [esp + 4], esi
// 0070b8ff  8b4618               mov eax, dword ptr [esi + 0x18]
// 0070b902  8b0e                 mov ecx, dword ptr [esi]
// 0070b904  8b10                 mov edx, dword ptr [eax]
// 0070b906  50                   push eax
// 0070b907  51                   push ecx
// 0070b908  52                   push edx
// 0070b909  51                   push ecx
// 0070b90a  8d442418             lea eax, [esp + 0x18]
// 0070b90e  50                   push eax
// 0070b90f  8bce                 mov ecx, esi
// 0070b911  c744242c00000000     mov dword ptr [esp + 0x2c], 0
// 0070b919  e8e2feffff           call 0x70b800
// 0070b91e  8b4e18               mov ecx, dword ptr [esi + 0x18]
// 0070b921  51                   push ecx
// 0070b922  e80bd10000           call 0x718a32
// 0070b927  8b16                 mov edx, dword ptr [esi]
// 0070b929  52                   push edx
// 0070b92a  c7461800000000       mov dword ptr [esi + 0x18], 0
// 0070b931  c7461c00000000       mov dword ptr [esi + 0x1c], 0
// 0070b938  e8f5d00000           call 0x718a32
// 0070b93d  8b4c2418             mov ecx, dword ptr [esp + 0x18]
// 0070b941  83c408               add esp, 8
// 0070b944  5e                   pop esi
// 0070b945  64890d00000000       mov dword ptr fs:[0], ecx
// 0070b94c  83c418               add esp, 0x18
// 0070b94f  c3                   ret 
// standard library set<ptr> (function ??1?$_Tree@V?$_Tset_traits@PAUT@@U?$less@PAUT@@@std@@V?$allocator@PAUT@@@3@$0A@@std@@@std@@QAE@XZ)

// stl: set<ptr>
struct T; typedef T* E;
#include <set>
template class std::set<E>;
