// from server: 100% by auto
// roc 2011-06 004067c0  unit: VCApp::?$IObjectSafetyRobloxImpl  size: 233 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 004067c0
//
// 004067c0  53                   push ebx
// 004067c1  8b5c2408             mov ebx, dword ptr [esp + 8]
// 004067c5  56                   push esi
// 004067c6  85db                 test ebx, ebx
// 004067c8  0f84d1000000         je 0x40689f
// 004067ce  8b742410             mov esi, dword ptr [esp + 0x10]
// 004067d2  85f6                 test esi, esi
// 004067d4  0f84c5000000         je 0x40689f
// 004067da  55                   push ebp
// 004067db  8b6c241c             mov ebp, dword ptr [esp + 0x1c]
// 004067df  85ed                 test ebp, ebp
// 004067e1  750b                 jne 0x4067ee
// 004067e3  5d                   pop ebp
// 004067e4  5e                   pop esi
// 004067e5  b803400080           mov eax, 0x80004003
// 004067ea  5b                   pop ebx
// 004067eb  c21000               ret 0x10
// 004067ee  57                   push edi
// 004067ef  8b7c241c             mov edi, dword ptr [esp + 0x1c]
// 004067f3  57                   push edi
// 004067f4  c7450000000000       mov dword ptr [ebp], 0
// 004067fb  e890ebffff           call 0x405390
// 00406800  85c0                 test eax, eax
// 00406802  741a                 je 0x40681e
// 00406804  8b7604               mov esi, dword ptr [esi + 4]
// 00406807  8b041e               mov eax, dword ptr [esi + ebx]
// 0040680a  8b4804               mov ecx, dword ptr [eax + 4]
// 0040680d  03f3                 add esi, ebx
// 0040680f  56                   push esi
// 00406810  ffd1                 call ecx
// 00406812  897500               mov dword ptr [ebp], esi
// 00406815  33c0                 xor eax, eax
// 00406817  5f                   pop edi
// 00406818  5d                   pop ebp
// 00406819  5e                   pop esi
// 0040681a  5b                   pop ebx
// 0040681b  c21000               ret 0x10
// 0040681e  8b4e08               mov ecx, dword ptr [esi + 8]
// 00406821  85c9                 test ecx, ecx
// 00406823  7453                 je 0x406878
// 00406825  8b06                 mov eax, dword ptr [esi]
// 00406827  33db                 xor ebx, ebx
// 00406829  85c0                 test eax, eax
// 0040682b  0f94c3               sete bl
// 0040682e  85db                 test ebx, ebx
// 00406830  751e                 jne 0x406850
// 00406832  8b10                 mov edx, dword ptr [eax]
// 00406834  3b17                 cmp edx, dword ptr [edi]
// 00406836  7536                 jne 0x40686e
// 00406838  8b5004               mov edx, dword ptr [eax + 4]
// 0040683b  3b5704               cmp edx, dword ptr [edi + 4]
// 0040683e  752e                 jne 0x40686e
// 00406840  8b5008               mov edx, dword ptr [eax + 8]
// 00406843  3b5708               cmp edx, dword ptr [edi + 8]
// 00406846  7526                 jne 0x40686e
// 00406848  8b400c               mov eax, dword ptr [eax + 0xc]
// 0040684b  3b470c               cmp eax, dword ptr [edi + 0xc]
// 0040684e  751e                 jne 0x40686e
// 00406850  83f901               cmp ecx, 1
// 00406853  742f                 je 0x406884
// 00406855  8b5604               mov edx, dword ptr [esi + 4]
// 00406858  8b442414             mov eax, dword ptr [esp + 0x14]
// 0040685c  52                   push edx
// 0040685d  55                   push ebp
// 0040685e  57                   push edi
// 0040685f  50                   push eax
// 00406860  ffd1                 call ecx
// 00406862  85c0                 test eax, eax
// 00406864  74b1                 je 0x406817
// 00406866  85db                 test ebx, ebx
// 00406868  7504                 jne 0x40686e
// 0040686a  85c0                 test eax, eax
// 0040686c  7ca9                 jl 0x406817
// 0040686e  8b4e14               mov ecx, dword ptr [esi + 0x14]
// 00406871  83c60c               add esi, 0xc
// 00406874  85c9                 test ecx, ecx
// 00406876  75ad                 jne 0x406825
// 00406878  5f                   pop edi
// 00406879  5d                   pop ebp
// 0040687a  5e                   pop esi
// 0040687b  b802400080           mov eax, 0x80004002
// 00406880  5b                   pop ebx
// 00406881  c21000               ret 0x10
// 00406884  8b7604               mov esi, dword ptr [esi + 4]
// 00406887  03742414             add esi, dword ptr [esp + 0x14]
// 0040688b  8b0e                 mov ecx, dword ptr [esi]
// 0040688d  8b5104               mov edx, dword ptr [ecx + 4]
// 00406890  56                   push esi
// 00406891  ffd2                 call edx
// 00406893  5f                   pop edi
// 00406894  897500               mov dword ptr [ebp], esi
// 00406897  5d                   pop ebp
// 00406898  5e                   pop esi
// 00406899  33c0                 xor eax, eax
// 0040689b  5b                   pop ebx
// 0040689c  c21000               ret 0x10
// 0040689f  5e                   pop esi
// 004068a0  b857000780           mov eax, 0x80070057
// 004068a5  5b                   pop ebx
// 004068a6  c21000               ret 0x10
// library mfc-9.0/atlmfc\src\mfc\wincore.cpp (function ?AtlInternalQueryInterface@ATL@@YGJPAXPBU_ATL_INTMAP_ENTRY@1@ABU_GUID@@PAPAX@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/wincore.cpp
