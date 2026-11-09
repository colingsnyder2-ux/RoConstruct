// from server: 100% by auto
// roc 2008-06 00402280  unit: VCWorkspace::?$CComObject  size: 233 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 00402280
//
// 00402280  53                   push ebx
// 00402281  8b5c2408             mov ebx, dword ptr [esp + 8]
// 00402285  56                   push esi
// 00402286  85db                 test ebx, ebx
// 00402288  0f84d1000000         je 0x40235f
// 0040228e  8b742410             mov esi, dword ptr [esp + 0x10]
// 00402292  85f6                 test esi, esi
// 00402294  0f84c5000000         je 0x40235f
// 0040229a  55                   push ebp
// 0040229b  8b6c241c             mov ebp, dword ptr [esp + 0x1c]
// 0040229f  85ed                 test ebp, ebp
// 004022a1  750b                 jne 0x4022ae
// 004022a3  5d                   pop ebp
// 004022a4  5e                   pop esi
// 004022a5  b803400080           mov eax, 0x80004003
// 004022aa  5b                   pop ebx
// 004022ab  c21000               ret 0x10
// 004022ae  57                   push edi
// 004022af  8b7c241c             mov edi, dword ptr [esp + 0x1c]
// 004022b3  57                   push edi
// 004022b4  c7450000000000       mov dword ptr [ebp], 0
// 004022bb  e8a0f8ffff           call 0x401b60
// 004022c0  85c0                 test eax, eax
// 004022c2  741a                 je 0x4022de
// 004022c4  8b7604               mov esi, dword ptr [esi + 4]
// 004022c7  8b041e               mov eax, dword ptr [esi + ebx]
// 004022ca  8b4804               mov ecx, dword ptr [eax + 4]
// 004022cd  03f3                 add esi, ebx
// 004022cf  56                   push esi
// 004022d0  ffd1                 call ecx
// 004022d2  897500               mov dword ptr [ebp], esi
// 004022d5  33c0                 xor eax, eax
// 004022d7  5f                   pop edi
// 004022d8  5d                   pop ebp
// 004022d9  5e                   pop esi
// 004022da  5b                   pop ebx
// 004022db  c21000               ret 0x10
// 004022de  8b4e08               mov ecx, dword ptr [esi + 8]
// 004022e1  85c9                 test ecx, ecx
// 004022e3  7453                 je 0x402338
// 004022e5  8b06                 mov eax, dword ptr [esi]
// 004022e7  33db                 xor ebx, ebx
// 004022e9  85c0                 test eax, eax
// 004022eb  0f94c3               sete bl
// 004022ee  85db                 test ebx, ebx
// 004022f0  751e                 jne 0x402310
// 004022f2  8b10                 mov edx, dword ptr [eax]
// 004022f4  3b17                 cmp edx, dword ptr [edi]
// 004022f6  7536                 jne 0x40232e
// 004022f8  8b5004               mov edx, dword ptr [eax + 4]
// 004022fb  3b5704               cmp edx, dword ptr [edi + 4]
// 004022fe  752e                 jne 0x40232e
// 00402300  8b5008               mov edx, dword ptr [eax + 8]
// 00402303  3b5708               cmp edx, dword ptr [edi + 8]
// 00402306  7526                 jne 0x40232e
// 00402308  8b400c               mov eax, dword ptr [eax + 0xc]
// 0040230b  3b470c               cmp eax, dword ptr [edi + 0xc]
// 0040230e  751e                 jne 0x40232e
// 00402310  83f901               cmp ecx, 1
// 00402313  742f                 je 0x402344
// 00402315  8b5604               mov edx, dword ptr [esi + 4]
// 00402318  8b442414             mov eax, dword ptr [esp + 0x14]
// 0040231c  52                   push edx
// 0040231d  55                   push ebp
// 0040231e  57                   push edi
// 0040231f  50                   push eax
// 00402320  ffd1                 call ecx
// 00402322  85c0                 test eax, eax
// 00402324  74b1                 je 0x4022d7
// 00402326  85db                 test ebx, ebx
// 00402328  7504                 jne 0x40232e
// 0040232a  85c0                 test eax, eax
// 0040232c  7ca9                 jl 0x4022d7
// 0040232e  8b4e14               mov ecx, dword ptr [esi + 0x14]
// 00402331  83c60c               add esi, 0xc
// 00402334  85c9                 test ecx, ecx
// 00402336  75ad                 jne 0x4022e5
// 00402338  5f                   pop edi
// 00402339  5d                   pop ebp
// 0040233a  5e                   pop esi
// 0040233b  b802400080           mov eax, 0x80004002
// 00402340  5b                   pop ebx
// 00402341  c21000               ret 0x10
// 00402344  8b7604               mov esi, dword ptr [esi + 4]
// 00402347  03742414             add esi, dword ptr [esp + 0x14]
// 0040234b  8b0e                 mov ecx, dword ptr [esi]
// 0040234d  8b5104               mov edx, dword ptr [ecx + 4]
// 00402350  56                   push esi
// 00402351  ffd2                 call edx
// 00402353  5f                   pop edi
// 00402354  897500               mov dword ptr [ebp], esi
// 00402357  5d                   pop ebp
// 00402358  5e                   pop esi
// 00402359  33c0                 xor eax, eax
// 0040235b  5b                   pop ebx
// 0040235c  c21000               ret 0x10
// 0040235f  5e                   pop esi
// 00402360  b857000780           mov eax, 0x80070057
// 00402365  5b                   pop ebx
// 00402366  c21000               ret 0x10
// library mfc-9.0/atlmfc\src\mfc\wincore.cpp (function ?AtlInternalQueryInterface@ATL@@YGJPAXPBU_ATL_INTMAP_ENTRY@1@ABU_GUID@@PAPAX@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/wincore.cpp
