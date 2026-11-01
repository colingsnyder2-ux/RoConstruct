// from server: 100% by auto
// roc 2009-12 006fa9c0  unit: RBX::Network::VPlayer::?$RemoteEventDesc  size: 112 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 006fa9c0
//
// 006fa9c0  6aff                 push -1
// 006fa9c2  68888f9400           push 0x948f88
// 006fa9c7  64a100000000         mov eax, dword ptr fs:[0]
// 006fa9cd  50                   push eax
// 006fa9ce  64892500000000       mov dword ptr fs:[0], esp
// 006fa9d5  83ec0c               sub esp, 0xc
// 006fa9d8  56                   push esi
// 006fa9d9  8bf1                 mov esi, ecx
// 006fa9db  89742404             mov dword ptr [esp + 4], esi
// 006fa9df  8b4618               mov eax, dword ptr [esi + 0x18]
// 006fa9e2  8b0e                 mov ecx, dword ptr [esi]
// 006fa9e4  8b10                 mov edx, dword ptr [eax]
// 006fa9e6  50                   push eax
// 006fa9e7  51                   push ecx
// 006fa9e8  52                   push edx
// 006fa9e9  51                   push ecx
// 006fa9ea  8d442418             lea eax, [esp + 0x18]
// 006fa9ee  50                   push eax
// 006fa9ef  8bce                 mov ecx, esi
// 006fa9f1  c744242c00000000     mov dword ptr [esp + 0x2c], 0
// 006fa9f9  e8f2f7ffff           call 0x6fa1f0
// 006fa9fe  8b4e18               mov ecx, dword ptr [esi + 0x18]
// 006faa01  51                   push ecx
// 006faa02  e8538e0f00           call 0x7f385a
// 006faa07  8b16                 mov edx, dword ptr [esi]
// 006faa09  52                   push edx
// 006faa0a  c7461800000000       mov dword ptr [esi + 0x18], 0
// 006faa11  c7461c00000000       mov dword ptr [esi + 0x1c], 0
// 006faa18  e83d8e0f00           call 0x7f385a
// 006faa1d  8b4c2418             mov ecx, dword ptr [esp + 0x18]
// 006faa21  83c408               add esp, 8
// 006faa24  5e                   pop esi
// 006faa25  64890d00000000       mov dword ptr fs:[0], ecx
// 006faa2c  83c418               add esp, 0x18
// 006faa2f  c3                   ret 
// standard library set<ptr> (function ??1?$_Tree@V?$_Tset_traits@PAUT@@U?$less@PAUT@@@std@@V?$allocator@PAUT@@@3@$0A@@std@@@std@@QAE@XZ)

// stl: set<ptr>
struct T; typedef T* E;
#include <set>
template class std::set<E>;
