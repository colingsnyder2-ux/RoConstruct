// from server: 100% by auto
// roc 2009-12 004c4940  unit: Ogre::RbxCluster  size: 112 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 004c4940
//
// 004c4940  6aff                 push -1
// 004c4942  68888f9400           push 0x948f88
// 004c4947  64a100000000         mov eax, dword ptr fs:[0]
// 004c494d  50                   push eax
// 004c494e  64892500000000       mov dword ptr fs:[0], esp
// 004c4955  83ec0c               sub esp, 0xc
// 004c4958  56                   push esi
// 004c4959  8bf1                 mov esi, ecx
// 004c495b  89742404             mov dword ptr [esp + 4], esi
// 004c495f  8b4618               mov eax, dword ptr [esi + 0x18]
// 004c4962  8b0e                 mov ecx, dword ptr [esi]
// 004c4964  8b10                 mov edx, dword ptr [eax]
// 004c4966  50                   push eax
// 004c4967  51                   push ecx
// 004c4968  52                   push edx
// 004c4969  51                   push ecx
// 004c496a  8d442418             lea eax, [esp + 0x18]
// 004c496e  50                   push eax
// 004c496f  8bce                 mov ecx, esi
// 004c4971  c744242c00000000     mov dword ptr [esp + 0x2c], 0
// 004c4979  e812f9ffff           call 0x4c4290
// 004c497e  8b4e18               mov ecx, dword ptr [esi + 0x18]
// 004c4981  51                   push ecx
// 004c4982  e8d3ee3200           call 0x7f385a
// 004c4987  8b16                 mov edx, dword ptr [esi]
// 004c4989  52                   push edx
// 004c498a  c7461800000000       mov dword ptr [esi + 0x18], 0
// 004c4991  c7461c00000000       mov dword ptr [esi + 0x1c], 0
// 004c4998  e8bdee3200           call 0x7f385a
// 004c499d  8b4c2418             mov ecx, dword ptr [esp + 0x18]
// 004c49a1  83c408               add esp, 8
// 004c49a4  5e                   pop esi
// 004c49a5  64890d00000000       mov dword ptr fs:[0], ecx
// 004c49ac  83c418               add esp, 0x18
// 004c49af  c3                   ret 
// standard library set<ptr> (function ??1?$_Tree@V?$_Tset_traits@PAUT@@U?$less@PAUT@@@std@@V?$allocator@PAUT@@@3@$0A@@std@@@std@@QAE@XZ)

// stl: set<ptr>
struct T; typedef T* E;
#include <set>
template class std::set<E>;
