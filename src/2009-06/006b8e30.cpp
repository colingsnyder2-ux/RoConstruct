// from server: 100% by auto
// roc 2009-06 006b8e30  unit: RBX::UniversalTool  size: 80 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 006b8e30
//
// 006b8e30  8b442408             mov eax, dword ptr [esp + 8]
// 006b8e34  56                   push esi
// 006b8e35  8b742408             mov esi, dword ptr [esp + 8]
// 006b8e39  8bce                 mov ecx, esi
// 006b8e3b  e890fdffff           call 0x6b8bd0
// 006b8e40  8b5608               mov edx, dword ptr [esi + 8]
// 006b8e43  3bd0                 cmp edx, eax
// 006b8e45  7624                 jbe 0x6b8e6b
// 006b8e47  8d4af0               lea ecx, [edx - 0x10]
// 006b8e4a  57                   push edi
// 006b8e4b  eb03                 jmp 0x6b8e50
// 006b8e4d  8d4900               lea ecx, [ecx]
// 006b8e50  8b39                 mov edi, dword ptr [ecx]
// 006b8e52  893a                 mov dword ptr [edx], edi
// 006b8e54  8b7904               mov edi, dword ptr [ecx + 4]
// 006b8e57  897a04               mov dword ptr [edx + 4], edi
// 006b8e5a  8b7908               mov edi, dword ptr [ecx + 8]
// 006b8e5d  897918               mov dword ptr [ecx + 0x18], edi
// 006b8e60  83ea10               sub edx, 0x10
// 006b8e63  83e910               sub ecx, 0x10
// 006b8e66  3bd0                 cmp edx, eax
// 006b8e68  77e6                 ja 0x6b8e50
// 006b8e6a  5f                   pop edi
// 006b8e6b  8b4e08               mov ecx, dword ptr [esi + 8]
// 006b8e6e  8b11                 mov edx, dword ptr [ecx]
// 006b8e70  8910                 mov dword ptr [eax], edx
// 006b8e72  8b5104               mov edx, dword ptr [ecx + 4]
// 006b8e75  895004               mov dword ptr [eax + 4], edx
// 006b8e78  8b4908               mov ecx, dword ptr [ecx + 8]
// 006b8e7b  894808               mov dword ptr [eax + 8], ecx
// 006b8e7e  5e                   pop esi
// 006b8e7f  c3                   ret 
// library lua-5.1/lapi.c (function _lua_insert)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1 lapi.c
