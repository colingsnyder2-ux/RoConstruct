// from server: 100% by auto
// roc 2007-08 00612380  unit: seg_00610000  size: 87 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 00612380
//
// 00612380  53                   push ebx
// 00612381  55                   push ebp
// 00612382  8b6c240c             mov ebp, dword ptr [esp + 0xc]
// 00612386  56                   push esi
// 00612387  57                   push edi
// 00612388  6a20                 push 0x20
// 0061238a  33db                 xor ebx, ebx
// 0061238c  53                   push ebx
// 0061238d  53                   push ebx
// 0061238e  55                   push ebp
// 0061238f  e85c160000           call 0x6139f0
// 00612394  8bf0                 mov esi, eax
// 00612396  6a05                 push 5
// 00612398  56                   push esi
// 00612399  55                   push ebp
// 0061239a  e8b1dbffff           call 0x60ff50
// 0061239f  8b7c2434             mov edi, dword ptr [esp + 0x34]
// 006123a3  8bc5                 mov eax, ebp
// 006123a5  895e08               mov dword ptr [esi + 8], ebx
// 006123a8  c64606ff             mov byte ptr [esi + 6], 0xff
// 006123ac  895e0c               mov dword ptr [esi + 0xc], ebx
// 006123af  895e1c               mov dword ptr [esi + 0x1c], ebx
// 006123b2  885e07               mov byte ptr [esi + 7], bl
// 006123b5  c74610b8327c00       mov dword ptr [esi + 0x10], 0x7c32b8
// 006123bc  e89ffeffff           call 0x612260
// 006123c1  8b442438             mov eax, dword ptr [esp + 0x38]
// 006123c5  55                   push ebp
// 006123c6  8bfe                 mov edi, esi
// 006123c8  e8f3feffff           call 0x6122c0
// 006123cd  83c420               add esp, 0x20
// 006123d0  5f                   pop edi
// 006123d1  8bc6                 mov eax, esi
// 006123d3  5e                   pop esi
// 006123d4  5d                   pop ebp
// 006123d5  5b                   pop ebx
// 006123d6  c3                   ret 
// library lua-5.1/ltable.c (function _luaH_new)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1 ltable.c
