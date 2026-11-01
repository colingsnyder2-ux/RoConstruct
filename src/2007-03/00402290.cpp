// from server: 100% by auto
// roc 2007-03 00402290  unit: seg_00400000  size: 233 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 00402290
//
// 00402290  53                   push ebx
// 00402291  8b5c2408             mov ebx, dword ptr [esp + 8]
// 00402295  85db                 test ebx, ebx
// 00402297  56                   push esi
// 00402298  0f84d1000000         je 0x40236f
// 0040229e  8b742410             mov esi, dword ptr [esp + 0x10]
// 004022a2  85f6                 test esi, esi
// 004022a4  0f84c5000000         je 0x40236f
// 004022aa  55                   push ebp
// 004022ab  8b6c241c             mov ebp, dword ptr [esp + 0x1c]
// 004022af  85ed                 test ebp, ebp
// 004022b1  750b                 jne 0x4022be
// 004022b3  5d                   pop ebp
// 004022b4  5e                   pop esi
// 004022b5  b803400080           mov eax, 0x80004003
// 004022ba  5b                   pop ebx
// 004022bb  c21000               ret 0x10
// 004022be  57                   push edi
// 004022bf  8b7c241c             mov edi, dword ptr [esp + 0x1c]
// 004022c3  57                   push edi
// 004022c4  c7450000000000       mov dword ptr [ebp], 0
// 004022cb  e820f9ffff           call 0x401bf0
// 004022d0  85c0                 test eax, eax
// 004022d2  741a                 je 0x4022ee
// 004022d4  8b7604               mov esi, dword ptr [esi + 4]
// 004022d7  8b041e               mov eax, dword ptr [esi + ebx]
// 004022da  8b4804               mov ecx, dword ptr [eax + 4]
// 004022dd  03f3                 add esi, ebx
// 004022df  56                   push esi
// 004022e0  ffd1                 call ecx
// 004022e2  897500               mov dword ptr [ebp], esi
// 004022e5  33c0                 xor eax, eax
// 004022e7  5f                   pop edi
// 004022e8  5d                   pop ebp
// 004022e9  5e                   pop esi
// 004022ea  5b                   pop ebx
// 004022eb  c21000               ret 0x10
// 004022ee  8b4e08               mov ecx, dword ptr [esi + 8]
// 004022f1  85c9                 test ecx, ecx
// 004022f3  7453                 je 0x402348
// 004022f5  8b06                 mov eax, dword ptr [esi]
// 004022f7  33db                 xor ebx, ebx
// 004022f9  85c0                 test eax, eax
// 004022fb  0f94c3               sete bl
// 004022fe  85db                 test ebx, ebx
// 00402300  751e                 jne 0x402320
// 00402302  8b10                 mov edx, dword ptr [eax]
// 00402304  3b17                 cmp edx, dword ptr [edi]
// 00402306  7536                 jne 0x40233e
// 00402308  8b5004               mov edx, dword ptr [eax + 4]
// 0040230b  3b5704               cmp edx, dword ptr [edi + 4]
// 0040230e  752e                 jne 0x40233e
// 00402310  8b5008               mov edx, dword ptr [eax + 8]
// 00402313  3b5708               cmp edx, dword ptr [edi + 8]
// 00402316  7526                 jne 0x40233e
// 00402318  8b400c               mov eax, dword ptr [eax + 0xc]
// 0040231b  3b470c               cmp eax, dword ptr [edi + 0xc]
// 0040231e  751e                 jne 0x40233e
// 00402320  83f901               cmp ecx, 1
// 00402323  742f                 je 0x402354
// 00402325  8b5604               mov edx, dword ptr [esi + 4]
// 00402328  8b442414             mov eax, dword ptr [esp + 0x14]
// 0040232c  52                   push edx
// 0040232d  55                   push ebp
// 0040232e  57                   push edi
// 0040232f  50                   push eax
// 00402330  ffd1                 call ecx
// 00402332  85c0                 test eax, eax
// 00402334  74b1                 je 0x4022e7
// 00402336  85db                 test ebx, ebx
// 00402338  7504                 jne 0x40233e
// 0040233a  85c0                 test eax, eax
// 0040233c  7ca9                 jl 0x4022e7
// 0040233e  8b4e14               mov ecx, dword ptr [esi + 0x14]
// 00402341  83c60c               add esi, 0xc
// 00402344  85c9                 test ecx, ecx
// 00402346  75ad                 jne 0x4022f5
// 00402348  5f                   pop edi
// 00402349  5d                   pop ebp
// 0040234a  5e                   pop esi
// 0040234b  b802400080           mov eax, 0x80004002
// 00402350  5b                   pop ebx
// 00402351  c21000               ret 0x10
// 00402354  8b7604               mov esi, dword ptr [esi + 4]
// 00402357  03742414             add esi, dword ptr [esp + 0x14]
// 0040235b  8b0e                 mov ecx, dword ptr [esi]
// 0040235d  8b5104               mov edx, dword ptr [ecx + 4]
// 00402360  56                   push esi
// 00402361  ffd2                 call edx
// 00402363  5f                   pop edi
// 00402364  897500               mov dword ptr [ebp], esi
// 00402367  5d                   pop ebp
// 00402368  5e                   pop esi
// 00402369  33c0                 xor eax, eax
// 0040236b  5b                   pop ebx
// 0040236c  c21000               ret 0x10
// 0040236f  5e                   pop esi
// 00402370  b857000780           mov eax, 0x80070057
// 00402375  5b                   pop ebx
// 00402376  c21000               ret 0x10
// library atl-8.0/atl.cpp (function _AtlInternalQueryInterface@16)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: atl-8.0 atl.cpp
