// from server: 100% by auto
// roc 2010-06 00404f70  unit: VCApp::?$IObjectSafetyRobloxImpl  size: 233 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00404f70
//
// 00404f70  53                   push ebx
// 00404f71  8b5c2408             mov ebx, dword ptr [esp + 8]
// 00404f75  56                   push esi
// 00404f76  85db                 test ebx, ebx
// 00404f78  0f84d1000000         je 0x40504f
// 00404f7e  8b742410             mov esi, dword ptr [esp + 0x10]
// 00404f82  85f6                 test esi, esi
// 00404f84  0f84c5000000         je 0x40504f
// 00404f8a  55                   push ebp
// 00404f8b  8b6c241c             mov ebp, dword ptr [esp + 0x1c]
// 00404f8f  85ed                 test ebp, ebp
// 00404f91  750b                 jne 0x404f9e
// 00404f93  5d                   pop ebp
// 00404f94  5e                   pop esi
// 00404f95  b803400080           mov eax, 0x80004003
// 00404f9a  5b                   pop ebx
// 00404f9b  c21000               ret 0x10
// 00404f9e  57                   push edi
// 00404f9f  8b7c241c             mov edi, dword ptr [esp + 0x1c]
// 00404fa3  57                   push edi
// 00404fa4  c7450000000000       mov dword ptr [ebp], 0
// 00404fab  e810f6ffff           call 0x4045c0
// 00404fb0  85c0                 test eax, eax
// 00404fb2  741a                 je 0x404fce
// 00404fb4  8b7604               mov esi, dword ptr [esi + 4]
// 00404fb7  8b041e               mov eax, dword ptr [esi + ebx]
// 00404fba  8b4804               mov ecx, dword ptr [eax + 4]
// 00404fbd  03f3                 add esi, ebx
// 00404fbf  56                   push esi
// 00404fc0  ffd1                 call ecx
// 00404fc2  897500               mov dword ptr [ebp], esi
// 00404fc5  33c0                 xor eax, eax
// 00404fc7  5f                   pop edi
// 00404fc8  5d                   pop ebp
// 00404fc9  5e                   pop esi
// 00404fca  5b                   pop ebx
// 00404fcb  c21000               ret 0x10
// 00404fce  8b4e08               mov ecx, dword ptr [esi + 8]
// 00404fd1  85c9                 test ecx, ecx
// 00404fd3  7453                 je 0x405028
// 00404fd5  8b06                 mov eax, dword ptr [esi]
// 00404fd7  33db                 xor ebx, ebx
// 00404fd9  85c0                 test eax, eax
// 00404fdb  0f94c3               sete bl
// 00404fde  85db                 test ebx, ebx
// 00404fe0  751e                 jne 0x405000
// 00404fe2  8b10                 mov edx, dword ptr [eax]
// 00404fe4  3b17                 cmp edx, dword ptr [edi]
// 00404fe6  7536                 jne 0x40501e
// 00404fe8  8b5004               mov edx, dword ptr [eax + 4]
// 00404feb  3b5704               cmp edx, dword ptr [edi + 4]
// 00404fee  752e                 jne 0x40501e
// 00404ff0  8b5008               mov edx, dword ptr [eax + 8]
// 00404ff3  3b5708               cmp edx, dword ptr [edi + 8]
// 00404ff6  7526                 jne 0x40501e
// 00404ff8  8b400c               mov eax, dword ptr [eax + 0xc]
// 00404ffb  3b470c               cmp eax, dword ptr [edi + 0xc]
// 00404ffe  751e                 jne 0x40501e
// 00405000  83f901               cmp ecx, 1
// 00405003  742f                 je 0x405034
// 00405005  8b5604               mov edx, dword ptr [esi + 4]
// 00405008  8b442414             mov eax, dword ptr [esp + 0x14]
// 0040500c  52                   push edx
// 0040500d  55                   push ebp
// 0040500e  57                   push edi
// 0040500f  50                   push eax
// 00405010  ffd1                 call ecx
// 00405012  85c0                 test eax, eax
// 00405014  74b1                 je 0x404fc7
// 00405016  85db                 test ebx, ebx
// 00405018  7504                 jne 0x40501e
// 0040501a  85c0                 test eax, eax
// 0040501c  7ca9                 jl 0x404fc7
// 0040501e  8b4e14               mov ecx, dword ptr [esi + 0x14]
// 00405021  83c60c               add esi, 0xc
// 00405024  85c9                 test ecx, ecx
// 00405026  75ad                 jne 0x404fd5
// 00405028  5f                   pop edi
// 00405029  5d                   pop ebp
// 0040502a  5e                   pop esi
// 0040502b  b802400080           mov eax, 0x80004002
// 00405030  5b                   pop ebx
// 00405031  c21000               ret 0x10
// 00405034  8b7604               mov esi, dword ptr [esi + 4]
// 00405037  03742414             add esi, dword ptr [esp + 0x14]
// 0040503b  8b0e                 mov ecx, dword ptr [esi]
// 0040503d  8b5104               mov edx, dword ptr [ecx + 4]
// 00405040  56                   push esi
// 00405041  ffd2                 call edx
// 00405043  5f                   pop edi
// 00405044  897500               mov dword ptr [ebp], esi
// 00405047  5d                   pop ebp
// 00405048  5e                   pop esi
// 00405049  33c0                 xor eax, eax
// 0040504b  5b                   pop ebx
// 0040504c  c21000               ret 0x10
// 0040504f  5e                   pop esi
// 00405050  b857000780           mov eax, 0x80070057
// 00405055  5b                   pop ebx
// 00405056  c21000               ret 0x10
// library mfc-9.0/atlmfc\src\mfc\wincore.cpp (function ?AtlInternalQueryInterface@ATL@@YGJPAXPBU_ATL_INTMAP_ENTRY@1@ABU_GUID@@PAPAX@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/wincore.cpp
