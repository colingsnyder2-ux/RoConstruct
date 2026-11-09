// from server: 100% by auto
// roc 2008-06 004a3470  unit: RBX::Network::Server::ClientProxy  size: 112 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 004a3470
//
// 004a3470  6aff                 push -1
// 004a3472  6828d97b00           push 0x7bd928
// 004a3477  64a100000000         mov eax, dword ptr fs:[0]
// 004a347d  50                   push eax
// 004a347e  64892500000000       mov dword ptr fs:[0], esp
// 004a3485  83ec0c               sub esp, 0xc
// 004a3488  56                   push esi
// 004a3489  8bf1                 mov esi, ecx
// 004a348b  89742404             mov dword ptr [esp + 4], esi
// 004a348f  8b4618               mov eax, dword ptr [esi + 0x18]
// 004a3492  8b0e                 mov ecx, dword ptr [esi]
// 004a3494  8b10                 mov edx, dword ptr [eax]
// 004a3496  50                   push eax
// 004a3497  51                   push ecx
// 004a3498  52                   push edx
// 004a3499  51                   push ecx
// 004a349a  8d442418             lea eax, [esp + 0x18]
// 004a349e  50                   push eax
// 004a349f  8bce                 mov ecx, esi
// 004a34a1  c744242c00000000     mov dword ptr [esp + 0x2c], 0
// 004a34a9  e8e2feffff           call 0x4a3390
// 004a34ae  8b4e18               mov ecx, dword ptr [esi + 0x18]
// 004a34b1  51                   push ecx
// 004a34b2  e8c3d11f00           call 0x6a067a
// 004a34b7  8b16                 mov edx, dword ptr [esi]
// 004a34b9  52                   push edx
// 004a34ba  c7461800000000       mov dword ptr [esi + 0x18], 0
// 004a34c1  c7461c00000000       mov dword ptr [esi + 0x1c], 0
// 004a34c8  e8add11f00           call 0x6a067a
// 004a34cd  8b4c2418             mov ecx, dword ptr [esp + 0x18]
// 004a34d1  83c408               add esp, 8
// 004a34d4  5e                   pop esi
// 004a34d5  64890d00000000       mov dword ptr fs:[0], ecx
// 004a34dc  83c418               add esp, 0x18
// 004a34df  c3                   ret 
// standard library set<ptr> (function ??1?$_Tree@V?$_Tset_traits@PAUT@@U?$less@PAUT@@@std@@V?$allocator@PAUT@@@3@$0A@@std@@@std@@QAE@XZ)

// stl: set<ptr>
struct T; typedef T* E;
#include <set>
template class std::set<E>;
