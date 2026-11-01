// from server: 100% by auto
// roc 2009-12 007cd860  unit: RBX::PartDropTool  size: 63 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 007cd860
//
// 007cd860  53                   push ebx
// 007cd861  8b5c2408             mov ebx, dword ptr [esp + 8]
// 007cd865  56                   push esi
// 007cd866  8b7310               mov esi, dword ptr [ebx + 0x10]
// 007cd869  57                   push edi
// 007cd86a  6afd                 push -3
// 007cd86c  8d461c               lea eax, [esi + 0x1c]
// 007cd86f  50                   push eax
// 007cd870  53                   push ebx
// 007cd871  c6461443             mov byte ptr [esi + 0x14], 0x43
// 007cd875  e806feffff           call 0x7cd680
// 007cd87a  33ff                 xor edi, edi
// 007cd87c  83c40c               add esp, 0xc
// 007cd87f  397e08               cmp dword ptr [esi + 8], edi
// 007cd882  7e17                 jle 0x7cd89b
// 007cd884  8b0e                 mov ecx, dword ptr [esi]
// 007cd886  6afd                 push -3
// 007cd888  8d14b9               lea edx, [ecx + edi*4]
// 007cd88b  52                   push edx
// 007cd88c  53                   push ebx
// 007cd88d  e8eefdffff           call 0x7cd680
// 007cd892  47                   inc edi
// 007cd893  83c40c               add esp, 0xc
// 007cd896  3b7e08               cmp edi, dword ptr [esi + 8]
// 007cd899  7ce9                 jl 0x7cd884
// 007cd89b  5f                   pop edi
// 007cd89c  5e                   pop esi
// 007cd89d  5b                   pop ebx
// 007cd89e  c3                   ret 
// library lua-5.1/lgc.c (function _luaC_freeall)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1 lgc.c
