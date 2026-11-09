// from server: 100% by auto
// roc 2008-06 0058d450  unit: RBX::ChangeHistoryService  size: 83 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 0058d450
//
// 0058d450  6aff                 push -1
// 0058d452  68496b7c00           push 0x7c6b49
// 0058d457  64a100000000         mov eax, dword ptr fs:[0]
// 0058d45d  50                   push eax
// 0058d45e  64892500000000       mov dword ptr fs:[0], esp
// 0058d465  51                   push ecx
// 0058d466  56                   push esi
// 0058d467  57                   push edi
// 0058d468  8b7c241c             mov edi, dword ptr [esp + 0x1c]
// 0058d46c  8bf1                 mov esi, ecx
// 0058d46e  57                   push edi
// 0058d46f  8974240c             mov dword ptr [esp + 0xc], esi
// 0058d473  ff155c248000         call dword ptr [0x80245c]
// 0058d479  83c71c               add edi, 0x1c
// 0058d47c  57                   push edi
// 0058d47d  8d4e1c               lea ecx, [esi + 0x1c]
// 0058d480  c744241800000000     mov dword ptr [esp + 0x18], 0
// 0058d488  ff155c248000         call dword ptr [0x80245c]
// 0058d48e  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 0058d492  5f                   pop edi
// 0058d493  8bc6                 mov eax, esi
// 0058d495  5e                   pop esi
// 0058d496  64890d00000000       mov dword ptr fs:[0], ecx
// 0058d49d  83c410               add esp, 0x10
// 0058d4a0  c20400               ret 4
// standard library map_str<string> (function ??0?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V12@@std@@QAE@ABU01@@Z)

// stl: map_str<string>
#include <string>
typedef std::string E;
#include <map>
#include <string>
template class std::map<std::string, E>;
