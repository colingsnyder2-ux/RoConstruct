// from server: 100% by auto
// roc 2009-12 006c0a00  unit: RBX::VInstance::?$NonFactoryProduct  size: 112 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 006c0a00
//
// 006c0a00  6aff                 push -1
// 006c0a02  68888f9400           push 0x948f88
// 006c0a07  64a100000000         mov eax, dword ptr fs:[0]
// 006c0a0d  50                   push eax
// 006c0a0e  64892500000000       mov dword ptr fs:[0], esp
// 006c0a15  83ec0c               sub esp, 0xc
// 006c0a18  56                   push esi
// 006c0a19  8bf1                 mov esi, ecx
// 006c0a1b  89742404             mov dword ptr [esp + 4], esi
// 006c0a1f  8b4618               mov eax, dword ptr [esi + 0x18]
// 006c0a22  8b0e                 mov ecx, dword ptr [esi]
// 006c0a24  8b10                 mov edx, dword ptr [eax]
// 006c0a26  50                   push eax
// 006c0a27  51                   push ecx
// 006c0a28  52                   push edx
// 006c0a29  51                   push ecx
// 006c0a2a  8d442418             lea eax, [esp + 0x18]
// 006c0a2e  50                   push eax
// 006c0a2f  8bce                 mov ecx, esi
// 006c0a31  c744242c00000000     mov dword ptr [esp + 0x2c], 0
// 006c0a39  e8b2eeffff           call 0x6bf8f0
// 006c0a3e  8b4e18               mov ecx, dword ptr [esi + 0x18]
// 006c0a41  51                   push ecx
// 006c0a42  e8132e1300           call 0x7f385a
// 006c0a47  8b16                 mov edx, dword ptr [esi]
// 006c0a49  52                   push edx
// 006c0a4a  c7461800000000       mov dword ptr [esi + 0x18], 0
// 006c0a51  c7461c00000000       mov dword ptr [esi + 0x1c], 0
// 006c0a58  e8fd2d1300           call 0x7f385a
// 006c0a5d  8b4c2418             mov ecx, dword ptr [esp + 0x18]
// 006c0a61  83c408               add esp, 8
// 006c0a64  5e                   pop esi
// 006c0a65  64890d00000000       mov dword ptr fs:[0], ecx
// 006c0a6c  83c418               add esp, 0x18
// 006c0a6f  c3                   ret 
// standard library set<ptr> (function ??1?$_Tree@V?$_Tset_traits@PAUT@@U?$less@PAUT@@@std@@V?$allocator@PAUT@@@3@$0A@@std@@@std@@QAE@XZ)

// stl: set<ptr>
struct T; typedef T* E;
#include <set>
template class std::set<E>;
