// from server: 100% by auto
// roc 2010-06 00401810  unit: CAboutRobloxDialog  size: 89 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00401810
//
// 00401810  6aff                 push -1
// 00401812  68198f9a00           push 0x9a8f19
// 00401817  64a100000000         mov eax, dword ptr fs:[0]
// 0040181d  50                   push eax
// 0040181e  64892500000000       mov dword ptr fs:[0], esp
// 00401825  51                   push ecx
// 00401826  56                   push esi
// 00401827  57                   push edi
// 00401828  8b7c241c             mov edi, dword ptr [esp + 0x1c]
// 0040182c  8bf1                 mov esi, ecx
// 0040182e  57                   push edi
// 0040182f  8974240c             mov dword ptr [esp + 0xc], esi
// 00401833  ff1510a99e00         call dword ptr [0x9ea910]
// 00401839  83c70c               add edi, 0xc
// 0040183c  57                   push edi
// 0040183d  8d4e0c               lea ecx, [esi + 0xc]
// 00401840  c744241800000000     mov dword ptr [esp + 0x18], 0
// 00401848  c7062c00a000         mov dword ptr [esi], 0xa0002c
// 0040184e  ff150ca49e00         call dword ptr [0x9ea40c]
// 00401854  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 00401858  5f                   pop edi
// 00401859  8bc6                 mov eax, esi
// 0040185b  5e                   pop esi
// 0040185c  64890d00000000       mov dword ptr fs:[0], ecx
// 00401863  83c410               add esp, 0x10
// 00401866  c20400               ret 4
// standard library vector<ptr> (function ??0logic_error@std@@QAE@ABV01@@Z)

// stl: vector<ptr>
struct T; typedef T* E;
#include <vector>
template class std::vector<E>;
