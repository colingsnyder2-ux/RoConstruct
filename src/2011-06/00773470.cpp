// from server: 100% by auto
// roc 2011-06 00773470  unit: RBX::Lua::VWaitScriptSlot::?$TGenericSlotWrapper  size: 82 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 00773470
//
// 00773470  6aff                 push -1
// 00773472  6829e09e00           push 0x9ee029
// 00773477  64a100000000         mov eax, dword ptr fs:[0]
// 0077347d  50                   push eax
// 0077347e  64892500000000       mov dword ptr fs:[0], esp
// 00773485  51                   push ecx
// 00773486  8b442414             mov eax, dword ptr [esp + 0x14]
// 0077348a  56                   push esi
// 0077348b  8bf1                 mov esi, ecx
// 0077348d  50                   push eax
// 0077348e  89742408             mov dword ptr [esp + 8], esi
// 00773492  ff15c804a400         call dword ptr [0xa404c8]
// 00773498  8b4c241c             mov ecx, dword ptr [esp + 0x1c]
// 0077349c  51                   push ecx
// 0077349d  8d4e1c               lea ecx, [esi + 0x1c]
// 007734a0  c744241400000000     mov dword ptr [esp + 0x14], 0
// 007734a8  ff15c804a400         call dword ptr [0xa404c8]
// 007734ae  8b4c2408             mov ecx, dword ptr [esp + 8]
// 007734b2  8bc6                 mov eax, esi
// 007734b4  5e                   pop esi
// 007734b5  64890d00000000       mov dword ptr fs:[0], ecx
// 007734bc  83c410               add esp, 0x10
// 007734bf  c20800               ret 8
// standard library map_str<string> (function ??0?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V12@@std@@QAE@ABV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@1@0@Z)

// stl: map_str<string>
#include <string>
typedef std::string E;
#include <map>
#include <string>
template class std::map<std::string, E>;
