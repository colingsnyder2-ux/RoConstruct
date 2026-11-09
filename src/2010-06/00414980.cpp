// from server: 100% by auto
// roc 2010-06 00414980  unit: CopyVerb  size: 112 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00414980
//
// 00414980  6aff                 push -1
// 00414982  68b8d19b00           push 0x9bd1b8
// 00414987  64a100000000         mov eax, dword ptr fs:[0]
// 0041498d  50                   push eax
// 0041498e  64892500000000       mov dword ptr fs:[0], esp
// 00414995  83ec0c               sub esp, 0xc
// 00414998  56                   push esi
// 00414999  8bf1                 mov esi, ecx
// 0041499b  89742404             mov dword ptr [esp + 4], esi
// 0041499f  8b4618               mov eax, dword ptr [esi + 0x18]
// 004149a2  8b0e                 mov ecx, dword ptr [esi]
// 004149a4  8b10                 mov edx, dword ptr [eax]
// 004149a6  50                   push eax
// 004149a7  51                   push ecx
// 004149a8  52                   push edx
// 004149a9  51                   push ecx
// 004149aa  8d442418             lea eax, [esp + 0x18]
// 004149ae  50                   push eax
// 004149af  8bce                 mov ecx, esi
// 004149b1  c744242c00000000     mov dword ptr [esp + 0x2c], 0
// 004149b9  e8a2fdffff           call 0x414760
// 004149be  8b4e18               mov ecx, dword ptr [esi + 0x18]
// 004149c1  51                   push ecx
// 004149c2  e8d32f3900           call 0x7a799a
// 004149c7  8b16                 mov edx, dword ptr [esi]
// 004149c9  52                   push edx
// 004149ca  c7461800000000       mov dword ptr [esi + 0x18], 0
// 004149d1  c7461c00000000       mov dword ptr [esi + 0x1c], 0
// 004149d8  e8bd2f3900           call 0x7a799a
// 004149dd  8b4c2418             mov ecx, dword ptr [esp + 0x18]
// 004149e1  83c408               add esp, 8
// 004149e4  5e                   pop esi
// 004149e5  64890d00000000       mov dword ptr fs:[0], ecx
// 004149ec  83c418               add esp, 0x18
// 004149ef  c3                   ret 
// standard library set<ptr> (function ??1?$_Tree@V?$_Tset_traits@PAUT@@U?$less@PAUT@@@std@@V?$allocator@PAUT@@@3@$0A@@std@@@std@@QAE@XZ)

// stl: set<ptr>
struct T; typedef T* E;
#include <set>
template class std::set<E>;
