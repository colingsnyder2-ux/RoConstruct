// from server: 100% by auto
// roc 2008-06 0055d1a0  unit: RBX::MD5HasherImpl  size: 74 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 0055d1a0
//
// 0055d1a0  56                   push esi
// 0055d1a1  8b742408             mov esi, dword ptr [esp + 8]
// 0055d1a5  33c0                 xor eax, eax
// 0055d1a7  57                   push edi
// 0055d1a8  8bf9                 mov edi, ecx
// 0055d1aa  89470c               mov dword ptr [edi + 0xc], eax
// 0055d1ad  894710               mov dword ptr [edi + 0x10], eax
// 0055d1b0  894714               mov dword ptr [edi + 0x14], eax
// 0055d1b3  3bf0                 cmp esi, eax
// 0055d1b5  7507                 jne 0x55d1be
// 0055d1b7  5f                   pop edi
// 0055d1b8  32c0                 xor al, al
// 0055d1ba  5e                   pop esi
// 0055d1bb  c20400               ret 4
// 0055d1be  81feffffff07         cmp esi, 0x7ffffff
// 0055d1c4  7605                 jbe 0x55d1cb
// 0055d1c6  e8759bf6ff           call 0x4c6d40
// 0055d1cb  50                   push eax
// 0055d1cc  56                   push esi
// 0055d1cd  e85ef1ffff           call 0x55c330
// 0055d1d2  c1e605               shl esi, 5
// 0055d1d5  03f0                 add esi, eax
// 0055d1d7  83c408               add esp, 8
// 0055d1da  89470c               mov dword ptr [edi + 0xc], eax
// 0055d1dd  894710               mov dword ptr [edi + 0x10], eax
// 0055d1e0  897714               mov dword ptr [edi + 0x14], esi
// 0055d1e3  5f                   pop edi
// 0055d1e4  b001                 mov al, 1
// 0055d1e6  5e                   pop esi
// 0055d1e7  c20400               ret 4
// standard library vector<pod32> (function ?_Buy@?$vector@UE@@V?$allocator@UE@@@std@@@std@@IAE_NI@Z)

// stl: vector<pod32>
struct E { int v[8]; };
#include <vector>
template class std::vector<E>;
