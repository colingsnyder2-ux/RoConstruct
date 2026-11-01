// from server: 100% by auto
// roc 2009-12 00789730  unit: RBX::UniversalTool  size: 51 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00789730
//
// 00789730  8b442408             mov eax, dword ptr [esp + 8]
// 00789734  56                   push esi
// 00789735  8b742408             mov esi, dword ptr [esp + 8]
// 00789739  8bce                 mov ecx, esi
// 0078973b  e8b0eeffff           call 0x7885f0
// 00789740  8b4e08               mov ecx, dword ptr [esi + 8]
// 00789743  8b10                 mov edx, dword ptr [eax]
// 00789745  83e910               sub ecx, 0x10
// 00789748  51                   push ecx
// 00789749  52                   push edx
// 0078974a  56                   push esi
// 0078974b  e890660400           call 0x7cfde0
// 00789750  83c40c               add esp, 0xc
// 00789753  85c0                 test eax, eax
// 00789755  7406                 je 0x78975d
// 00789757  83460810             add dword ptr [esi + 8], 0x10
// 0078975b  5e                   pop esi
// 0078975c  c3                   ret 
// 0078975d  834608f0             add dword ptr [esi + 8], -0x10
// 00789761  5e                   pop esi
// 00789762  c3                   ret 
// library lua-5.1/lapi.c (function _lua_next)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1 lapi.c
