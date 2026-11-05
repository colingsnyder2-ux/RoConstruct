// from server: 100% by auto
// roc 2010-06 0061c410  unit: RBX::Accoutrement  size: 112 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 0061c410
//
// 0061c410  6aff                 push -1
// 0061c412  68b8d19b00           push 0x9bd1b8
// 0061c417  64a100000000         mov eax, dword ptr fs:[0]
// 0061c41d  50                   push eax
// 0061c41e  64892500000000       mov dword ptr fs:[0], esp
// 0061c425  83ec0c               sub esp, 0xc
// 0061c428  56                   push esi
// 0061c429  8bf1                 mov esi, ecx
// 0061c42b  89742404             mov dword ptr [esp + 4], esi
// 0061c42f  8b4618               mov eax, dword ptr [esi + 0x18]
// 0061c432  8b0e                 mov ecx, dword ptr [esi]
// 0061c434  8b10                 mov edx, dword ptr [eax]
// 0061c436  50                   push eax
// 0061c437  51                   push ecx
// 0061c438  52                   push edx
// 0061c439  51                   push ecx
// 0061c43a  8d442418             lea eax, [esp + 0x18]
// 0061c43e  50                   push eax
// 0061c43f  8bce                 mov ecx, esi
// 0061c441  c744242c00000000     mov dword ptr [esp + 0x2c], 0
// 0061c449  e832fbffff           call 0x61bf80
// 0061c44e  8b4e18               mov ecx, dword ptr [esi + 0x18]
// 0061c451  51                   push ecx
// 0061c452  e843b51800           call 0x7a799a
// 0061c457  8b16                 mov edx, dword ptr [esi]
// 0061c459  52                   push edx
// 0061c45a  c7461800000000       mov dword ptr [esi + 0x18], 0
// 0061c461  c7461c00000000       mov dword ptr [esi + 0x1c], 0
// 0061c468  e82db51800           call 0x7a799a
// 0061c46d  8b4c2418             mov ecx, dword ptr [esp + 0x18]
// 0061c471  83c408               add esp, 8
// 0061c474  5e                   pop esi
// 0061c475  64890d00000000       mov dword ptr fs:[0], ecx
// 0061c47c  83c418               add esp, 0x18
// 0061c47f  c3                   ret 
// standard library set<ptr> (function ??1?$_Tree@V?$_Tset_traits@PAUT@@U?$less@PAUT@@@std@@V?$allocator@PAUT@@@3@$0A@@std@@@std@@QAE@XZ)

// stl: set<ptr>
struct T; typedef T* E;
#include <set>
template class std::set<E>;
