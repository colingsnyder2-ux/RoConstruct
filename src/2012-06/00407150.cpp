// from server: 100% by auto
// roc 2012-06 00407150  unit: VCApp::?$IObjectSafetyRobloxImpl  size: 233 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00407150
//
// 00407150  53                   push ebx
// 00407151  8b5c2408             mov ebx, dword ptr [esp + 8]
// 00407155  56                   push esi
// 00407156  85db                 test ebx, ebx
// 00407158  0f84d1000000         je 0x40722f
// 0040715e  8b742410             mov esi, dword ptr [esp + 0x10]
// 00407162  85f6                 test esi, esi
// 00407164  0f84c5000000         je 0x40722f
// 0040716a  55                   push ebp
// 0040716b  8b6c241c             mov ebp, dword ptr [esp + 0x1c]
// 0040716f  85ed                 test ebp, ebp
// 00407171  750b                 jne 0x40717e
// 00407173  5d                   pop ebp
// 00407174  5e                   pop esi
// 00407175  b803400080           mov eax, 0x80004003
// 0040717a  5b                   pop ebx
// 0040717b  c21000               ret 0x10
// 0040717e  57                   push edi
// 0040717f  8b7c241c             mov edi, dword ptr [esp + 0x1c]
// 00407183  57                   push edi
// 00407184  c7450000000000       mov dword ptr [ebp], 0
// 0040718b  e8a0e9ffff           call 0x405b30
// 00407190  85c0                 test eax, eax
// 00407192  741a                 je 0x4071ae
// 00407194  8b7604               mov esi, dword ptr [esi + 4]
// 00407197  8b041e               mov eax, dword ptr [esi + ebx]
// 0040719a  8b4804               mov ecx, dword ptr [eax + 4]
// 0040719d  03f3                 add esi, ebx
// 0040719f  56                   push esi
// 004071a0  ffd1                 call ecx
// 004071a2  897500               mov dword ptr [ebp], esi
// 004071a5  33c0                 xor eax, eax
// 004071a7  5f                   pop edi
// 004071a8  5d                   pop ebp
// 004071a9  5e                   pop esi
// 004071aa  5b                   pop ebx
// 004071ab  c21000               ret 0x10
// 004071ae  8b4e08               mov ecx, dword ptr [esi + 8]
// 004071b1  85c9                 test ecx, ecx
// 004071b3  7453                 je 0x407208
// 004071b5  8b06                 mov eax, dword ptr [esi]
// 004071b7  33db                 xor ebx, ebx
// 004071b9  85c0                 test eax, eax
// 004071bb  0f94c3               sete bl
// 004071be  85db                 test ebx, ebx
// 004071c0  751e                 jne 0x4071e0
// 004071c2  8b10                 mov edx, dword ptr [eax]
// 004071c4  3b17                 cmp edx, dword ptr [edi]
// 004071c6  7536                 jne 0x4071fe
// 004071c8  8b5004               mov edx, dword ptr [eax + 4]
// 004071cb  3b5704               cmp edx, dword ptr [edi + 4]
// 004071ce  752e                 jne 0x4071fe
// 004071d0  8b5008               mov edx, dword ptr [eax + 8]
// 004071d3  3b5708               cmp edx, dword ptr [edi + 8]
// 004071d6  7526                 jne 0x4071fe
// 004071d8  8b400c               mov eax, dword ptr [eax + 0xc]
// 004071db  3b470c               cmp eax, dword ptr [edi + 0xc]
// 004071de  751e                 jne 0x4071fe
// 004071e0  83f901               cmp ecx, 1
// 004071e3  742f                 je 0x407214
// 004071e5  8b5604               mov edx, dword ptr [esi + 4]
// 004071e8  8b442414             mov eax, dword ptr [esp + 0x14]
// 004071ec  52                   push edx
// 004071ed  55                   push ebp
// 004071ee  57                   push edi
// 004071ef  50                   push eax
// 004071f0  ffd1                 call ecx
// 004071f2  85c0                 test eax, eax
// 004071f4  74b1                 je 0x4071a7
// 004071f6  85db                 test ebx, ebx
// 004071f8  7504                 jne 0x4071fe
// 004071fa  85c0                 test eax, eax
// 004071fc  7ca9                 jl 0x4071a7
// 004071fe  8b4e14               mov ecx, dword ptr [esi + 0x14]
// 00407201  83c60c               add esi, 0xc
// 00407204  85c9                 test ecx, ecx
// 00407206  75ad                 jne 0x4071b5
// 00407208  5f                   pop edi
// 00407209  5d                   pop ebp
// 0040720a  5e                   pop esi
// 0040720b  b802400080           mov eax, 0x80004002
// 00407210  5b                   pop ebx
// 00407211  c21000               ret 0x10
// 00407214  8b7604               mov esi, dword ptr [esi + 4]
// 00407217  03742414             add esi, dword ptr [esp + 0x14]
// 0040721b  8b0e                 mov ecx, dword ptr [esi]
// 0040721d  8b5104               mov edx, dword ptr [ecx + 4]
// 00407220  56                   push esi
// 00407221  ffd2                 call edx
// 00407223  5f                   pop edi
// 00407224  897500               mov dword ptr [ebp], esi
// 00407227  5d                   pop ebp
// 00407228  5e                   pop esi
// 00407229  33c0                 xor eax, eax
// 0040722b  5b                   pop ebx
// 0040722c  c21000               ret 0x10
// 0040722f  5e                   pop esi
// 00407230  b857000780           mov eax, 0x80070057
// 00407235  5b                   pop ebx
// 00407236  c21000               ret 0x10
// library mfc-9.0/atlmfc\src\mfc\wincore.cpp (function ?AtlInternalQueryInterface@ATL@@YGJPAXPBU_ATL_INTMAP_ENTRY@1@ABU_GUID@@PAPAX@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/wincore.cpp
