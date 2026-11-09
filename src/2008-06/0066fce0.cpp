// from server: 100% by auto
// roc 2008-06 0066fce0  unit: RBX::AdornRbxGfx  size: 83 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 0066fce0
//
// 0066fce0  6aff                 push -1
// 0066fce2  68496b7c00           push 0x7c6b49
// 0066fce7  64a100000000         mov eax, dword ptr fs:[0]
// 0066fced  50                   push eax
// 0066fcee  64892500000000       mov dword ptr fs:[0], esp
// 0066fcf5  51                   push ecx
// 0066fcf6  56                   push esi
// 0066fcf7  57                   push edi
// 0066fcf8  8b7c241c             mov edi, dword ptr [esp + 0x1c]
// 0066fcfc  8bf1                 mov esi, ecx
// 0066fcfe  57                   push edi
// 0066fcff  8974240c             mov dword ptr [esp + 0xc], esi
// 0066fd03  ff155c248000         call dword ptr [0x80245c]
// 0066fd09  83c71c               add edi, 0x1c
// 0066fd0c  57                   push edi
// 0066fd0d  8d4e1c               lea ecx, [esi + 0x1c]
// 0066fd10  c744241800000000     mov dword ptr [esp + 0x18], 0
// 0066fd18  ff15684c8000         call dword ptr [0x804c68]
// 0066fd1e  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 0066fd22  5f                   pop edi
// 0066fd23  8bc6                 mov eax, esi
// 0066fd25  5e                   pop esi
// 0066fd26  64890d00000000       mov dword ptr fs:[0], ecx
// 0066fd2d  83c410               add esp, 0x10
// 0066fd30  c20400               ret 4
// standard library map_str<string> (function ??0?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V12@@std@@QAE@ABU01@@Z)

// stl: map_str<string>
#include <string>
typedef std::string E;
#include <map>
#include <string>
template class std::map<std::string, E>;
