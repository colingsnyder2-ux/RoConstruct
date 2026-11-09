// from server: 100% by auto
// roc 2011-06 007d9540  unit: RBX::EquationDisplay  size: 93 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 007d9540
//
// 007d9540  53                   push ebx
// 007d9541  55                   push ebp
// 007d9542  8b6c240c             mov ebp, dword ptr [esp + 0xc]
// 007d9546  56                   push esi
// 007d9547  57                   push edi
// 007d9548  33f6                 xor esi, esi
// 007d954a  33db                 xor ebx, ebx
// 007d954c  33ff                 xor edi, edi
// 007d954e  395d00               cmp dword ptr [ebp], ebx
// 007d9551  8d4e01               lea ecx, [esi + 1]
// 007d9554  7e3d                 jle 0x7d9593
// 007d9556  89442414             mov dword ptr [esp + 0x14], eax
// 007d955a  8d9b00000000         lea ebx, [ebx]
// 007d9560  8b542414             mov edx, dword ptr [esp + 0x14]
// 007d9564  8b02                 mov eax, dword ptr [edx]
// 007d9566  85c0                 test eax, eax
// 007d9568  7e11                 jle 0x7d957b
// 007d956a  03f0                 add esi, eax
// 007d956c  8bc1                 mov eax, ecx
// 007d956e  99                   cdq 
// 007d956f  2bc2                 sub eax, edx
// 007d9571  d1f8                 sar eax, 1
// 007d9573  3bf0                 cmp esi, eax
// 007d9575  7e04                 jle 0x7d957b
// 007d9577  8bf9                 mov edi, ecx
// 007d9579  8bde                 mov ebx, esi
// 007d957b  3b7500               cmp esi, dword ptr [ebp]
// 007d957e  7413                 je 0x7d9593
// 007d9580  8344241404           add dword ptr [esp + 0x14], 4
// 007d9585  03c9                 add ecx, ecx
// 007d9587  8bc1                 mov eax, ecx
// 007d9589  99                   cdq 
// 007d958a  2bc2                 sub eax, edx
// 007d958c  d1f8                 sar eax, 1
// 007d958e  3b4500               cmp eax, dword ptr [ebp]
// 007d9591  7ccd                 jl 0x7d9560
// 007d9593  897d00               mov dword ptr [ebp], edi
// 007d9596  5f                   pop edi
// 007d9597  5e                   pop esi
// 007d9598  5d                   pop ebp
// 007d9599  8bc3                 mov eax, ebx
// 007d959b  5b                   pop ebx
// 007d959c  c3                   ret 
// library lua-5.1/ltable.c (function _computesizes)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1 ltable.c
