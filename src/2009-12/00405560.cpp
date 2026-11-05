// from server: 100% by auto
// roc 2009-12 00405560  unit: ATL::CRegObject  size: 233 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00405560
//
// 00405560  53                   push ebx
// 00405561  8b5c2408             mov ebx, dword ptr [esp + 8]
// 00405565  56                   push esi
// 00405566  85db                 test ebx, ebx
// 00405568  0f84d1000000         je 0x40563f
// 0040556e  8b742410             mov esi, dword ptr [esp + 0x10]
// 00405572  85f6                 test esi, esi
// 00405574  0f84c5000000         je 0x40563f
// 0040557a  55                   push ebp
// 0040557b  8b6c241c             mov ebp, dword ptr [esp + 0x1c]
// 0040557f  85ed                 test ebp, ebp
// 00405581  750b                 jne 0x40558e
// 00405583  5d                   pop ebp
// 00405584  5e                   pop esi
// 00405585  b803400080           mov eax, 0x80004003
// 0040558a  5b                   pop ebx
// 0040558b  c21000               ret 0x10
// 0040558e  57                   push edi
// 0040558f  8b7c241c             mov edi, dword ptr [esp + 0x1c]
// 00405593  57                   push edi
// 00405594  c7450000000000       mov dword ptr [ebp], 0
// 0040559b  e800f4ffff           call 0x4049a0
// 004055a0  85c0                 test eax, eax
// 004055a2  741a                 je 0x4055be
// 004055a4  8b7604               mov esi, dword ptr [esi + 4]
// 004055a7  8b041e               mov eax, dword ptr [esi + ebx]
// 004055aa  8b4804               mov ecx, dword ptr [eax + 4]
// 004055ad  03f3                 add esi, ebx
// 004055af  56                   push esi
// 004055b0  ffd1                 call ecx
// 004055b2  897500               mov dword ptr [ebp], esi
// 004055b5  33c0                 xor eax, eax
// 004055b7  5f                   pop edi
// 004055b8  5d                   pop ebp
// 004055b9  5e                   pop esi
// 004055ba  5b                   pop ebx
// 004055bb  c21000               ret 0x10
// 004055be  8b4e08               mov ecx, dword ptr [esi + 8]
// 004055c1  85c9                 test ecx, ecx
// 004055c3  7453                 je 0x405618
// 004055c5  8b06                 mov eax, dword ptr [esi]
// 004055c7  33db                 xor ebx, ebx
// 004055c9  85c0                 test eax, eax
// 004055cb  0f94c3               sete bl
// 004055ce  85db                 test ebx, ebx
// 004055d0  751e                 jne 0x4055f0
// 004055d2  8b10                 mov edx, dword ptr [eax]
// 004055d4  3b17                 cmp edx, dword ptr [edi]
// 004055d6  7536                 jne 0x40560e
// 004055d8  8b5004               mov edx, dword ptr [eax + 4]
// 004055db  3b5704               cmp edx, dword ptr [edi + 4]
// 004055de  752e                 jne 0x40560e
// 004055e0  8b5008               mov edx, dword ptr [eax + 8]
// 004055e3  3b5708               cmp edx, dword ptr [edi + 8]
// 004055e6  7526                 jne 0x40560e
// 004055e8  8b400c               mov eax, dword ptr [eax + 0xc]
// 004055eb  3b470c               cmp eax, dword ptr [edi + 0xc]
// 004055ee  751e                 jne 0x40560e
// 004055f0  83f901               cmp ecx, 1
// 004055f3  742f                 je 0x405624
// 004055f5  8b5604               mov edx, dword ptr [esi + 4]
// 004055f8  8b442414             mov eax, dword ptr [esp + 0x14]
// 004055fc  52                   push edx
// 004055fd  55                   push ebp
// 004055fe  57                   push edi
// 004055ff  50                   push eax
// 00405600  ffd1                 call ecx
// 00405602  85c0                 test eax, eax
// 00405604  74b1                 je 0x4055b7
// 00405606  85db                 test ebx, ebx
// 00405608  7504                 jne 0x40560e
// 0040560a  85c0                 test eax, eax
// 0040560c  7ca9                 jl 0x4055b7
// 0040560e  8b4e14               mov ecx, dword ptr [esi + 0x14]
// 00405611  83c60c               add esi, 0xc
// 00405614  85c9                 test ecx, ecx
// 00405616  75ad                 jne 0x4055c5
// 00405618  5f                   pop edi
// 00405619  5d                   pop ebp
// 0040561a  5e                   pop esi
// 0040561b  b802400080           mov eax, 0x80004002
// 00405620  5b                   pop ebx
// 00405621  c21000               ret 0x10
// 00405624  8b7604               mov esi, dword ptr [esi + 4]
// 00405627  03742414             add esi, dword ptr [esp + 0x14]
// 0040562b  8b0e                 mov ecx, dword ptr [esi]
// 0040562d  8b5104               mov edx, dword ptr [ecx + 4]
// 00405630  56                   push esi
// 00405631  ffd2                 call edx
// 00405633  5f                   pop edi
// 00405634  897500               mov dword ptr [ebp], esi
// 00405637  5d                   pop ebp
// 00405638  5e                   pop esi
// 00405639  33c0                 xor eax, eax
// 0040563b  5b                   pop ebx
// 0040563c  c21000               ret 0x10
// 0040563f  5e                   pop esi
// 00405640  b857000780           mov eax, 0x80070057
// 00405645  5b                   pop ebx
// 00405646  c21000               ret 0x10
// library mfc-9.0/atlmfc\src\mfc\wincore.cpp (function ?AtlInternalQueryInterface@ATL@@YGJPAXPBU_ATL_INTMAP_ENTRY@1@ABU_GUID@@PAPAX@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/wincore.cpp
