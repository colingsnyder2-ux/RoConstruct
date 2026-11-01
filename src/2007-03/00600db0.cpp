// from server: 100% by auto
// roc 2007-03 00600db0  unit: seg_00600000  size: 110 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 00600db0
//
// 00600db0  56                   push esi
// 00600db1  8b733c               mov esi, dword ptr [ebx + 0x3c]
// 00600db4  8b4e04               mov ecx, dword ptr [esi + 4]
// 00600db7  8b4608               mov eax, dword ptr [esi + 8]
// 00600dba  83c101               add ecx, 1
// 00600dbd  3bc8                 cmp ecx, eax
// 00600dbf  764b                 jbe 0x600e0c
// 00600dc1  3dfeffff7f           cmp eax, 0x7ffffffe
// 00600dc6  7210                 jb 0x600dd8
// 00600dc8  6a00                 push 0
// 00600dca  68e8097c00           push 0x7c09e8
// 00600dcf  53                   push ebx
// 00600dd0  e8fb000000           call 0x600ed0
// 00600dd5  83c40c               add esp, 0xc
// 00600dd8  8b4608               mov eax, dword ptr [esi + 8]
// 00600ddb  57                   push edi
// 00600ddc  8d3c00               lea edi, [eax + eax]
// 00600ddf  8d5701               lea edx, [edi + 1]
// 00600de2  83fafd               cmp edx, -3
// 00600de5  7713                 ja 0x600dfa
// 00600de7  8b4b34               mov ecx, dword ptr [ebx + 0x34]
// 00600dea  57                   push edi
// 00600deb  50                   push eax
// 00600dec  8b06                 mov eax, dword ptr [esi]
// 00600dee  50                   push eax
// 00600def  51                   push ecx
// 00600df0  e8abc5ffff           call 0x5fd3a0
// 00600df5  83c410               add esp, 0x10
// 00600df8  eb0c                 jmp 0x600e06
// 00600dfa  8b5334               mov edx, dword ptr [ebx + 0x34]
// 00600dfd  52                   push edx
// 00600dfe  e87dc5ffff           call 0x5fd380
// 00600e03  83c404               add esp, 4
// 00600e06  897e08               mov dword ptr [esi + 8], edi
// 00600e09  8906                 mov dword ptr [esi], eax
// 00600e0b  5f                   pop edi
// 00600e0c  8b4604               mov eax, dword ptr [esi + 4]
// 00600e0f  8b0e                 mov ecx, dword ptr [esi]
// 00600e11  8a542408             mov dl, byte ptr [esp + 8]
// 00600e15  881408               mov byte ptr [eax + ecx], dl
// 00600e18  83460401             add dword ptr [esi + 4], 1
// 00600e1c  5e                   pop esi
// 00600e1d  c3                   ret 
// library lua-5.1.1/llex.c (function _save)

// roc-lang: c
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1.1 llex.c
