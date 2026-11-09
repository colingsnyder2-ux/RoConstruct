// from server: 100% by auto
// roc 2008-06 005bae40  unit: RBX::Soundscape::W4ReverbType::?$EnumDesc  size: 112 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 005bae40
//
// 005bae40  6aff                 push -1
// 005bae42  6828d97b00           push 0x7bd928
// 005bae47  64a100000000         mov eax, dword ptr fs:[0]
// 005bae4d  50                   push eax
// 005bae4e  64892500000000       mov dword ptr fs:[0], esp
// 005bae55  83ec0c               sub esp, 0xc
// 005bae58  56                   push esi
// 005bae59  8bf1                 mov esi, ecx
// 005bae5b  89742404             mov dword ptr [esp + 4], esi
// 005bae5f  8b4618               mov eax, dword ptr [esi + 0x18]
// 005bae62  8b0e                 mov ecx, dword ptr [esi]
// 005bae64  8b10                 mov edx, dword ptr [eax]
// 005bae66  50                   push eax
// 005bae67  51                   push ecx
// 005bae68  52                   push edx
// 005bae69  51                   push ecx
// 005bae6a  8d442418             lea eax, [esp + 0x18]
// 005bae6e  50                   push eax
// 005bae6f  8bce                 mov ecx, esi
// 005bae71  c744242c00000000     mov dword ptr [esp + 0x2c], 0
// 005bae79  e812faffff           call 0x5ba890
// 005bae7e  8b4e18               mov ecx, dword ptr [esi + 0x18]
// 005bae81  51                   push ecx
// 005bae82  e8f3570e00           call 0x6a067a
// 005bae87  8b16                 mov edx, dword ptr [esi]
// 005bae89  52                   push edx
// 005bae8a  c7461800000000       mov dword ptr [esi + 0x18], 0
// 005bae91  c7461c00000000       mov dword ptr [esi + 0x1c], 0
// 005bae98  e8dd570e00           call 0x6a067a
// 005bae9d  8b4c2418             mov ecx, dword ptr [esp + 0x18]
// 005baea1  83c408               add esp, 8
// 005baea4  5e                   pop esi
// 005baea5  64890d00000000       mov dword ptr fs:[0], ecx
// 005baeac  83c418               add esp, 0x18
// 005baeaf  c3                   ret 
// standard library set<ptr> (function ??1?$_Tree@V?$_Tset_traits@PAUT@@U?$less@PAUT@@@std@@V?$allocator@PAUT@@@3@$0A@@std@@@std@@QAE@XZ)

// stl: set<ptr>
struct T; typedef T* E;
#include <set>
template class std::set<E>;
