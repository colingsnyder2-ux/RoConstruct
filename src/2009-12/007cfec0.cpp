// from server: 100% by auto
// roc 2009-12 007cfec0  unit: RBX::PartDropTool  size: 93 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 007cfec0
//
// 007cfec0  53                   push ebx
// 007cfec1  55                   push ebp
// 007cfec2  8b6c240c             mov ebp, dword ptr [esp + 0xc]
// 007cfec6  56                   push esi
// 007cfec7  57                   push edi
// 007cfec8  33f6                 xor esi, esi
// 007cfeca  33db                 xor ebx, ebx
// 007cfecc  33ff                 xor edi, edi
// 007cfece  395d00               cmp dword ptr [ebp], ebx
// 007cfed1  8d4e01               lea ecx, [esi + 1]
// 007cfed4  7e3d                 jle 0x7cff13
// 007cfed6  89442414             mov dword ptr [esp + 0x14], eax
// 007cfeda  8d9b00000000         lea ebx, [ebx]
// 007cfee0  8b542414             mov edx, dword ptr [esp + 0x14]
// 007cfee4  8b02                 mov eax, dword ptr [edx]
// 007cfee6  85c0                 test eax, eax
// 007cfee8  7e11                 jle 0x7cfefb
// 007cfeea  03f0                 add esi, eax
// 007cfeec  8bc1                 mov eax, ecx
// 007cfeee  99                   cdq 
// 007cfeef  2bc2                 sub eax, edx
// 007cfef1  d1f8                 sar eax, 1
// 007cfef3  3bf0                 cmp esi, eax
// 007cfef5  7e04                 jle 0x7cfefb
// 007cfef7  8bf9                 mov edi, ecx
// 007cfef9  8bde                 mov ebx, esi
// 007cfefb  3b7500               cmp esi, dword ptr [ebp]
// 007cfefe  7413                 je 0x7cff13
// 007cff00  8344241404           add dword ptr [esp + 0x14], 4
// 007cff05  03c9                 add ecx, ecx
// 007cff07  8bc1                 mov eax, ecx
// 007cff09  99                   cdq 
// 007cff0a  2bc2                 sub eax, edx
// 007cff0c  d1f8                 sar eax, 1
// 007cff0e  3b4500               cmp eax, dword ptr [ebp]
// 007cff11  7ccd                 jl 0x7cfee0
// 007cff13  897d00               mov dword ptr [ebp], edi
// 007cff16  5f                   pop edi
// 007cff17  5e                   pop esi
// 007cff18  5d                   pop ebp
// 007cff19  8bc3                 mov eax, ebx
// 007cff1b  5b                   pop ebx
// 007cff1c  c3                   ret 
// library lua-5.1/ltable.c (function _computesizes)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1 ltable.c
