// from server: 100% by auto
// roc 2007-08 004022a0  unit: VCWorkspace::?$CComObject  size: 233 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 004022a0
//
// 004022a0  53                   push ebx
// 004022a1  8b5c2408             mov ebx, dword ptr [esp + 8]
// 004022a5  85db                 test ebx, ebx
// 004022a7  56                   push esi
// 004022a8  0f84d1000000         je 0x40237f
// 004022ae  8b742410             mov esi, dword ptr [esp + 0x10]
// 004022b2  85f6                 test esi, esi
// 004022b4  0f84c5000000         je 0x40237f
// 004022ba  55                   push ebp
// 004022bb  8b6c241c             mov ebp, dword ptr [esp + 0x1c]
// 004022bf  85ed                 test ebp, ebp
// 004022c1  750b                 jne 0x4022ce
// 004022c3  5d                   pop ebp
// 004022c4  5e                   pop esi
// 004022c5  b803400080           mov eax, 0x80004003
// 004022ca  5b                   pop ebx
// 004022cb  c21000               ret 0x10
// 004022ce  57                   push edi
// 004022cf  8b7c241c             mov edi, dword ptr [esp + 0x1c]
// 004022d3  57                   push edi
// 004022d4  c7450000000000       mov dword ptr [ebp], 0
// 004022db  e820f9ffff           call 0x401c00
// 004022e0  85c0                 test eax, eax
// 004022e2  741a                 je 0x4022fe
// 004022e4  8b7604               mov esi, dword ptr [esi + 4]
// 004022e7  8b041e               mov eax, dword ptr [esi + ebx]
// 004022ea  8b4804               mov ecx, dword ptr [eax + 4]
// 004022ed  03f3                 add esi, ebx
// 004022ef  56                   push esi
// 004022f0  ffd1                 call ecx
// 004022f2  897500               mov dword ptr [ebp], esi
// 004022f5  33c0                 xor eax, eax
// 004022f7  5f                   pop edi
// 004022f8  5d                   pop ebp
// 004022f9  5e                   pop esi
// 004022fa  5b                   pop ebx
// 004022fb  c21000               ret 0x10
// 004022fe  8b4e08               mov ecx, dword ptr [esi + 8]
// 00402301  85c9                 test ecx, ecx
// 00402303  7453                 je 0x402358
// 00402305  8b06                 mov eax, dword ptr [esi]
// 00402307  33db                 xor ebx, ebx
// 00402309  85c0                 test eax, eax
// 0040230b  0f94c3               sete bl
// 0040230e  85db                 test ebx, ebx
// 00402310  751e                 jne 0x402330
// 00402312  8b10                 mov edx, dword ptr [eax]
// 00402314  3b17                 cmp edx, dword ptr [edi]
// 00402316  7536                 jne 0x40234e
// 00402318  8b5004               mov edx, dword ptr [eax + 4]
// 0040231b  3b5704               cmp edx, dword ptr [edi + 4]
// 0040231e  752e                 jne 0x40234e
// 00402320  8b5008               mov edx, dword ptr [eax + 8]
// 00402323  3b5708               cmp edx, dword ptr [edi + 8]
// 00402326  7526                 jne 0x40234e
// 00402328  8b400c               mov eax, dword ptr [eax + 0xc]
// 0040232b  3b470c               cmp eax, dword ptr [edi + 0xc]
// 0040232e  751e                 jne 0x40234e
// 00402330  83f901               cmp ecx, 1
// 00402333  742f                 je 0x402364
// 00402335  8b5604               mov edx, dword ptr [esi + 4]
// 00402338  8b442414             mov eax, dword ptr [esp + 0x14]
// 0040233c  52                   push edx
// 0040233d  55                   push ebp
// 0040233e  57                   push edi
// 0040233f  50                   push eax
// 00402340  ffd1                 call ecx
// 00402342  85c0                 test eax, eax
// 00402344  74b1                 je 0x4022f7
// 00402346  85db                 test ebx, ebx
// 00402348  7504                 jne 0x40234e
// 0040234a  85c0                 test eax, eax
// 0040234c  7ca9                 jl 0x4022f7
// 0040234e  8b4e14               mov ecx, dword ptr [esi + 0x14]
// 00402351  83c60c               add esi, 0xc
// 00402354  85c9                 test ecx, ecx
// 00402356  75ad                 jne 0x402305
// 00402358  5f                   pop edi
// 00402359  5d                   pop ebp
// 0040235a  5e                   pop esi
// 0040235b  b802400080           mov eax, 0x80004002
// 00402360  5b                   pop ebx
// 00402361  c21000               ret 0x10
// 00402364  8b7604               mov esi, dword ptr [esi + 4]
// 00402367  03742414             add esi, dword ptr [esp + 0x14]
// 0040236b  8b0e                 mov ecx, dword ptr [esi]
// 0040236d  8b5104               mov edx, dword ptr [ecx + 4]
// 00402370  56                   push esi
// 00402371  ffd2                 call edx
// 00402373  5f                   pop edi
// 00402374  897500               mov dword ptr [ebp], esi
// 00402377  5d                   pop ebp
// 00402378  5e                   pop esi
// 00402379  33c0                 xor eax, eax
// 0040237b  5b                   pop ebx
// 0040237c  c21000               ret 0x10
// 0040237f  5e                   pop esi
// 00402380  b857000780           mov eax, 0x80070057
// 00402385  5b                   pop ebx
// 00402386  c21000               ret 0x10
// library atl-8.0/atl.cpp (function _AtlInternalQueryInterface@16)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: atl-8.0 atl.cpp
