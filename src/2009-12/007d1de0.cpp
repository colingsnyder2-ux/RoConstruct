// from server: 100% by auto
// roc 2009-12 007d1de0  unit: seg_007d0000  size: 69 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 007d1de0
//
// 007d1de0  57                   push edi
// 007d1de1  8b7e14               mov edi, dword ptr [esi + 0x14]
// 007d1de4  8b07                 mov eax, dword ptr [edi]
// 007d1de6  894614               mov dword ptr [esi + 0x14], eax
// 007d1de9  0fb65708             movzx edx, byte ptr [edi + 8]
// 007d1ded  8b460c               mov eax, dword ptr [esi + 0xc]
// 007d1df0  e8bbfcffff           call 0x7d1ab0
// 007d1df5  807f0900             cmp byte ptr [edi + 9], 0
// 007d1df9  7414                 je 0x7d1e0f
// 007d1dfb  0fb64f08             movzx ecx, byte ptr [edi + 8]
// 007d1dff  6a00                 push 0
// 007d1e01  6a00                 push 0
// 007d1e03  51                   push ecx
// 007d1e04  6a23                 push 0x23
// 007d1e06  56                   push esi
// 007d1e07  e8f4a70000           call 0x7dc600
// 007d1e0c  83c414               add esp, 0x14
// 007d1e0f  0fb65632             movzx edx, byte ptr [esi + 0x32]
// 007d1e13  895624               mov dword ptr [esi + 0x24], edx
// 007d1e16  8b4704               mov eax, dword ptr [edi + 4]
// 007d1e19  50                   push eax
// 007d1e1a  56                   push esi
// 007d1e1b  e840aa0000           call 0x7dc860
// 007d1e20  83c408               add esp, 8
// 007d1e23  5f                   pop edi
// 007d1e24  c3                   ret 
// library lua-5.1/lparser.c (function _leaveblock)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1 lparser.c
