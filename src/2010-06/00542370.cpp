// from server: 100% by auto
// roc 2010-06 00542370  unit: RBX::AggregatingSceneManager  size: 112 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00542370
//
// 00542370  6aff                 push -1
// 00542372  68b8d19b00           push 0x9bd1b8
// 00542377  64a100000000         mov eax, dword ptr fs:[0]
// 0054237d  50                   push eax
// 0054237e  64892500000000       mov dword ptr fs:[0], esp
// 00542385  83ec0c               sub esp, 0xc
// 00542388  56                   push esi
// 00542389  8bf1                 mov esi, ecx
// 0054238b  89742404             mov dword ptr [esp + 4], esi
// 0054238f  8b4618               mov eax, dword ptr [esi + 0x18]
// 00542392  8b0e                 mov ecx, dword ptr [esi]
// 00542394  8b10                 mov edx, dword ptr [eax]
// 00542396  50                   push eax
// 00542397  51                   push ecx
// 00542398  52                   push edx
// 00542399  51                   push ecx
// 0054239a  8d442418             lea eax, [esp + 0x18]
// 0054239e  50                   push eax
// 0054239f  8bce                 mov ecx, esi
// 005423a1  c744242c00000000     mov dword ptr [esp + 0x2c], 0
// 005423a9  e802f7ffff           call 0x541ab0
// 005423ae  8b4e18               mov ecx, dword ptr [esi + 0x18]
// 005423b1  51                   push ecx
// 005423b2  e8e3552600           call 0x7a799a
// 005423b7  8b16                 mov edx, dword ptr [esi]
// 005423b9  52                   push edx
// 005423ba  c7461800000000       mov dword ptr [esi + 0x18], 0
// 005423c1  c7461c00000000       mov dword ptr [esi + 0x1c], 0
// 005423c8  e8cd552600           call 0x7a799a
// 005423cd  8b4c2418             mov ecx, dword ptr [esp + 0x18]
// 005423d1  83c408               add esp, 8
// 005423d4  5e                   pop esi
// 005423d5  64890d00000000       mov dword ptr fs:[0], ecx
// 005423dc  83c418               add esp, 0x18
// 005423df  c3                   ret 
// standard library set<ptr> (function ??1?$_Tree@V?$_Tset_traits@PAUT@@U?$less@PAUT@@@std@@V?$allocator@PAUT@@@3@$0A@@std@@@std@@QAE@XZ)

// stl: set<ptr>
struct T; typedef T* E;
#include <set>
template class std::set<E>;
