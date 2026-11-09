// from server: 100% by auto
// roc 2008-06 004b93d0  unit: RBX::Network::Replicator  size: 112 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 004b93d0
//
// 004b93d0  6aff                 push -1
// 004b93d2  6828d97b00           push 0x7bd928
// 004b93d7  64a100000000         mov eax, dword ptr fs:[0]
// 004b93dd  50                   push eax
// 004b93de  64892500000000       mov dword ptr fs:[0], esp
// 004b93e5  83ec0c               sub esp, 0xc
// 004b93e8  56                   push esi
// 004b93e9  8bf1                 mov esi, ecx
// 004b93eb  89742404             mov dword ptr [esp + 4], esi
// 004b93ef  8b4618               mov eax, dword ptr [esi + 0x18]
// 004b93f2  8b0e                 mov ecx, dword ptr [esi]
// 004b93f4  8b10                 mov edx, dword ptr [eax]
// 004b93f6  50                   push eax
// 004b93f7  51                   push ecx
// 004b93f8  52                   push edx
// 004b93f9  51                   push ecx
// 004b93fa  8d442418             lea eax, [esp + 0x18]
// 004b93fe  50                   push eax
// 004b93ff  8bce                 mov ecx, esi
// 004b9401  c744242c00000000     mov dword ptr [esp + 0x2c], 0
// 004b9409  e872f6ffff           call 0x4b8a80
// 004b940e  8b4e18               mov ecx, dword ptr [esi + 0x18]
// 004b9411  51                   push ecx
// 004b9412  e863721e00           call 0x6a067a
// 004b9417  8b16                 mov edx, dword ptr [esi]
// 004b9419  52                   push edx
// 004b941a  c7461800000000       mov dword ptr [esi + 0x18], 0
// 004b9421  c7461c00000000       mov dword ptr [esi + 0x1c], 0
// 004b9428  e84d721e00           call 0x6a067a
// 004b942d  8b4c2418             mov ecx, dword ptr [esp + 0x18]
// 004b9431  83c408               add esp, 8
// 004b9434  5e                   pop esi
// 004b9435  64890d00000000       mov dword ptr fs:[0], ecx
// 004b943c  83c418               add esp, 0x18
// 004b943f  c3                   ret 
// standard library set<ptr> (function ??1?$_Tree@V?$_Tset_traits@PAUT@@U?$less@PAUT@@@std@@V?$allocator@PAUT@@@3@$0A@@std@@@std@@QAE@XZ)

// stl: set<ptr>
struct T; typedef T* E;
#include <set>
template class std::set<E>;
