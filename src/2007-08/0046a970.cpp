// from server: 100% by auto
// roc 2007-08 0046a970  unit: RBX::LDraw2Lua::LDraw2RobloxMapRoot  size: 91 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 0046a970
//
// 0046a970  83ec08               sub esp, 8
// 0046a973  53                   push ebx
// 0046a974  56                   push esi
// 0046a975  57                   push edi
// 0046a976  8bf9                 mov edi, ecx
// 0046a978  8b7704               mov esi, dword ptr [edi + 4]
// 0046a97b  85f6                 test esi, esi
// 0046a97d  7412                 je 0x46a991
// 0046a97f  8b4f08               mov ecx, dword ptr [edi + 8]
// 0046a982  8b5c2418             mov ebx, dword ptr [esp + 0x18]
// 0046a986  8bc1                 mov eax, ecx
// 0046a988  2bc6                 sub eax, esi
// 0046a98a  c1f806               sar eax, 6
// 0046a98d  3bc3                 cmp eax, ebx
// 0046a98f  7705                 ja 0x46a996
// 0046a991  e82a170000           call 0x46c0c0
// 0046a996  3bf1                 cmp esi, ecx
// 0046a998  55                   push ebp
// 0046a999  8b2dd8e67700         mov ebp, dword ptr [0x77e6d8]
// 0046a99f  7602                 jbe 0x46a9a3
// 0046a9a1  ffd5                 call ebp
// 0046a9a3  c1e306               shl ebx, 6
// 0046a9a6  89742414             mov dword ptr [esp + 0x14], esi
// 0046a9aa  03f3                 add esi, ebx
// 0046a9ac  3b7708               cmp esi, dword ptr [edi + 8]
// 0046a9af  7705                 ja 0x46a9b6
// 0046a9b1  3b7704               cmp esi, dword ptr [edi + 4]
// 0046a9b4  7302                 jae 0x46a9b8
// 0046a9b6  ffd5                 call ebp
// 0046a9b8  3b7708               cmp esi, dword ptr [edi + 8]
// 0046a9bb  7202                 jb 0x46a9bf
// 0046a9bd  ffd5                 call ebp
// 0046a9bf  5d                   pop ebp
// 0046a9c0  5f                   pop edi
// 0046a9c1  8bc6                 mov eax, esi
// 0046a9c3  5e                   pop esi
// 0046a9c4  5b                   pop ebx
// 0046a9c5  83c408               add esp, 8
// 0046a9c8  c20400               ret 4
// standard library vector<pod64> (function ?at@?$vector@UE@@V?$allocator@UE@@@std@@@std@@QBEABUE@@I@Z)

// stl: vector<pod64>
struct E { int v[16]; };
#include <vector>
template class std::vector<E>;
