// from server: 100% by auto
// roc 2010-06 0089b1e0  unit: CXTPScrollBase  size: 125 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 0089b1e0
//
// 0089b1e0  8b442404             mov eax, dword ptr [esp + 4]
// 0089b1e4  56                   push esi
// 0089b1e5  8bf1                 mov esi, ecx
// 0089b1e7  837e5c00             cmp dword ptr [esi + 0x5c], 0
// 0089b1eb  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 0089b1ef  57                   push edi
// 0089b1f0  8bf9                 mov edi, ecx
// 0089b1f2  7502                 jne 0x89b1f6
// 0089b1f4  8bf8                 mov edi, eax
// 0089b1f6  51                   push ecx
// 0089b1f7  50                   push eax
// 0089b1f8  8d4648               lea eax, [esi + 0x48]
// 0089b1fb  50                   push eax
// 0089b1fc  ff15e0bb9e00         call dword ptr [0x9ebbe0]
// 0089b202  85c0                 test eax, eax
// 0089b204  7505                 jne 0x89b20b
// 0089b206  5f                   pop edi
// 0089b207  5e                   pop esi
// 0089b208  c20800               ret 8
// 0089b20b  3b7e28               cmp edi, dword ptr [esi + 0x28]
// 0089b20e  7d0a                 jge 0x89b21a
// 0089b210  5f                   pop edi
// 0089b211  b83c000000           mov eax, 0x3c
// 0089b216  5e                   pop esi
// 0089b217  c20800               ret 8
// 0089b21a  8b463c               mov eax, dword ptr [esi + 0x3c]
// 0089b21d  85c0                 test eax, eax
// 0089b21f  7e0e                 jle 0x89b22f
// 0089b221  3bf8                 cmp edi, eax
// 0089b223  7e0a                 jle 0x89b22f
// 0089b225  5f                   pop edi
// 0089b226  b841000000           mov eax, 0x41
// 0089b22b  5e                   pop esi
// 0089b22c  c20800               ret 8
// 0089b22f  3b7e2c               cmp edi, dword ptr [esi + 0x2c]
// 0089b232  7c0a                 jl 0x89b23e
// 0089b234  5f                   pop edi
// 0089b235  b83d000000           mov eax, 0x3d
// 0089b23a  5e                   pop esi
// 0089b23b  c20800               ret 8
// 0089b23e  3b7e38               cmp edi, dword ptr [esi + 0x38]
// 0089b241  7d0a                 jge 0x89b24d
// 0089b243  5f                   pop edi
// 0089b244  b83e000000           mov eax, 0x3e
// 0089b249  5e                   pop esi
// 0089b24a  c20800               ret 8
// 0089b24d  33c0                 xor eax, eax
// 0089b24f  3b7e34               cmp edi, dword ptr [esi + 0x34]
// 0089b252  5f                   pop edi
// 0089b253  0f9cc0               setl al
// 0089b256  5e                   pop esi
// 0089b257  83c03f               add eax, 0x3f
// 0089b25a  c20800               ret 8
// library xtp-13.2.1/Source\CommandBars\XTPScrollBase.cpp (function ?HitTestScrollBar@CXTPScrollBase@@QBEHUtagPOINT@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/CommandBars/XTPScrollBase.cpp
