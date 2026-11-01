// from server: 100% by auto
// roc 2007-03 0046a7b0  unit: seg_00460000  size: 87 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 0046a7b0
//
// 0046a7b0  8b4c2404             mov ecx, dword ptr [esp + 4]
// 0046a7b4  83ec0c               sub esp, 0xc
// 0046a7b7  85c9                 test ecx, ecx
// 0046a7b9  7712                 ja 0x46a7cd
// 0046a7bb  33c9                 xor ecx, ecx
// 0046a7bd  c1e106               shl ecx, 6
// 0046a7c0  51                   push ecx
// 0046a7c1  e842391b00           call 0x61e108
// 0046a7c6  83c404               add esp, 4
// 0046a7c9  83c40c               add esp, 0xc
// 0046a7cc  c3                   ret 
// 0046a7cd  83c8ff               or eax, 0xffffffff
// 0046a7d0  33d2                 xor edx, edx
// 0046a7d2  f7f1                 div ecx
// 0046a7d4  83f840               cmp eax, 0x40
// 0046a7d7  73e4                 jae 0x46a7bd
// 0046a7d9  8d442410             lea eax, [esp + 0x10]
// 0046a7dd  50                   push eax
// 0046a7de  8d4c2404             lea ecx, [esp + 4]
// 0046a7e2  c744241400000000     mov dword ptr [esp + 0x14], 0
// 0046a7ea  ff1554e97700         call dword ptr [0x77e954]
// 0046a7f0  68e0f18300           push 0x83f1e0
// 0046a7f5  8d4c2404             lea ecx, [esp + 4]
// 0046a7f9  51                   push ecx
// 0046a7fa  c74424082c3e7800     mov dword ptr [esp + 8], 0x783e2c
// 0046a802  e827481b00           call 0x61f02e
// standard library vector<pod64> (function ??$_Allocate@UE@@@std@@YAPAUE@@IPAU1@@Z)

// stl: vector<pod64>
struct E { int v[16]; };
#include <vector>
template class std::vector<E>;
