// from server: 100% by auto
// roc 2008-06 00404f30  unit: VCWorkspace::?$CComObject  size: 89 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 00404f30
//
// 00404f30  6aff                 push -1
// 00404f32  6859cd7b00           push 0x7bcd59
// 00404f37  64a100000000         mov eax, dword ptr fs:[0]
// 00404f3d  50                   push eax
// 00404f3e  64892500000000       mov dword ptr fs:[0], esp
// 00404f45  51                   push ecx
// 00404f46  56                   push esi
// 00404f47  57                   push edi
// 00404f48  8b7c241c             mov edi, dword ptr [esp + 0x1c]
// 00404f4c  8bf1                 mov esi, ecx
// 00404f4e  57                   push edi
// 00404f4f  8974240c             mov dword ptr [esp + 0xc], esi
// 00404f53  ff1588288000         call dword ptr [0x802888]
// 00404f59  83c70c               add edi, 0xc
// 00404f5c  57                   push edi
// 00404f5d  8d4e0c               lea ecx, [esi + 0xc]
// 00404f60  c744241800000000     mov dword ptr [esp + 0x18], 0
// 00404f68  c70610b18000         mov dword ptr [esi], 0x80b110
// 00404f6e  ff155c248000         call dword ptr [0x80245c]
// 00404f74  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 00404f78  5f                   pop edi
// 00404f79  8bc6                 mov eax, esi
// 00404f7b  5e                   pop esi
// 00404f7c  64890d00000000       mov dword ptr fs:[0], ecx
// 00404f83  83c410               add esp, 0x10
// 00404f86  c20400               ret 4
// standard library vector<ptr> (function ??0logic_error@std@@QAE@ABV01@@Z)

// stl: vector<ptr>
struct T; typedef T* E;
#include <vector>
template class std::vector<E>;
