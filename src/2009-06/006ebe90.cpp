// from server: 100% by auto
// roc 2009-06 006ebe90  unit: RBX::PartDropTool  size: 93 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 006ebe90
//
// 006ebe90  53                   push ebx
// 006ebe91  55                   push ebp
// 006ebe92  8b6c240c             mov ebp, dword ptr [esp + 0xc]
// 006ebe96  56                   push esi
// 006ebe97  57                   push edi
// 006ebe98  33f6                 xor esi, esi
// 006ebe9a  33db                 xor ebx, ebx
// 006ebe9c  33ff                 xor edi, edi
// 006ebe9e  395d00               cmp dword ptr [ebp], ebx
// 006ebea1  8d4e01               lea ecx, [esi + 1]
// 006ebea4  7e3d                 jle 0x6ebee3
// 006ebea6  89442414             mov dword ptr [esp + 0x14], eax
// 006ebeaa  8d9b00000000         lea ebx, [ebx]
// 006ebeb0  8b542414             mov edx, dword ptr [esp + 0x14]
// 006ebeb4  8b02                 mov eax, dword ptr [edx]
// 006ebeb6  85c0                 test eax, eax
// 006ebeb8  7e11                 jle 0x6ebecb
// 006ebeba  03f0                 add esi, eax
// 006ebebc  8bc1                 mov eax, ecx
// 006ebebe  99                   cdq 
// 006ebebf  2bc2                 sub eax, edx
// 006ebec1  d1f8                 sar eax, 1
// 006ebec3  3bf0                 cmp esi, eax
// 006ebec5  7e04                 jle 0x6ebecb
// 006ebec7  8bf9                 mov edi, ecx
// 006ebec9  8bde                 mov ebx, esi
// 006ebecb  3b7500               cmp esi, dword ptr [ebp]
// 006ebece  7413                 je 0x6ebee3
// 006ebed0  8344241404           add dword ptr [esp + 0x14], 4
// 006ebed5  03c9                 add ecx, ecx
// 006ebed7  8bc1                 mov eax, ecx
// 006ebed9  99                   cdq 
// 006ebeda  2bc2                 sub eax, edx
// 006ebedc  d1f8                 sar eax, 1
// 006ebede  3b4500               cmp eax, dword ptr [ebp]
// 006ebee1  7ccd                 jl 0x6ebeb0
// 006ebee3  897d00               mov dword ptr [ebp], edi
// 006ebee6  5f                   pop edi
// 006ebee7  5e                   pop esi
// 006ebee8  5d                   pop ebp
// 006ebee9  8bc3                 mov eax, ebx
// 006ebeeb  5b                   pop ebx
// 006ebeec  c3                   ret 
// library lua-5.1/ltable.c (function _computesizes)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1 ltable.c
