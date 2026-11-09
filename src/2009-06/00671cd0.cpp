// from server: 100% by auto
// roc 2009-06 00671cd0  unit: RBX::VSpawnLocation::?$BoundPropGetSet  size: 154 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00671cd0
//
// 00671cd0  64a100000000         mov eax, dword ptr fs:[0]
// 00671cd6  8b542404             mov edx, dword ptr [esp + 4]
// 00671cda  6aff                 push -1
// 00671cdc  68b2db8500           push 0x85dbb2
// 00671ce1  50                   push eax
// 00671ce2  64892500000000       mov dword ptr fs:[0], esp
// 00671ce9  8b4118               mov eax, dword ptr [ecx + 0x18]
// 00671cec  83ec44               sub esp, 0x44
// 00671cef  56                   push esi
// 00671cf0  beffffff3f           mov esi, 0x3fffffff
// 00671cf5  2bf0                 sub esi, eax
// 00671cf7  3bf2                 cmp esi, edx
// 00671cf9  5e                   pop esi
// 00671cfa  7358                 jae 0x671d54
// 00671cfc  68d00b8b00           push 0x8b0bd0
// 00671d01  8d4c2404             lea ecx, [esp + 4]
// 00671d05  ff15b4e48900         call dword ptr [0x89e4b4]
// 00671d0b  8d4c241c             lea ecx, [esp + 0x1c]
// 00671d0f  c744244c00000000     mov dword ptr [esp + 0x4c], 0
// 00671d17  ff15b8e98900         call dword ptr [0x89e9b8]
// 00671d1d  8d0424               lea eax, [esp]
// 00671d20  50                   push eax
// 00671d21  8d4c242c             lea ecx, [esp + 0x2c]
// 00671d25  c644245001           mov byte ptr [esp + 0x50], 1
// 00671d2a  c744242044c98a00     mov dword ptr [esp + 0x20], 0x8ac944
// 00671d32  ff15b8e48900         call dword ptr [0x89e4b8]
// 00671d38  6834929700           push 0x979234
// 00671d3d  8d4c2420             lea ecx, [esp + 0x20]
// 00671d41  51                   push ecx
// 00671d42  c644245400           mov byte ptr [esp + 0x54], 0
// 00671d47  c744242450c98a00     mov dword ptr [esp + 0x24], 0x8ac950
// 00671d4f  e8f67c0a00           call 0x719a4a
// 00671d54  03c2                 add eax, edx
// 00671d56  894118               mov dword ptr [ecx + 0x18], eax
// 00671d59  8b4c2444             mov ecx, dword ptr [esp + 0x44]
// 00671d5d  64890d00000000       mov dword ptr fs:[0], ecx
// 00671d64  83c450               add esp, 0x50
// 00671d67  c20400               ret 4
// standard library list<ptr> (function ?_Incsize@?$list@PAUT@@V?$allocator@PAUT@@@std@@@std@@IAEXI@Z)

// stl: list<ptr>
struct T; typedef T* E;
#include <list>
template class std::list<E>;
