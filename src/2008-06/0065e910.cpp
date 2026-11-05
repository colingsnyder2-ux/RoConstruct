// from server: 100% by auto
// roc 2008-06 0065e910  unit: seg_00650000  size: 87 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 0065e910
//
// 0065e910  53                   push ebx
// 0065e911  55                   push ebp
// 0065e912  8b6c240c             mov ebp, dword ptr [esp + 0xc]
// 0065e916  56                   push esi
// 0065e917  57                   push edi
// 0065e918  6a20                 push 0x20
// 0065e91a  33db                 xor ebx, ebx
// 0065e91c  53                   push ebx
// 0065e91d  53                   push ebx
// 0065e91e  55                   push ebp
// 0065e91f  e8cc1d0000           call 0x6606f0
// 0065e924  8bf0                 mov esi, eax
// 0065e926  6a05                 push 5
// 0065e928  56                   push esi
// 0065e929  55                   push ebp
// 0065e92a  e8b1dbffff           call 0x65c4e0
// 0065e92f  8b7c2434             mov edi, dword ptr [esp + 0x34]
// 0065e933  8bc5                 mov eax, ebp
// 0065e935  895e08               mov dword ptr [esi + 8], ebx
// 0065e938  c64606ff             mov byte ptr [esi + 6], 0xff
// 0065e93c  895e0c               mov dword ptr [esi + 0xc], ebx
// 0065e93f  895e1c               mov dword ptr [esi + 0x1c], ebx
// 0065e942  885e07               mov byte ptr [esi + 7], bl
// 0065e945  c74610d0c38400       mov dword ptr [esi + 0x10], 0x84c3d0
// 0065e94c  e89ffeffff           call 0x65e7f0
// 0065e951  8b442438             mov eax, dword ptr [esp + 0x38]
// 0065e955  55                   push ebp
// 0065e956  8bfe                 mov edi, esi
// 0065e958  e8f3feffff           call 0x65e850
// 0065e95d  83c420               add esp, 0x20
// 0065e960  5f                   pop edi
// 0065e961  8bc6                 mov eax, esi
// 0065e963  5e                   pop esi
// 0065e964  5d                   pop ebp
// 0065e965  5b                   pop ebx
// 0065e966  c3                   ret 
// library lua-5.1/ltable.c (function _luaH_new)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1 ltable.c
