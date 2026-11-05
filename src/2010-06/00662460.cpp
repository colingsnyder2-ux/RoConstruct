// from server: 100% by auto
// roc 2010-06 00662460  unit: G3D::VRay::?$TypedPropertyDescriptor  size: 112 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00662460
//
// 00662460  6aff                 push -1
// 00662462  68b8d19b00           push 0x9bd1b8
// 00662467  64a100000000         mov eax, dword ptr fs:[0]
// 0066246d  50                   push eax
// 0066246e  64892500000000       mov dword ptr fs:[0], esp
// 00662475  83ec0c               sub esp, 0xc
// 00662478  56                   push esi
// 00662479  8bf1                 mov esi, ecx
// 0066247b  89742404             mov dword ptr [esp + 4], esi
// 0066247f  8b4618               mov eax, dword ptr [esi + 0x18]
// 00662482  8b0e                 mov ecx, dword ptr [esi]
// 00662484  8b10                 mov edx, dword ptr [eax]
// 00662486  50                   push eax
// 00662487  51                   push ecx
// 00662488  52                   push edx
// 00662489  51                   push ecx
// 0066248a  8d442418             lea eax, [esp + 0x18]
// 0066248e  50                   push eax
// 0066248f  8bce                 mov ecx, esi
// 00662491  c744242c00000000     mov dword ptr [esp + 0x2c], 0
// 00662499  e832f5ffff           call 0x6619d0
// 0066249e  8b4e18               mov ecx, dword ptr [esi + 0x18]
// 006624a1  51                   push ecx
// 006624a2  e8f3541400           call 0x7a799a
// 006624a7  8b16                 mov edx, dword ptr [esi]
// 006624a9  52                   push edx
// 006624aa  c7461800000000       mov dword ptr [esi + 0x18], 0
// 006624b1  c7461c00000000       mov dword ptr [esi + 0x1c], 0
// 006624b8  e8dd541400           call 0x7a799a
// 006624bd  8b4c2418             mov ecx, dword ptr [esp + 0x18]
// 006624c1  83c408               add esp, 8
// 006624c4  5e                   pop esi
// 006624c5  64890d00000000       mov dword ptr fs:[0], ecx
// 006624cc  83c418               add esp, 0x18
// 006624cf  c3                   ret 
// standard library set<ptr> (function ??1?$_Tree@V?$_Tset_traits@PAUT@@U?$less@PAUT@@@std@@V?$allocator@PAUT@@@3@$0A@@std@@@std@@QAE@XZ)

// stl: set<ptr>
struct T; typedef T* E;
#include <set>
template class std::set<E>;
