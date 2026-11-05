// from server: 100% by auto
// roc 2009-06 00401b80  unit: CAboutRobloxDialog  size: 89 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00401b80
//
// 00401b80  6aff                 push -1
// 00401b82  6809ca8400           push 0x84ca09
// 00401b87  64a100000000         mov eax, dword ptr fs:[0]
// 00401b8d  50                   push eax
// 00401b8e  64892500000000       mov dword ptr fs:[0], esp
// 00401b95  51                   push ecx
// 00401b96  56                   push esi
// 00401b97  57                   push edi
// 00401b98  8b7c241c             mov edi, dword ptr [esp + 0x1c]
// 00401b9c  8bf1                 mov esi, ecx
// 00401b9e  57                   push edi
// 00401b9f  8974240c             mov dword ptr [esp + 0xc], esi
// 00401ba3  ff15b0e98900         call dword ptr [0x89e9b0]
// 00401ba9  83c70c               add edi, 0xc
// 00401bac  57                   push edi
// 00401bad  8d4e0c               lea ecx, [esi + 0xc]
// 00401bb0  c744241800000000     mov dword ptr [esp + 0x18], 0
// 00401bb8  c70644c98a00         mov dword ptr [esi], 0x8ac944
// 00401bbe  ff15b8e48900         call dword ptr [0x89e4b8]
// 00401bc4  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 00401bc8  5f                   pop edi
// 00401bc9  8bc6                 mov eax, esi
// 00401bcb  5e                   pop esi
// 00401bcc  64890d00000000       mov dword ptr fs:[0], ecx
// 00401bd3  83c410               add esp, 0x10
// 00401bd6  c20400               ret 4
// standard library vector<ptr> (function ??0logic_error@std@@QAE@ABV01@@Z)

// stl: vector<ptr>
struct T; typedef T* E;
#include <vector>
template class std::vector<E>;
