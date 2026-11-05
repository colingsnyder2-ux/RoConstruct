// from server: 100% by auto
// roc 2009-12 007d5180  unit: seg_007d0000  size: 107 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 007d5180
//
// 007d5180  56                   push esi
// 007d5181  8b733c               mov esi, dword ptr [ebx + 0x3c]
// 007d5184  8b4e04               mov ecx, dword ptr [esi + 4]
// 007d5187  8b4608               mov eax, dword ptr [esi + 8]
// 007d518a  41                   inc ecx
// 007d518b  3bc8                 cmp ecx, eax
// 007d518d  764b                 jbe 0x7d51da
// 007d518f  3dfeffff7f           cmp eax, 0x7ffffffe
// 007d5194  7210                 jb 0x7d51a6
// 007d5196  6a00                 push 0
// 007d5198  68b8f39e00           push 0x9ef3b8
// 007d519d  53                   push ebx
// 007d519e  e8fd000000           call 0x7d52a0
// 007d51a3  83c40c               add esp, 0xc
// 007d51a6  8b4608               mov eax, dword ptr [esi + 8]
// 007d51a9  57                   push edi
// 007d51aa  8d3c00               lea edi, [eax + eax]
// 007d51ad  8d5701               lea edx, [edi + 1]
// 007d51b0  83fafd               cmp edx, -3
// 007d51b3  7713                 ja 0x7d51c8
// 007d51b5  8b4b34               mov ecx, dword ptr [ebx + 0x34]
// 007d51b8  57                   push edi
// 007d51b9  50                   push eax
// 007d51ba  8b06                 mov eax, dword ptr [esi]
// 007d51bc  50                   push eax
// 007d51bd  51                   push ecx
// 007d51be  e8edc5ffff           call 0x7d17b0
// 007d51c3  83c410               add esp, 0x10
// 007d51c6  eb0c                 jmp 0x7d51d4
// 007d51c8  8b5334               mov edx, dword ptr [ebx + 0x34]
// 007d51cb  52                   push edx
// 007d51cc  e8bfc5ffff           call 0x7d1790
// 007d51d1  83c404               add esp, 4
// 007d51d4  897e08               mov dword ptr [esi + 8], edi
// 007d51d7  8906                 mov dword ptr [esi], eax
// 007d51d9  5f                   pop edi
// 007d51da  8b4604               mov eax, dword ptr [esi + 4]
// 007d51dd  8b0e                 mov ecx, dword ptr [esi]
// 007d51df  8a542408             mov dl, byte ptr [esp + 8]
// 007d51e3  881408               mov byte ptr [eax + ecx], dl
// 007d51e6  ff4604               inc dword ptr [esi + 4]
// 007d51e9  5e                   pop esi
// 007d51ea  c3                   ret 
// library lua-5.1/llex.c (function _save)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1 llex.c
