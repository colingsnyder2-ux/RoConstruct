// from server: 100% by auto
// roc 2007-03 004158b0  unit: seg_00410000  size: 130 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 004158b0
//
// 004158b0  57                   push edi
// 004158b1  8b7c2408             mov edi, dword ptr [esp + 8]
// 004158b5  85ff                 test edi, edi
// 004158b7  7506                 jne 0x4158bf
// 004158b9  33c0                 xor eax, eax
// 004158bb  5f                   pop edi
// 004158bc  c20400               ret 4
// 004158bf  53                   push ebx
// 004158c0  55                   push ebp
// 004158c1  56                   push esi
// 004158c2  8d6f04               lea ebp, [edi + 4]
// 004158c5  55                   push ebp
// 004158c6  33db                 xor ebx, ebx
// 004158c8  ff15bcd27700         call dword ptr [0x77d2bc]
// 004158ce  8b771c               mov esi, dword ptr [edi + 0x1c]
// 004158d1  85f6                 test esi, esi
// 004158d3  744d                 je 0x415922
// 004158d5  ff1584d27700         call dword ptr [0x77d284]
// 004158db  33c9                 xor ecx, ecx
// 004158dd  8d4900               lea ecx, [ecx]
// 004158e0  394604               cmp dword ptr [esi + 4], eax
// 004158e3  7419                 je 0x4158fe
// 004158e5  8bce                 mov ecx, esi
// 004158e7  8b7608               mov esi, dword ptr [esi + 8]
// 004158ea  85f6                 test esi, esi
// 004158ec  75f2                 jne 0x4158e0
// 004158ee  55                   push ebp
// 004158ef  ff15b8d27700         call dword ptr [0x77d2b8]
// 004158f5  5e                   pop esi
// 004158f6  5d                   pop ebp
// 004158f7  8bc3                 mov eax, ebx
// 004158f9  5b                   pop ebx
// 004158fa  5f                   pop edi
// 004158fb  c20400               ret 4
// 004158fe  85c9                 test ecx, ecx
// 00415900  7518                 jne 0x41591a
// 00415902  8b4608               mov eax, dword ptr [esi + 8]
// 00415905  89471c               mov dword ptr [edi + 0x1c], eax
// 00415908  8b1e                 mov ebx, dword ptr [esi]
// 0041590a  55                   push ebp
// 0041590b  ff15b8d27700         call dword ptr [0x77d2b8]
// 00415911  5e                   pop esi
// 00415912  5d                   pop ebp
// 00415913  8bc3                 mov eax, ebx
// 00415915  5b                   pop ebx
// 00415916  5f                   pop edi
// 00415917  c20400               ret 4
// 0041591a  8b5608               mov edx, dword ptr [esi + 8]
// 0041591d  895108               mov dword ptr [ecx + 8], edx
// 00415920  8b1e                 mov ebx, dword ptr [esi]
// 00415922  55                   push ebp
// 00415923  ff15b8d27700         call dword ptr [0x77d2b8]
// 00415929  5e                   pop esi
// 0041592a  5d                   pop ebp
// 0041592b  8bc3                 mov eax, ebx
// 0041592d  5b                   pop ebx
// 0041592e  5f                   pop edi
// 0041592f  c20400               ret 4
// library atl-8.0/atl.cpp (function _AtlWinModuleExtractCreateWndData@4)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: atl-8.0 atl.cpp
