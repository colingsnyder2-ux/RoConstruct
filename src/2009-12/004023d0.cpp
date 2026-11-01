// from server: 100% by auto
// roc 2009-12 004023d0  unit: RBX::VTaskSchedulerSettings::?$FactoryProduct::Creator  size: 112 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 004023d0
//
// 004023d0  6aff                 push -1
// 004023d2  68888f9400           push 0x948f88
// 004023d7  64a100000000         mov eax, dword ptr fs:[0]
// 004023dd  50                   push eax
// 004023de  64892500000000       mov dword ptr fs:[0], esp
// 004023e5  83ec0c               sub esp, 0xc
// 004023e8  56                   push esi
// 004023e9  8bf1                 mov esi, ecx
// 004023eb  89742404             mov dword ptr [esp + 4], esi
// 004023ef  8b4618               mov eax, dword ptr [esi + 0x18]
// 004023f2  8b0e                 mov ecx, dword ptr [esi]
// 004023f4  8b10                 mov edx, dword ptr [eax]
// 004023f6  50                   push eax
// 004023f7  51                   push ecx
// 004023f8  52                   push edx
// 004023f9  51                   push ecx
// 004023fa  8d442418             lea eax, [esp + 0x18]
// 004023fe  50                   push eax
// 004023ff  8bce                 mov ecx, esi
// 00402401  c744242c00000000     mov dword ptr [esp + 0x2c], 0
// 00402409  e842220300           call 0x434650
// 0040240e  8b4e18               mov ecx, dword ptr [esi + 0x18]
// 00402411  51                   push ecx
// 00402412  e843143f00           call 0x7f385a
// 00402417  8b16                 mov edx, dword ptr [esi]
// 00402419  52                   push edx
// 0040241a  c7461800000000       mov dword ptr [esi + 0x18], 0
// 00402421  c7461c00000000       mov dword ptr [esi + 0x1c], 0
// 00402428  e82d143f00           call 0x7f385a
// 0040242d  8b4c2418             mov ecx, dword ptr [esp + 0x18]
// 00402431  83c408               add esp, 8
// 00402434  5e                   pop esi
// 00402435  64890d00000000       mov dword ptr fs:[0], ecx
// 0040243c  83c418               add esp, 0x18
// 0040243f  c3                   ret 
// standard library set<ptr> (function ??1?$_Tree@V?$_Tset_traits@PAUT@@U?$less@PAUT@@@std@@V?$allocator@PAUT@@@3@$0A@@std@@@std@@QAE@XZ)

// stl: set<ptr>
struct T; typedef T* E;
#include <set>
template class std::set<E>;
