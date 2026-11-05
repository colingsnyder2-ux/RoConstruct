// from server: 100% by auto
// roc 2009-06 004e8f80  unit: RBX::JointsService  size: 112 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 004e8f80
//
// 004e8f80  6aff                 push -1
// 004e8f82  68485e8500           push 0x855e48
// 004e8f87  64a100000000         mov eax, dword ptr fs:[0]
// 004e8f8d  50                   push eax
// 004e8f8e  64892500000000       mov dword ptr fs:[0], esp
// 004e8f95  83ec0c               sub esp, 0xc
// 004e8f98  56                   push esi
// 004e8f99  8bf1                 mov esi, ecx
// 004e8f9b  89742404             mov dword ptr [esp + 4], esi
// 004e8f9f  8b4618               mov eax, dword ptr [esi + 0x18]
// 004e8fa2  8b0e                 mov ecx, dword ptr [esi]
// 004e8fa4  8b10                 mov edx, dword ptr [eax]
// 004e8fa6  50                   push eax
// 004e8fa7  51                   push ecx
// 004e8fa8  52                   push edx
// 004e8fa9  51                   push ecx
// 004e8faa  8d442418             lea eax, [esp + 0x18]
// 004e8fae  50                   push eax
// 004e8faf  8bce                 mov ecx, esi
// 004e8fb1  c744242c00000000     mov dword ptr [esp + 0x2c], 0
// 004e8fb9  e8d2f8ffff           call 0x4e8890
// 004e8fbe  8b4e18               mov ecx, dword ptr [esi + 0x18]
// 004e8fc1  51                   push ecx
// 004e8fc2  e86bfa2200           call 0x718a32
// 004e8fc7  8b16                 mov edx, dword ptr [esi]
// 004e8fc9  52                   push edx
// 004e8fca  c7461800000000       mov dword ptr [esi + 0x18], 0
// 004e8fd1  c7461c00000000       mov dword ptr [esi + 0x1c], 0
// 004e8fd8  e855fa2200           call 0x718a32
// 004e8fdd  8b4c2418             mov ecx, dword ptr [esp + 0x18]
// 004e8fe1  83c408               add esp, 8
// 004e8fe4  5e                   pop esi
// 004e8fe5  64890d00000000       mov dword ptr fs:[0], ecx
// 004e8fec  83c418               add esp, 0x18
// 004e8fef  c3                   ret 
// standard library set<ptr> (function ??1?$_Tree@V?$_Tset_traits@PAUT@@U?$less@PAUT@@@std@@V?$allocator@PAUT@@@3@$0A@@std@@@std@@QAE@XZ)

// stl: set<ptr>
struct T; typedef T* E;
#include <set>
template class std::set<E>;
