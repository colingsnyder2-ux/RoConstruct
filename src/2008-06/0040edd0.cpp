// from server: 100% by auto
// roc 2008-06 0040edd0  unit: CBrowserView  size: 154 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 0040edd0
//
// 0040edd0  64a100000000         mov eax, dword ptr fs:[0]
// 0040edd6  8b542404             mov edx, dword ptr [esp + 4]
// 0040edda  6aff                 push -1
// 0040eddc  6842e87d00           push 0x7de842
// 0040ede1  50                   push eax
// 0040ede2  64892500000000       mov dword ptr fs:[0], esp
// 0040ede9  8b4118               mov eax, dword ptr [ecx + 0x18]
// 0040edec  83ec44               sub esp, 0x44
// 0040edef  56                   push esi
// 0040edf0  be49922409           mov esi, 0x9249249
// 0040edf5  2bf0                 sub esi, eax
// 0040edf7  3bf2                 cmp esi, edx
// 0040edf9  5e                   pop esi
// 0040edfa  7358                 jae 0x40ee54
// 0040edfc  6800d48000           push 0x80d400
// 0040ee01  8d4c2404             lea ecx, [esp + 4]
// 0040ee05  ff1558248000         call dword ptr [0x802458]
// 0040ee0b  8d4c241c             lea ecx, [esp + 0x1c]
// 0040ee0f  c744244c00000000     mov dword ptr [esp + 0x4c], 0
// 0040ee17  ff1598288000         call dword ptr [0x802898]
// 0040ee1d  8d0424               lea eax, [esp]
// 0040ee20  50                   push eax
// 0040ee21  8d4c242c             lea ecx, [esp + 0x2c]
// 0040ee25  c644245001           mov byte ptr [esp + 0x50], 1
// 0040ee2a  c744242010b18000     mov dword ptr [esp + 0x20], 0x80b110
// 0040ee32  ff155c248000         call dword ptr [0x80245c]
// 0040ee38  68c00c8d00           push 0x8d0cc0
// 0040ee3d  8d4c2420             lea ecx, [esp + 0x20]
// 0040ee41  51                   push ecx
// 0040ee42  c644245400           mov byte ptr [esp + 0x54], 0
// 0040ee47  c74424241cb18000     mov dword ptr [esp + 0x24], 0x80b11c
// 0040ee4f  e838272900           call 0x6a158c
// 0040ee54  03c2                 add eax, edx
// 0040ee56  894118               mov dword ptr [ecx + 0x18], eax
// 0040ee59  8b4c2444             mov ecx, dword ptr [esp + 0x44]
// 0040ee5d  64890d00000000       mov dword ptr fs:[0], ecx
// 0040ee64  83c450               add esp, 0x50
// 0040ee67  c20400               ret 4
// standard library list<string> (function ?_Incsize@?$list@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V?$allocator@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@@std@@IAEXI@Z)

// stl: list<string>
#include <string>
typedef std::string E;
#include <list>
template class std::list<E>;
