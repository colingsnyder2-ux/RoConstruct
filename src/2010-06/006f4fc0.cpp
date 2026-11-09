// from server: 100% by auto
// roc 2010-06 006f4fc0  unit: RBX::VInstance::?$NonFactoryProduct  size: 112 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 006f4fc0
//
// 006f4fc0  6aff                 push -1
// 006f4fc2  68b8d19b00           push 0x9bd1b8
// 006f4fc7  64a100000000         mov eax, dword ptr fs:[0]
// 006f4fcd  50                   push eax
// 006f4fce  64892500000000       mov dword ptr fs:[0], esp
// 006f4fd5  83ec0c               sub esp, 0xc
// 006f4fd8  56                   push esi
// 006f4fd9  8bf1                 mov esi, ecx
// 006f4fdb  89742404             mov dword ptr [esp + 4], esi
// 006f4fdf  8b4618               mov eax, dword ptr [esi + 0x18]
// 006f4fe2  8b0e                 mov ecx, dword ptr [esi]
// 006f4fe4  8b10                 mov edx, dword ptr [eax]
// 006f4fe6  50                   push eax
// 006f4fe7  51                   push ecx
// 006f4fe8  52                   push edx
// 006f4fe9  51                   push ecx
// 006f4fea  8d442418             lea eax, [esp + 0x18]
// 006f4fee  50                   push eax
// 006f4fef  8bce                 mov ecx, esi
// 006f4ff1  c744242c00000000     mov dword ptr [esp + 0x2c], 0
// 006f4ff9  e8b2f8ffff           call 0x6f48b0
// 006f4ffe  8b4e18               mov ecx, dword ptr [esi + 0x18]
// 006f5001  51                   push ecx
// 006f5002  e893290b00           call 0x7a799a
// 006f5007  8b16                 mov edx, dword ptr [esi]
// 006f5009  52                   push edx
// 006f500a  c7461800000000       mov dword ptr [esi + 0x18], 0
// 006f5011  c7461c00000000       mov dword ptr [esi + 0x1c], 0
// 006f5018  e87d290b00           call 0x7a799a
// 006f501d  8b4c2418             mov ecx, dword ptr [esp + 0x18]
// 006f5021  83c408               add esp, 8
// 006f5024  5e                   pop esi
// 006f5025  64890d00000000       mov dword ptr fs:[0], ecx
// 006f502c  83c418               add esp, 0x18
// 006f502f  c3                   ret 
// standard library set<ptr> (function ??1?$_Tree@V?$_Tset_traits@PAUT@@U?$less@PAUT@@@std@@V?$allocator@PAUT@@@3@$0A@@std@@@std@@QAE@XZ)

// stl: set<ptr>
struct T; typedef T* E;
#include <set>
template class std::set<E>;
