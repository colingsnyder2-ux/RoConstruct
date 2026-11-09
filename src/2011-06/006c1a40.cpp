// from server: 100% by auto
// roc 2011-06 006c1a40  unit: RBX::InsertService  size: 78 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 006c1a40
//
// 006c1a40  6aff                 push -1
// 006c1a42  6829e09e00           push 0x9ee029
// 006c1a47  64a100000000         mov eax, dword ptr fs:[0]
// 006c1a4d  50                   push eax
// 006c1a4e  64892500000000       mov dword ptr fs:[0], esp
// 006c1a55  51                   push ecx
// 006c1a56  56                   push esi
// 006c1a57  8bf1                 mov esi, ecx
// 006c1a59  89742404             mov dword ptr [esp + 4], esi
// 006c1a5d  8d4e1c               lea ecx, [esi + 0x1c]
// 006c1a60  c744241000000000     mov dword ptr [esp + 0x10], 0
// 006c1a68  ff15d004a400         call dword ptr [0xa404d0]
// 006c1a6e  8bce                 mov ecx, esi
// 006c1a70  c7442410ffffffff     mov dword ptr [esp + 0x10], 0xffffffff
// 006c1a78  ff15d004a400         call dword ptr [0xa404d0]
// 006c1a7e  8b4c2408             mov ecx, dword ptr [esp + 8]
// 006c1a82  5e                   pop esi
// 006c1a83  64890d00000000       mov dword ptr fs:[0], ecx
// 006c1a8a  83c410               add esp, 0x10
// 006c1a8d  c3                   ret 
// standard library map_str<string> (function ??1?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V12@@std@@QAE@XZ)

// stl: map_str<string>
#include <string>
typedef std::string E;
#include <map>
#include <string>
template class std::map<std::string, E>;
