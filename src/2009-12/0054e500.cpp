// from server: 100% by auto
// roc 2009-12 0054e500  unit: RBX::Network::Replicator  size: 112 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0054e500
//
// 0054e500  6aff                 push -1
// 0054e502  68888f9400           push 0x948f88
// 0054e507  64a100000000         mov eax, dword ptr fs:[0]
// 0054e50d  50                   push eax
// 0054e50e  64892500000000       mov dword ptr fs:[0], esp
// 0054e515  83ec0c               sub esp, 0xc
// 0054e518  56                   push esi
// 0054e519  8bf1                 mov esi, ecx
// 0054e51b  89742404             mov dword ptr [esp + 4], esi
// 0054e51f  8b4618               mov eax, dword ptr [esi + 0x18]
// 0054e522  8b0e                 mov ecx, dword ptr [esi]
// 0054e524  8b10                 mov edx, dword ptr [eax]
// 0054e526  50                   push eax
// 0054e527  51                   push ecx
// 0054e528  52                   push edx
// 0054e529  51                   push ecx
// 0054e52a  8d442418             lea eax, [esp + 0x18]
// 0054e52e  50                   push eax
// 0054e52f  8bce                 mov ecx, esi
// 0054e531  c744242c00000000     mov dword ptr [esp + 0x2c], 0
// 0054e539  e842f6ffff           call 0x54db80
// 0054e53e  8b4e18               mov ecx, dword ptr [esi + 0x18]
// 0054e541  51                   push ecx
// 0054e542  e813532a00           call 0x7f385a
// 0054e547  8b16                 mov edx, dword ptr [esi]
// 0054e549  52                   push edx
// 0054e54a  c7461800000000       mov dword ptr [esi + 0x18], 0
// 0054e551  c7461c00000000       mov dword ptr [esi + 0x1c], 0
// 0054e558  e8fd522a00           call 0x7f385a
// 0054e55d  8b4c2418             mov ecx, dword ptr [esp + 0x18]
// 0054e561  83c408               add esp, 8
// 0054e564  5e                   pop esi
// 0054e565  64890d00000000       mov dword ptr fs:[0], ecx
// 0054e56c  83c418               add esp, 0x18
// 0054e56f  c3                   ret 
// standard library set<ptr> (function ??1?$_Tree@V?$_Tset_traits@PAUT@@U?$less@PAUT@@@std@@V?$allocator@PAUT@@@3@$0A@@std@@@std@@QAE@XZ)

// stl: set<ptr>
struct T; typedef T* E;
#include <set>
template class std::set<E>;
