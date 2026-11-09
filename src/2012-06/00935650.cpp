// from server: 100% by auto
// roc 2012-06 00935650  unit: RBX::BallCellContact  size: 93 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00935650
//
// 00935650  53                   push ebx
// 00935651  55                   push ebp
// 00935652  8b6c240c             mov ebp, dword ptr [esp + 0xc]
// 00935656  56                   push esi
// 00935657  57                   push edi
// 00935658  33f6                 xor esi, esi
// 0093565a  33db                 xor ebx, ebx
// 0093565c  33ff                 xor edi, edi
// 0093565e  395d00               cmp dword ptr [ebp], ebx
// 00935661  8d4e01               lea ecx, [esi + 1]
// 00935664  7e3d                 jle 0x9356a3
// 00935666  89442414             mov dword ptr [esp + 0x14], eax
// 0093566a  8d9b00000000         lea ebx, [ebx]
// 00935670  8b542414             mov edx, dword ptr [esp + 0x14]
// 00935674  8b02                 mov eax, dword ptr [edx]
// 00935676  85c0                 test eax, eax
// 00935678  7e11                 jle 0x93568b
// 0093567a  03f0                 add esi, eax
// 0093567c  8bc1                 mov eax, ecx
// 0093567e  99                   cdq 
// 0093567f  2bc2                 sub eax, edx
// 00935681  d1f8                 sar eax, 1
// 00935683  3bf0                 cmp esi, eax
// 00935685  7e04                 jle 0x93568b
// 00935687  8bf9                 mov edi, ecx
// 00935689  8bde                 mov ebx, esi
// 0093568b  3b7500               cmp esi, dword ptr [ebp]
// 0093568e  7413                 je 0x9356a3
// 00935690  8344241404           add dword ptr [esp + 0x14], 4
// 00935695  03c9                 add ecx, ecx
// 00935697  8bc1                 mov eax, ecx
// 00935699  99                   cdq 
// 0093569a  2bc2                 sub eax, edx
// 0093569c  d1f8                 sar eax, 1
// 0093569e  3b4500               cmp eax, dword ptr [ebp]
// 009356a1  7ccd                 jl 0x935670
// 009356a3  897d00               mov dword ptr [ebp], edi
// 009356a6  5f                   pop edi
// 009356a7  5e                   pop esi
// 009356a8  5d                   pop ebp
// 009356a9  8bc3                 mov eax, ebx
// 009356ab  5b                   pop ebx
// 009356ac  c3                   ret 
// library lua-5.1/ltable.c (function _computesizes)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1 ltable.c
