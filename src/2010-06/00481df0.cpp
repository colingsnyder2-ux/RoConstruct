// from server: 100% by auto
// roc 2010-06 00481df0  unit: RBX::LDraw2Lua::LDraw2RobloxMapRoot  size: 112 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00481df0
//
// 00481df0  6aff                 push -1
// 00481df2  68e22f9a00           push 0x9a2fe2
// 00481df7  64a100000000         mov eax, dword ptr fs:[0]
// 00481dfd  50                   push eax
// 00481dfe  64892500000000       mov dword ptr fs:[0], esp
// 00481e05  83ec44               sub esp, 0x44
// 00481e08  68782fa100           push 0xa12f78
// 00481e0d  8d4c2404             lea ecx, [esp + 4]
// 00481e11  ff1510a49e00         call dword ptr [0x9ea410]
// 00481e17  8d4c241c             lea ecx, [esp + 0x1c]
// 00481e1b  c744244c00000000     mov dword ptr [esp + 0x4c], 0
// 00481e23  ff1518a99e00         call dword ptr [0x9ea918]
// 00481e29  8d0424               lea eax, [esp]
// 00481e2c  50                   push eax
// 00481e2d  8d4c242c             lea ecx, [esp + 0x2c]
// 00481e31  c644245001           mov byte ptr [esp + 0x50], 1
// 00481e36  c74424202c00a000     mov dword ptr [esp + 0x20], 0xa0002c
// 00481e3e  ff150ca49e00         call dword ptr [0x9ea40c]
// 00481e44  68081bb000           push 0xb01b08
// 00481e49  8d4c2420             lea ecx, [esp + 0x20]
// 00481e4d  51                   push ecx
// 00481e4e  c644245400           mov byte ptr [esp + 0x54], 0
// 00481e53  c74424244400a000     mov dword ptr [esp + 0x24], 0xa00044
// 00481e5b  e8526b3200           call 0x7a89b2
// standard library vector<char> (function ?_Xran@?$vector@DV?$allocator@D@std@@@std@@KAXXZ)

// stl: vector<char>
typedef char E;
#include <vector>
template class std::vector<E>;
