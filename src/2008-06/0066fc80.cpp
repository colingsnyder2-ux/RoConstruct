// from server: 100% by auto
// roc 2008-06 0066fc80  unit: RBX::AdornRbxGfx  size: 82 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 0066fc80
//
// 0066fc80  6aff                 push -1
// 0066fc82  68496b7c00           push 0x7c6b49
// 0066fc87  64a100000000         mov eax, dword ptr fs:[0]
// 0066fc8d  50                   push eax
// 0066fc8e  64892500000000       mov dword ptr fs:[0], esp
// 0066fc95  51                   push ecx
// 0066fc96  8b442414             mov eax, dword ptr [esp + 0x14]
// 0066fc9a  56                   push esi
// 0066fc9b  8bf1                 mov esi, ecx
// 0066fc9d  50                   push eax
// 0066fc9e  89742408             mov dword ptr [esp + 8], esi
// 0066fca2  ff155c248000         call dword ptr [0x80245c]
// 0066fca8  8b4c241c             mov ecx, dword ptr [esp + 0x1c]
// 0066fcac  51                   push ecx
// 0066fcad  8d4e1c               lea ecx, [esi + 0x1c]
// 0066fcb0  c744241400000000     mov dword ptr [esp + 0x14], 0
// 0066fcb8  ff15684c8000         call dword ptr [0x804c68]
// 0066fcbe  8b4c2408             mov ecx, dword ptr [esp + 8]
// 0066fcc2  8bc6                 mov eax, esi
// 0066fcc4  5e                   pop esi
// 0066fcc5  64890d00000000       mov dword ptr fs:[0], ecx
// 0066fccc  83c410               add esp, 0x10
// 0066fccf  c20800               ret 8
// standard library map_str<string> (function ??0?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V12@@std@@QAE@ABV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@1@0@Z)

// stl: map_str<string>
#include <string>
typedef std::string E;
#include <map>
#include <string>
template class std::map<std::string, E>;
