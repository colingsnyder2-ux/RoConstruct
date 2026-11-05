// from server: 100% by auto
// roc 2008-06 0065e650  unit: seg_00650000  size: 93 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 0065e650
//
// 0065e650  53                   push ebx
// 0065e651  55                   push ebp
// 0065e652  8b6c240c             mov ebp, dword ptr [esp + 0xc]
// 0065e656  56                   push esi
// 0065e657  57                   push edi
// 0065e658  33f6                 xor esi, esi
// 0065e65a  33db                 xor ebx, ebx
// 0065e65c  33ff                 xor edi, edi
// 0065e65e  395d00               cmp dword ptr [ebp], ebx
// 0065e661  8d4e01               lea ecx, [esi + 1]
// 0065e664  7e3d                 jle 0x65e6a3
// 0065e666  89442414             mov dword ptr [esp + 0x14], eax
// 0065e66a  8d9b00000000         lea ebx, [ebx]
// 0065e670  8b542414             mov edx, dword ptr [esp + 0x14]
// 0065e674  8b02                 mov eax, dword ptr [edx]
// 0065e676  85c0                 test eax, eax
// 0065e678  7e11                 jle 0x65e68b
// 0065e67a  03f0                 add esi, eax
// 0065e67c  8bc1                 mov eax, ecx
// 0065e67e  99                   cdq 
// 0065e67f  2bc2                 sub eax, edx
// 0065e681  d1f8                 sar eax, 1
// 0065e683  3bf0                 cmp esi, eax
// 0065e685  7e04                 jle 0x65e68b
// 0065e687  8bf9                 mov edi, ecx
// 0065e689  8bde                 mov ebx, esi
// 0065e68b  3b7500               cmp esi, dword ptr [ebp]
// 0065e68e  7413                 je 0x65e6a3
// 0065e690  8344241404           add dword ptr [esp + 0x14], 4
// 0065e695  03c9                 add ecx, ecx
// 0065e697  8bc1                 mov eax, ecx
// 0065e699  99                   cdq 
// 0065e69a  2bc2                 sub eax, edx
// 0065e69c  d1f8                 sar eax, 1
// 0065e69e  3b4500               cmp eax, dword ptr [ebp]
// 0065e6a1  7ccd                 jl 0x65e670
// 0065e6a3  897d00               mov dword ptr [ebp], edi
// 0065e6a6  5f                   pop edi
// 0065e6a7  5e                   pop esi
// 0065e6a8  5d                   pop ebp
// 0065e6a9  8bc3                 mov eax, ebx
// 0065e6ab  5b                   pop ebx
// 0065e6ac  c3                   ret 
// library lua-5.1/ltable.c (function _computesizes)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1 ltable.c
