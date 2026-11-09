// from server: 100% by auto
// roc 2009-06 006fe8d0  unit: RBX::AdornRbxGfx  size: 112 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 006fe8d0
//
// 006fe8d0  6aff                 push -1
// 006fe8d2  68485e8500           push 0x855e48
// 006fe8d7  64a100000000         mov eax, dword ptr fs:[0]
// 006fe8dd  50                   push eax
// 006fe8de  64892500000000       mov dword ptr fs:[0], esp
// 006fe8e5  83ec0c               sub esp, 0xc
// 006fe8e8  56                   push esi
// 006fe8e9  8bf1                 mov esi, ecx
// 006fe8eb  89742404             mov dword ptr [esp + 4], esi
// 006fe8ef  8b4618               mov eax, dword ptr [esi + 0x18]
// 006fe8f2  8b0e                 mov ecx, dword ptr [esi]
// 006fe8f4  8b10                 mov edx, dword ptr [eax]
// 006fe8f6  50                   push eax
// 006fe8f7  51                   push ecx
// 006fe8f8  52                   push edx
// 006fe8f9  51                   push ecx
// 006fe8fa  8d442418             lea eax, [esp + 0x18]
// 006fe8fe  50                   push eax
// 006fe8ff  8bce                 mov ecx, esi
// 006fe901  c744242c00000000     mov dword ptr [esp + 0x2c], 0
// 006fe909  e8a2f9ffff           call 0x6fe2b0
// 006fe90e  8b4e18               mov ecx, dword ptr [esi + 0x18]
// 006fe911  51                   push ecx
// 006fe912  e81ba10100           call 0x718a32
// 006fe917  8b16                 mov edx, dword ptr [esi]
// 006fe919  52                   push edx
// 006fe91a  c7461800000000       mov dword ptr [esi + 0x18], 0
// 006fe921  c7461c00000000       mov dword ptr [esi + 0x1c], 0
// 006fe928  e805a10100           call 0x718a32
// 006fe92d  8b4c2418             mov ecx, dword ptr [esp + 0x18]
// 006fe931  83c408               add esp, 8
// 006fe934  5e                   pop esi
// 006fe935  64890d00000000       mov dword ptr fs:[0], ecx
// 006fe93c  83c418               add esp, 0x18
// 006fe93f  c3                   ret 
// standard library set<ptr> (function ??1?$_Tree@V?$_Tset_traits@PAUT@@U?$less@PAUT@@@std@@V?$allocator@PAUT@@@3@$0A@@std@@@std@@QAE@XZ)

// stl: set<ptr>
struct T; typedef T* E;
#include <set>
template class std::set<E>;
