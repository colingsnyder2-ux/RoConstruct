// from server: 100% by auto
// roc 2009-12 007d5360  unit: seg_007d0000  size: 70 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 007d5360
//
// 007d5360  8b44240c             mov eax, dword ptr [esp + 0xc]
// 007d5364  8b4c2408             mov ecx, dword ptr [esp + 8]
// 007d5368  53                   push ebx
// 007d5369  8b5c2408             mov ebx, dword ptr [esp + 8]
// 007d536d  56                   push esi
// 007d536e  8b7334               mov esi, dword ptr [ebx + 0x34]
// 007d5371  57                   push edi
// 007d5372  50                   push eax
// 007d5373  51                   push ecx
// 007d5374  56                   push esi
// 007d5375  e816b8ffff           call 0x7d0b90
// 007d537a  8b5330               mov edx, dword ptr [ebx + 0x30]
// 007d537d  8bf8                 mov edi, eax
// 007d537f  8b4204               mov eax, dword ptr [edx + 4]
// 007d5382  57                   push edi
// 007d5383  50                   push eax
// 007d5384  56                   push esi
// 007d5385  e856b6ffff           call 0x7d09e0
// 007d538a  83c418               add esp, 0x18
// 007d538d  83780800             cmp dword ptr [eax + 8], 0
// 007d5391  750d                 jne 0x7d53a0
// 007d5393  c70001000000         mov dword ptr [eax], 1
// 007d5399  c7400801000000       mov dword ptr [eax + 8], 1
// 007d53a0  8bc7                 mov eax, edi
// 007d53a2  5f                   pop edi
// 007d53a3  5e                   pop esi
// 007d53a4  5b                   pop ebx
// 007d53a5  c3                   ret 
// library lua-5.1/llex.c (function _luaX_newstring)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1 llex.c
