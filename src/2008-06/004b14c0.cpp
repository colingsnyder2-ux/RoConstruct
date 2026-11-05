// from server: 100% by auto
// roc 2008-06 004b14c0  unit: RBX::Network::Server::ClientProxy  size: 112 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 004b14c0
//
// 004b14c0  6aff                 push -1
// 004b14c2  6828d97b00           push 0x7bd928
// 004b14c7  64a100000000         mov eax, dword ptr fs:[0]
// 004b14cd  50                   push eax
// 004b14ce  64892500000000       mov dword ptr fs:[0], esp
// 004b14d5  83ec0c               sub esp, 0xc
// 004b14d8  56                   push esi
// 004b14d9  8bf1                 mov esi, ecx
// 004b14db  89742404             mov dword ptr [esp + 4], esi
// 004b14df  8b4618               mov eax, dword ptr [esi + 0x18]
// 004b14e2  8b0e                 mov ecx, dword ptr [esi]
// 004b14e4  8b10                 mov edx, dword ptr [eax]
// 004b14e6  50                   push eax
// 004b14e7  51                   push ecx
// 004b14e8  52                   push edx
// 004b14e9  51                   push ecx
// 004b14ea  8d442418             lea eax, [esp + 0x18]
// 004b14ee  50                   push eax
// 004b14ef  8bce                 mov ecx, esi
// 004b14f1  c744242c00000000     mov dword ptr [esp + 0x2c], 0
// 004b14f9  e8a2f7ffff           call 0x4b0ca0
// 004b14fe  8b4e18               mov ecx, dword ptr [esi + 0x18]
// 004b1501  51                   push ecx
// 004b1502  e873f11e00           call 0x6a067a
// 004b1507  8b16                 mov edx, dword ptr [esi]
// 004b1509  52                   push edx
// 004b150a  c7461800000000       mov dword ptr [esi + 0x18], 0
// 004b1511  c7461c00000000       mov dword ptr [esi + 0x1c], 0
// 004b1518  e85df11e00           call 0x6a067a
// 004b151d  8b4c2418             mov ecx, dword ptr [esp + 0x18]
// 004b1521  83c408               add esp, 8
// 004b1524  5e                   pop esi
// 004b1525  64890d00000000       mov dword ptr fs:[0], ecx
// 004b152c  83c418               add esp, 0x18
// 004b152f  c3                   ret 
// standard library set<ptr> (function ??1?$_Tree@V?$_Tset_traits@PAUT@@U?$less@PAUT@@@std@@V?$allocator@PAUT@@@3@$0A@@std@@@std@@QAE@XZ)

// stl: set<ptr>
struct T; typedef T* E;
#include <set>
template class std::set<E>;
