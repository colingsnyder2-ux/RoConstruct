// from server: 100% by auto
// roc 2011-06 00401a10  unit: CAboutRobloxDialog  size: 89 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 00401a10
//
// 00401a10  6aff                 push -1
// 00401a12  6879cf9c00           push 0x9ccf79
// 00401a17  64a100000000         mov eax, dword ptr fs:[0]
// 00401a1d  50                   push eax
// 00401a1e  64892500000000       mov dword ptr fs:[0], esp
// 00401a25  51                   push ecx
// 00401a26  56                   push esi
// 00401a27  57                   push edi
// 00401a28  8b7c241c             mov edi, dword ptr [esp + 0x1c]
// 00401a2c  8bf1                 mov esi, ecx
// 00401a2e  57                   push edi
// 00401a2f  8974240c             mov dword ptr [esp + 0xc], esi
// 00401a33  ff15580aa400         call dword ptr [0xa40a58]
// 00401a39  83c70c               add edi, 0xc
// 00401a3c  57                   push edi
// 00401a3d  8d4e0c               lea ecx, [esi + 0xc]
// 00401a40  c744241800000000     mov dword ptr [esp + 0x18], 0
// 00401a48  c706c0b5a500         mov dword ptr [esi], 0xa5b5c0
// 00401a4e  ff15c804a400         call dword ptr [0xa404c8]
// 00401a54  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 00401a58  5f                   pop edi
// 00401a59  8bc6                 mov eax, esi
// 00401a5b  5e                   pop esi
// 00401a5c  64890d00000000       mov dword ptr fs:[0], ecx
// 00401a63  83c410               add esp, 0x10
// 00401a66  c20400               ret 4
// standard library vector<ptr> (function ??0logic_error@std@@QAE@ABV01@@Z)

// stl: vector<ptr>
struct T; typedef T* E;
#include <vector>
template class std::vector<E>;
