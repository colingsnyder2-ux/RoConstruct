// from server: 100% by auto
// roc 2010-06 00623f80  unit: RBX::Soundscape::W4ReverbType::?$EnumDesc  size: 112 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00623f80
//
// 00623f80  6aff                 push -1
// 00623f82  68b8d19b00           push 0x9bd1b8
// 00623f87  64a100000000         mov eax, dword ptr fs:[0]
// 00623f8d  50                   push eax
// 00623f8e  64892500000000       mov dword ptr fs:[0], esp
// 00623f95  83ec0c               sub esp, 0xc
// 00623f98  56                   push esi
// 00623f99  8bf1                 mov esi, ecx
// 00623f9b  89742404             mov dword ptr [esp + 4], esi
// 00623f9f  8b4618               mov eax, dword ptr [esi + 0x18]
// 00623fa2  8b0e                 mov ecx, dword ptr [esi]
// 00623fa4  8b10                 mov edx, dword ptr [eax]
// 00623fa6  50                   push eax
// 00623fa7  51                   push ecx
// 00623fa8  52                   push edx
// 00623fa9  51                   push ecx
// 00623faa  8d442418             lea eax, [esp + 0x18]
// 00623fae  50                   push eax
// 00623faf  8bce                 mov ecx, esi
// 00623fb1  c744242c00000000     mov dword ptr [esp + 0x2c], 0
// 00623fb9  e862f8ffff           call 0x623820
// 00623fbe  8b4e18               mov ecx, dword ptr [esi + 0x18]
// 00623fc1  51                   push ecx
// 00623fc2  e8d3391800           call 0x7a799a
// 00623fc7  8b16                 mov edx, dword ptr [esi]
// 00623fc9  52                   push edx
// 00623fca  c7461800000000       mov dword ptr [esi + 0x18], 0
// 00623fd1  c7461c00000000       mov dword ptr [esi + 0x1c], 0
// 00623fd8  e8bd391800           call 0x7a799a
// 00623fdd  8b4c2418             mov ecx, dword ptr [esp + 0x18]
// 00623fe1  83c408               add esp, 8
// 00623fe4  5e                   pop esi
// 00623fe5  64890d00000000       mov dword ptr fs:[0], ecx
// 00623fec  83c418               add esp, 0x18
// 00623fef  c3                   ret 
// standard library set<ptr> (function ??1?$_Tree@V?$_Tset_traits@PAUT@@U?$less@PAUT@@@std@@V?$allocator@PAUT@@@3@$0A@@std@@@std@@QAE@XZ)

// stl: set<ptr>
struct T; typedef T* E;
#include <set>
template class std::set<E>;
