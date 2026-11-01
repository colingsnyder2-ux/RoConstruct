// from server: 100% by auto
// roc 2007-03 005fbd30  unit: seg_005f0000  size: 87 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 005fbd30
//
// 005fbd30  53                   push ebx
// 005fbd31  55                   push ebp
// 005fbd32  8b6c240c             mov ebp, dword ptr [esp + 0xc]
// 005fbd36  56                   push esi
// 005fbd37  57                   push edi
// 005fbd38  6a20                 push 0x20
// 005fbd3a  33db                 xor ebx, ebx
// 005fbd3c  53                   push ebx
// 005fbd3d  53                   push ebx
// 005fbd3e  55                   push ebp
// 005fbd3f  e85c160000           call 0x5fd3a0
// 005fbd44  8bf0                 mov esi, eax
// 005fbd46  6a05                 push 5
// 005fbd48  56                   push esi
// 005fbd49  55                   push ebp
// 005fbd4a  e8b1dbffff           call 0x5f9900
// 005fbd4f  8b7c2434             mov edi, dword ptr [esp + 0x34]
// 005fbd53  8bc5                 mov eax, ebp
// 005fbd55  895e08               mov dword ptr [esi + 8], ebx
// 005fbd58  c64606ff             mov byte ptr [esi + 6], 0xff
// 005fbd5c  895e0c               mov dword ptr [esi + 0xc], ebx
// 005fbd5f  895e1c               mov dword ptr [esi + 0x1c], ebx
// 005fbd62  885e07               mov byte ptr [esi + 7], bl
// 005fbd65  c7461070037c00       mov dword ptr [esi + 0x10], 0x7c0370
// 005fbd6c  e89ffeffff           call 0x5fbc10
// 005fbd71  8b442438             mov eax, dword ptr [esp + 0x38]
// 005fbd75  55                   push ebp
// 005fbd76  8bfe                 mov edi, esi
// 005fbd78  e8f3feffff           call 0x5fbc70
// 005fbd7d  83c420               add esp, 0x20
// 005fbd80  5f                   pop edi
// 005fbd81  8bc6                 mov eax, esi
// 005fbd83  5e                   pop esi
// 005fbd84  5d                   pop ebp
// 005fbd85  5b                   pop ebx
// 005fbd86  c3                   ret 
// library lua-5.1.1/ltable.c (function _luaH_new)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1.1 ltable.c
