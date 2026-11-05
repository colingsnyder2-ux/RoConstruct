// from server: 100% by auto
// roc 2010-06 0077dc30  unit: RBX::PartDropTool  size: 67 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 0077dc30
//
// 0077dc30  83ec10               sub esp, 0x10
// 0077dc33  56                   push esi
// 0077dc34  8b742420             mov esi, dword ptr [esp + 0x20]
// 0077dc38  57                   push edi
// 0077dc39  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 0077dc3d  56                   push esi
// 0077dc3e  57                   push edi
// 0077dc3f  e8fcf8ffff           call 0x77d540
// 0077dc44  83c408               add esp, 8
// 0077dc47  3d78dca400           cmp eax, 0xa4dc78
// 0077dc4c  751f                 jne 0x77dc6d
// 0077dc4e  8b4c241c             mov ecx, dword ptr [esp + 0x1c]
// 0077dc52  8d442408             lea eax, [esp + 8]
// 0077dc56  50                   push eax
// 0077dc57  57                   push edi
// 0077dc58  51                   push ecx
// 0077dc59  89742414             mov dword ptr [esp + 0x14], esi
// 0077dc5d  c744241c04000000     mov dword ptr [esp + 0x1c], 4
// 0077dc65  e8d6feffff           call 0x77db40
// 0077dc6a  83c40c               add esp, 0xc
// 0077dc6d  5f                   pop edi
// 0077dc6e  5e                   pop esi
// 0077dc6f  83c410               add esp, 0x10
// 0077dc72  c3                   ret 
// library lua-5.1/ltable.c (function _luaH_setstr)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1 ltable.c
