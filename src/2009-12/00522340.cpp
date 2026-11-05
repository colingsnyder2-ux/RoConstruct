// from server: 100% by auto
// roc 2009-12 00522340  unit: RBX::Network::Players  size: 112 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00522340
//
// 00522340  6aff                 push -1
// 00522342  68888f9400           push 0x948f88
// 00522347  64a100000000         mov eax, dword ptr fs:[0]
// 0052234d  50                   push eax
// 0052234e  64892500000000       mov dword ptr fs:[0], esp
// 00522355  83ec0c               sub esp, 0xc
// 00522358  56                   push esi
// 00522359  8bf1                 mov esi, ecx
// 0052235b  89742404             mov dword ptr [esp + 4], esi
// 0052235f  8b4618               mov eax, dword ptr [esi + 0x18]
// 00522362  8b0e                 mov ecx, dword ptr [esi]
// 00522364  8b10                 mov edx, dword ptr [eax]
// 00522366  50                   push eax
// 00522367  51                   push ecx
// 00522368  52                   push edx
// 00522369  51                   push ecx
// 0052236a  8d442418             lea eax, [esp + 0x18]
// 0052236e  50                   push eax
// 0052236f  8bce                 mov ecx, esi
// 00522371  c744242c00000000     mov dword ptr [esp + 0x2c], 0
// 00522379  e8a2f2ffff           call 0x521620
// 0052237e  8b4e18               mov ecx, dword ptr [esi + 0x18]
// 00522381  51                   push ecx
// 00522382  e8d3142d00           call 0x7f385a
// 00522387  8b16                 mov edx, dword ptr [esi]
// 00522389  52                   push edx
// 0052238a  c7461800000000       mov dword ptr [esi + 0x18], 0
// 00522391  c7461c00000000       mov dword ptr [esi + 0x1c], 0
// 00522398  e8bd142d00           call 0x7f385a
// 0052239d  8b4c2418             mov ecx, dword ptr [esp + 0x18]
// 005223a1  83c408               add esp, 8
// 005223a4  5e                   pop esi
// 005223a5  64890d00000000       mov dword ptr fs:[0], ecx
// 005223ac  83c418               add esp, 0x18
// 005223af  c3                   ret 
// standard library set<ptr> (function ??1?$_Tree@V?$_Tset_traits@PAUT@@U?$less@PAUT@@@std@@V?$allocator@PAUT@@@3@$0A@@std@@@std@@QAE@XZ)

// stl: set<ptr>
struct T; typedef T* E;
#include <set>
template class std::set<E>;
