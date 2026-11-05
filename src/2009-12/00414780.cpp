// from server: 100% by auto
// roc 2009-12 00414780  unit: CopyVerb  size: 112 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00414780
//
// 00414780  6aff                 push -1
// 00414782  68888f9400           push 0x948f88
// 00414787  64a100000000         mov eax, dword ptr fs:[0]
// 0041478d  50                   push eax
// 0041478e  64892500000000       mov dword ptr fs:[0], esp
// 00414795  83ec0c               sub esp, 0xc
// 00414798  56                   push esi
// 00414799  8bf1                 mov esi, ecx
// 0041479b  89742404             mov dword ptr [esp + 4], esi
// 0041479f  8b4618               mov eax, dword ptr [esi + 0x18]
// 004147a2  8b0e                 mov ecx, dword ptr [esi]
// 004147a4  8b10                 mov edx, dword ptr [eax]
// 004147a6  50                   push eax
// 004147a7  51                   push ecx
// 004147a8  52                   push edx
// 004147a9  51                   push ecx
// 004147aa  8d442418             lea eax, [esp + 0x18]
// 004147ae  50                   push eax
// 004147af  8bce                 mov ecx, esi
// 004147b1  c744242c00000000     mov dword ptr [esp + 0x2c], 0
// 004147b9  e8a2fdffff           call 0x414560
// 004147be  8b4e18               mov ecx, dword ptr [esi + 0x18]
// 004147c1  51                   push ecx
// 004147c2  e893f03d00           call 0x7f385a
// 004147c7  8b16                 mov edx, dword ptr [esi]
// 004147c9  52                   push edx
// 004147ca  c7461800000000       mov dword ptr [esi + 0x18], 0
// 004147d1  c7461c00000000       mov dword ptr [esi + 0x1c], 0
// 004147d8  e87df03d00           call 0x7f385a
// 004147dd  8b4c2418             mov ecx, dword ptr [esp + 0x18]
// 004147e1  83c408               add esp, 8
// 004147e4  5e                   pop esi
// 004147e5  64890d00000000       mov dword ptr fs:[0], ecx
// 004147ec  83c418               add esp, 0x18
// 004147ef  c3                   ret 
// standard library set<ptr> (function ??1?$_Tree@V?$_Tset_traits@PAUT@@U?$less@PAUT@@@std@@V?$allocator@PAUT@@@3@$0A@@std@@@std@@QAE@XZ)

// stl: set<ptr>
struct T; typedef T* E;
#include <set>
template class std::set<E>;
