// from server: 100% by auto
// roc 2008-06 00499270  unit: RBX::Network::VPlayers::?$SignalDesc  size: 112 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 00499270
//
// 00499270  6aff                 push -1
// 00499272  6828d97b00           push 0x7bd928
// 00499277  64a100000000         mov eax, dword ptr fs:[0]
// 0049927d  50                   push eax
// 0049927e  64892500000000       mov dword ptr fs:[0], esp
// 00499285  83ec0c               sub esp, 0xc
// 00499288  56                   push esi
// 00499289  8bf1                 mov esi, ecx
// 0049928b  89742404             mov dword ptr [esp + 4], esi
// 0049928f  8b4618               mov eax, dword ptr [esi + 0x18]
// 00499292  8b0e                 mov ecx, dword ptr [esi]
// 00499294  8b10                 mov edx, dword ptr [eax]
// 00499296  50                   push eax
// 00499297  51                   push ecx
// 00499298  52                   push edx
// 00499299  51                   push ecx
// 0049929a  8d442418             lea eax, [esp + 0x18]
// 0049929e  50                   push eax
// 0049929f  8bce                 mov ecx, esi
// 004992a1  c744242c00000000     mov dword ptr [esp + 0x2c], 0
// 004992a9  e842f1ffff           call 0x4983f0
// 004992ae  8b4e18               mov ecx, dword ptr [esi + 0x18]
// 004992b1  51                   push ecx
// 004992b2  e8c3732000           call 0x6a067a
// 004992b7  8b16                 mov edx, dword ptr [esi]
// 004992b9  52                   push edx
// 004992ba  c7461800000000       mov dword ptr [esi + 0x18], 0
// 004992c1  c7461c00000000       mov dword ptr [esi + 0x1c], 0
// 004992c8  e8ad732000           call 0x6a067a
// 004992cd  8b4c2418             mov ecx, dword ptr [esp + 0x18]
// 004992d1  83c408               add esp, 8
// 004992d4  5e                   pop esi
// 004992d5  64890d00000000       mov dword ptr fs:[0], ecx
// 004992dc  83c418               add esp, 0x18
// 004992df  c3                   ret 
// standard library set<ptr> (function ??1?$_Tree@V?$_Tset_traits@PAUT@@U?$less@PAUT@@@std@@V?$allocator@PAUT@@@3@$0A@@std@@@std@@QAE@XZ)

// stl: set<ptr>
struct T; typedef T* E;
#include <set>
template class std::set<E>;
