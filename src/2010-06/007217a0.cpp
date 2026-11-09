// from server: 100% by auto
// roc 2010-06 007217a0  unit: RBX::UniversalTool  size: 91 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 007217a0
//
// 007217a0  8b442408             mov eax, dword ptr [esp + 8]
// 007217a4  83ec10               sub esp, 0x10
// 007217a7  53                   push ebx
// 007217a8  56                   push esi
// 007217a9  8b74241c             mov esi, dword ptr [esp + 0x1c]
// 007217ad  57                   push edi
// 007217ae  8bce                 mov ecx, esi
// 007217b0  e8ebf5ffff           call 0x720da0
// 007217b5  8b542428             mov edx, dword ptr [esp + 0x28]
// 007217b9  8bf8                 mov edi, eax
// 007217bb  8bc2                 mov eax, edx
// 007217bd  8d5801               lea ebx, [eax + 1]
// 007217c0  8a08                 mov cl, byte ptr [eax]
// 007217c2  40                   inc eax
// 007217c3  84c9                 test cl, cl
// 007217c5  75f9                 jne 0x7217c0
// 007217c7  2bc3                 sub eax, ebx
// 007217c9  50                   push eax
// 007217ca  52                   push edx
// 007217cb  56                   push esi
// 007217cc  e80fc60500           call 0x77dde0
// 007217d1  89442418             mov dword ptr [esp + 0x18], eax
// 007217d5  8b4608               mov eax, dword ptr [esi + 8]
// 007217d8  50                   push eax
// 007217d9  8d4c241c             lea ecx, [esp + 0x1c]
// 007217dd  51                   push ecx
// 007217de  57                   push edi
// 007217df  56                   push esi
// 007217e0  c744243004000000     mov dword ptr [esp + 0x30], 4
// 007217e8  e8c39b0500           call 0x77b3b0
// 007217ed  83c41c               add esp, 0x1c
// 007217f0  83460810             add dword ptr [esi + 8], 0x10
// 007217f4  5f                   pop edi
// 007217f5  5e                   pop esi
// 007217f6  5b                   pop ebx
// 007217f7  83c410               add esp, 0x10
// 007217fa  c3                   ret 
// library lua-5.1/lapi.c (function _lua_getfield)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1 lapi.c
