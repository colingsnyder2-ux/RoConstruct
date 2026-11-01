// from server: 100% by auto
// roc 2010-06 00481e70  unit: RBX::LDraw2Lua::LDraw2RobloxMapRoot  size: 87 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00481e70
//
// 00481e70  8b4c2404             mov ecx, dword ptr [esp + 4]
// 00481e74  83ec0c               sub esp, 0xc
// 00481e77  85c9                 test ecx, ecx
// 00481e79  7712                 ja 0x481e8d
// 00481e7b  33c9                 xor ecx, ecx
// 00481e7d  c1e106               shl ecx, 6
// 00481e80  51                   push ecx
// 00481e81  e81a5b3200           call 0x7a79a0
// 00481e86  83c404               add esp, 4
// 00481e89  83c40c               add esp, 0xc
// 00481e8c  c3                   ret 
// 00481e8d  83c8ff               or eax, 0xffffffff
// 00481e90  33d2                 xor edx, edx
// 00481e92  f7f1                 div ecx
// 00481e94  83f840               cmp eax, 0x40
// 00481e97  73e4                 jae 0x481e7d
// 00481e99  8d442410             lea eax, [esp + 0x10]
// 00481e9d  50                   push eax
// 00481e9e  8d4c2404             lea ecx, [esp + 4]
// 00481ea2  c744241400000000     mov dword ptr [esp + 0x14], 0
// 00481eaa  ff1524a99e00         call dword ptr [0x9ea924]
// 00481eb0  68b41ab000           push 0xb01ab4
// 00481eb5  8d4c2404             lea ecx, [esp + 4]
// 00481eb9  51                   push ecx
// 00481eba  c74424082000a000     mov dword ptr [esp + 8], 0xa00020
// 00481ec2  e8eb6a3200           call 0x7a89b2
// standard library vector<pod64> (function ??$_Allocate@UE@@@std@@YAPAUE@@IPAU1@@Z)

// stl: vector<pod64>
struct E { int v[16]; };
#include <vector>
template class std::vector<E>;
