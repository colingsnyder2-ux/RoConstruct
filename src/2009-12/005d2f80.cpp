// from server: 100% by auto
// roc 2009-12 005d2f80  unit: RBX::G3DPart  size: 112 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 005d2f80
//
// 005d2f80  6aff                 push -1
// 005d2f82  68888f9400           push 0x948f88
// 005d2f87  64a100000000         mov eax, dword ptr fs:[0]
// 005d2f8d  50                   push eax
// 005d2f8e  64892500000000       mov dword ptr fs:[0], esp
// 005d2f95  83ec0c               sub esp, 0xc
// 005d2f98  56                   push esi
// 005d2f99  8bf1                 mov esi, ecx
// 005d2f9b  89742404             mov dword ptr [esp + 4], esi
// 005d2f9f  8b4618               mov eax, dword ptr [esi + 0x18]
// 005d2fa2  8b0e                 mov ecx, dword ptr [esi]
// 005d2fa4  8b10                 mov edx, dword ptr [eax]
// 005d2fa6  50                   push eax
// 005d2fa7  51                   push ecx
// 005d2fa8  52                   push edx
// 005d2fa9  51                   push ecx
// 005d2faa  8d442418             lea eax, [esp + 0x18]
// 005d2fae  50                   push eax
// 005d2faf  8bce                 mov ecx, esi
// 005d2fb1  c744242c00000000     mov dword ptr [esp + 0x2c], 0
// 005d2fb9  e8f2f1ffff           call 0x5d21b0
// 005d2fbe  8b4e18               mov ecx, dword ptr [esi + 0x18]
// 005d2fc1  51                   push ecx
// 005d2fc2  e893082200           call 0x7f385a
// 005d2fc7  8b16                 mov edx, dword ptr [esi]
// 005d2fc9  52                   push edx
// 005d2fca  c7461800000000       mov dword ptr [esi + 0x18], 0
// 005d2fd1  c7461c00000000       mov dword ptr [esi + 0x1c], 0
// 005d2fd8  e87d082200           call 0x7f385a
// 005d2fdd  8b4c2418             mov ecx, dword ptr [esp + 0x18]
// 005d2fe1  83c408               add esp, 8
// 005d2fe4  5e                   pop esi
// 005d2fe5  64890d00000000       mov dword ptr fs:[0], ecx
// 005d2fec  83c418               add esp, 0x18
// 005d2fef  c3                   ret 
// standard library set<ptr> (function ??1?$_Tree@V?$_Tset_traits@PAUT@@U?$less@PAUT@@@std@@V?$allocator@PAUT@@@3@$0A@@std@@@std@@QAE@XZ)

// stl: set<ptr>
struct T; typedef T* E;
#include <set>
template class std::set<E>;
