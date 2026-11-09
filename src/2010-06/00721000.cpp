// from server: 100% by auto
// roc 2010-06 00721000  unit: RBX::UniversalTool  size: 80 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00721000
//
// 00721000  8b442408             mov eax, dword ptr [esp + 8]
// 00721004  56                   push esi
// 00721005  8b742408             mov esi, dword ptr [esp + 8]
// 00721009  8bce                 mov ecx, esi
// 0072100b  e890fdffff           call 0x720da0
// 00721010  8b5608               mov edx, dword ptr [esi + 8]
// 00721013  3bd0                 cmp edx, eax
// 00721015  7624                 jbe 0x72103b
// 00721017  8d4af0               lea ecx, [edx - 0x10]
// 0072101a  57                   push edi
// 0072101b  eb03                 jmp 0x721020
// 0072101d  8d4900               lea ecx, [ecx]
// 00721020  8b39                 mov edi, dword ptr [ecx]
// 00721022  893a                 mov dword ptr [edx], edi
// 00721024  8b7904               mov edi, dword ptr [ecx + 4]
// 00721027  897a04               mov dword ptr [edx + 4], edi
// 0072102a  8b7908               mov edi, dword ptr [ecx + 8]
// 0072102d  897918               mov dword ptr [ecx + 0x18], edi
// 00721030  83ea10               sub edx, 0x10
// 00721033  83e910               sub ecx, 0x10
// 00721036  3bd0                 cmp edx, eax
// 00721038  77e6                 ja 0x721020
// 0072103a  5f                   pop edi
// 0072103b  8b4e08               mov ecx, dword ptr [esi + 8]
// 0072103e  8b11                 mov edx, dword ptr [ecx]
// 00721040  8910                 mov dword ptr [eax], edx
// 00721042  8b5104               mov edx, dword ptr [ecx + 4]
// 00721045  895004               mov dword ptr [eax + 4], edx
// 00721048  8b4908               mov ecx, dword ptr [ecx + 8]
// 0072104b  894808               mov dword ptr [eax + 8], ecx
// 0072104e  5e                   pop esi
// 0072104f  c3                   ret 
// library lua-5.1/lapi.c (function _lua_insert)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1 lapi.c
