// from server: 100% by auto
// roc 2009-06 006e6b30  unit: RBX::ScoreHud  size: 112 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 006e6b30
//
// 006e6b30  6aff                 push -1
// 006e6b32  68485e8500           push 0x855e48
// 006e6b37  64a100000000         mov eax, dword ptr fs:[0]
// 006e6b3d  50                   push eax
// 006e6b3e  64892500000000       mov dword ptr fs:[0], esp
// 006e6b45  83ec0c               sub esp, 0xc
// 006e6b48  56                   push esi
// 006e6b49  8bf1                 mov esi, ecx
// 006e6b4b  89742404             mov dword ptr [esp + 4], esi
// 006e6b4f  8b4618               mov eax, dword ptr [esi + 0x18]
// 006e6b52  8b0e                 mov ecx, dword ptr [esi]
// 006e6b54  8b10                 mov edx, dword ptr [eax]
// 006e6b56  50                   push eax
// 006e6b57  51                   push ecx
// 006e6b58  52                   push edx
// 006e6b59  51                   push ecx
// 006e6b5a  8d442418             lea eax, [esp + 0x18]
// 006e6b5e  50                   push eax
// 006e6b5f  8bce                 mov ecx, esi
// 006e6b61  c744242c00000000     mov dword ptr [esp + 0x2c], 0
// 006e6b69  e822ecffff           call 0x6e5790
// 006e6b6e  8b4e18               mov ecx, dword ptr [esi + 0x18]
// 006e6b71  51                   push ecx
// 006e6b72  e8bb1e0300           call 0x718a32
// 006e6b77  8b16                 mov edx, dword ptr [esi]
// 006e6b79  52                   push edx
// 006e6b7a  c7461800000000       mov dword ptr [esi + 0x18], 0
// 006e6b81  c7461c00000000       mov dword ptr [esi + 0x1c], 0
// 006e6b88  e8a51e0300           call 0x718a32
// 006e6b8d  8b4c2418             mov ecx, dword ptr [esp + 0x18]
// 006e6b91  83c408               add esp, 8
// 006e6b94  5e                   pop esi
// 006e6b95  64890d00000000       mov dword ptr fs:[0], ecx
// 006e6b9c  83c418               add esp, 0x18
// 006e6b9f  c3                   ret 
// standard library set<ptr> (function ??1?$_Tree@V?$_Tset_traits@PAUT@@U?$less@PAUT@@@std@@V?$allocator@PAUT@@@3@$0A@@std@@@std@@QAE@XZ)

// stl: set<ptr>
struct T; typedef T* E;
#include <set>
template class std::set<E>;
