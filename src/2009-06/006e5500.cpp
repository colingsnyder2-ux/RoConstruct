// from server: 100% by auto
// roc 2009-06 006e5500  unit: RBX::ScoreHud  size: 112 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 006e5500
//
// 006e5500  6aff                 push -1
// 006e5502  68485e8500           push 0x855e48
// 006e5507  64a100000000         mov eax, dword ptr fs:[0]
// 006e550d  50                   push eax
// 006e550e  64892500000000       mov dword ptr fs:[0], esp
// 006e5515  83ec0c               sub esp, 0xc
// 006e5518  56                   push esi
// 006e5519  8bf1                 mov esi, ecx
// 006e551b  89742404             mov dword ptr [esp + 4], esi
// 006e551f  8b4618               mov eax, dword ptr [esi + 0x18]
// 006e5522  8b0e                 mov ecx, dword ptr [esi]
// 006e5524  8b10                 mov edx, dword ptr [eax]
// 006e5526  50                   push eax
// 006e5527  51                   push ecx
// 006e5528  52                   push edx
// 006e5529  51                   push ecx
// 006e552a  8d442418             lea eax, [esp + 0x18]
// 006e552e  50                   push eax
// 006e552f  8bce                 mov ecx, esi
// 006e5531  c744242c00000000     mov dword ptr [esp + 0x2c], 0
// 006e5539  e852efffff           call 0x6e4490
// 006e553e  8b4e18               mov ecx, dword ptr [esi + 0x18]
// 006e5541  51                   push ecx
// 006e5542  e8eb340300           call 0x718a32
// 006e5547  8b16                 mov edx, dword ptr [esi]
// 006e5549  52                   push edx
// 006e554a  c7461800000000       mov dword ptr [esi + 0x18], 0
// 006e5551  c7461c00000000       mov dword ptr [esi + 0x1c], 0
// 006e5558  e8d5340300           call 0x718a32
// 006e555d  8b4c2418             mov ecx, dword ptr [esp + 0x18]
// 006e5561  83c408               add esp, 8
// 006e5564  5e                   pop esi
// 006e5565  64890d00000000       mov dword ptr fs:[0], ecx
// 006e556c  83c418               add esp, 0x18
// 006e556f  c3                   ret 
// standard library set<ptr> (function ??1?$_Tree@V?$_Tset_traits@PAUT@@U?$less@PAUT@@@std@@V?$allocator@PAUT@@@3@$0A@@std@@@std@@QAE@XZ)

// stl: set<ptr>
struct T; typedef T* E;
#include <set>
template class std::set<E>;
