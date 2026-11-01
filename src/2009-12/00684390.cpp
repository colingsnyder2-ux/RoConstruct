// from server: 100% by auto
// roc 2009-12 00684390  unit: RBX::VChangeHistoryService::?$FactoryProduct  size: 112 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00684390
//
// 00684390  6aff                 push -1
// 00684392  68888f9400           push 0x948f88
// 00684397  64a100000000         mov eax, dword ptr fs:[0]
// 0068439d  50                   push eax
// 0068439e  64892500000000       mov dword ptr fs:[0], esp
// 006843a5  83ec0c               sub esp, 0xc
// 006843a8  56                   push esi
// 006843a9  8bf1                 mov esi, ecx
// 006843ab  89742404             mov dword ptr [esp + 4], esi
// 006843af  8b4618               mov eax, dword ptr [esi + 0x18]
// 006843b2  8b0e                 mov ecx, dword ptr [esi]
// 006843b4  8b10                 mov edx, dword ptr [eax]
// 006843b6  50                   push eax
// 006843b7  51                   push ecx
// 006843b8  52                   push edx
// 006843b9  51                   push ecx
// 006843ba  8d442418             lea eax, [esp + 0x18]
// 006843be  50                   push eax
// 006843bf  8bce                 mov ecx, esi
// 006843c1  c744242c00000000     mov dword ptr [esp + 0x2c], 0
// 006843c9  e8b2fcffff           call 0x684080
// 006843ce  8b4e18               mov ecx, dword ptr [esi + 0x18]
// 006843d1  51                   push ecx
// 006843d2  e883f41600           call 0x7f385a
// 006843d7  8b16                 mov edx, dword ptr [esi]
// 006843d9  52                   push edx
// 006843da  c7461800000000       mov dword ptr [esi + 0x18], 0
// 006843e1  c7461c00000000       mov dword ptr [esi + 0x1c], 0
// 006843e8  e86df41600           call 0x7f385a
// 006843ed  8b4c2418             mov ecx, dword ptr [esp + 0x18]
// 006843f1  83c408               add esp, 8
// 006843f4  5e                   pop esi
// 006843f5  64890d00000000       mov dword ptr fs:[0], ecx
// 006843fc  83c418               add esp, 0x18
// 006843ff  c3                   ret 
// standard library set<ptr> (function ??1?$_Tree@V?$_Tset_traits@PAUT@@U?$less@PAUT@@@std@@V?$allocator@PAUT@@@3@$0A@@std@@@std@@QAE@XZ)

// stl: set<ptr>
struct T; typedef T* E;
#include <set>
template class std::set<E>;
