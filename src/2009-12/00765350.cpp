// from server: 100% by auto
// roc 2009-12 00765350  unit: RBX::VBadgeService::?$BoundYieldFuncDesc  size: 112 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00765350
//
// 00765350  6aff                 push -1
// 00765352  68888f9400           push 0x948f88
// 00765357  64a100000000         mov eax, dword ptr fs:[0]
// 0076535d  50                   push eax
// 0076535e  64892500000000       mov dword ptr fs:[0], esp
// 00765365  83ec0c               sub esp, 0xc
// 00765368  56                   push esi
// 00765369  8bf1                 mov esi, ecx
// 0076536b  89742404             mov dword ptr [esp + 4], esi
// 0076536f  8b4618               mov eax, dword ptr [esi + 0x18]
// 00765372  8b0e                 mov ecx, dword ptr [esi]
// 00765374  8b10                 mov edx, dword ptr [eax]
// 00765376  50                   push eax
// 00765377  51                   push ecx
// 00765378  52                   push edx
// 00765379  51                   push ecx
// 0076537a  8d442418             lea eax, [esp + 0x18]
// 0076537e  50                   push eax
// 0076537f  8bce                 mov ecx, esi
// 00765381  c744242c00000000     mov dword ptr [esp + 0x2c], 0
// 00765389  e842fdffff           call 0x7650d0
// 0076538e  8b4e18               mov ecx, dword ptr [esi + 0x18]
// 00765391  51                   push ecx
// 00765392  e8c3e40800           call 0x7f385a
// 00765397  8b16                 mov edx, dword ptr [esi]
// 00765399  52                   push edx
// 0076539a  c7461800000000       mov dword ptr [esi + 0x18], 0
// 007653a1  c7461c00000000       mov dword ptr [esi + 0x1c], 0
// 007653a8  e8ade40800           call 0x7f385a
// 007653ad  8b4c2418             mov ecx, dword ptr [esp + 0x18]
// 007653b1  83c408               add esp, 8
// 007653b4  5e                   pop esi
// 007653b5  64890d00000000       mov dword ptr fs:[0], ecx
// 007653bc  83c418               add esp, 0x18
// 007653bf  c3                   ret 
// standard library set<ptr> (function ??1?$_Tree@V?$_Tset_traits@PAUT@@U?$less@PAUT@@@std@@V?$allocator@PAUT@@@3@$0A@@std@@@std@@QAE@XZ)

// stl: set<ptr>
struct T; typedef T* E;
#include <set>
template class std::set<E>;
