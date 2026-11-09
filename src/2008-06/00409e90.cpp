// from server: 100% by auto
// roc 2008-06 00409e90  unit: RBX::GlobalSettings::Item  size: 89 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 00409e90
//
// 00409e90  6aff                 push -1
// 00409e92  6859cd7b00           push 0x7bcd59
// 00409e97  64a100000000         mov eax, dword ptr fs:[0]
// 00409e9d  50                   push eax
// 00409e9e  64892500000000       mov dword ptr fs:[0], esp
// 00409ea5  51                   push ecx
// 00409ea6  56                   push esi
// 00409ea7  57                   push edi
// 00409ea8  8b7c241c             mov edi, dword ptr [esp + 0x1c]
// 00409eac  8bf1                 mov esi, ecx
// 00409eae  57                   push edi
// 00409eaf  8974240c             mov dword ptr [esp + 0xc], esi
// 00409eb3  ff1588288000         call dword ptr [0x802888]
// 00409eb9  83c70c               add edi, 0xc
// 00409ebc  57                   push edi
// 00409ebd  8d4e0c               lea ecx, [esi + 0xc]
// 00409ec0  c744241800000000     mov dword ptr [esp + 0x18], 0
// 00409ec8  c706f8b78000         mov dword ptr [esi], 0x80b7f8
// 00409ece  ff155c248000         call dword ptr [0x80245c]
// 00409ed4  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 00409ed8  5f                   pop edi
// 00409ed9  8bc6                 mov eax, esi
// 00409edb  5e                   pop esi
// 00409edc  64890d00000000       mov dword ptr fs:[0], ecx
// 00409ee3  83c410               add esp, 0x10
// 00409ee6  c20400               ret 4
// standard library vector<ptr> (function ??0logic_error@std@@QAE@ABV01@@Z)

// stl: vector<ptr>
struct T; typedef T* E;
#include <vector>
template class std::vector<E>;
