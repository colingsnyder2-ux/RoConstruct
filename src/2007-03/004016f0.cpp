// from server: 100% by auto
// roc 2007-03 004016f0  unit: seg_00400000  size: 133 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 004016f0
//
// 004016f0  8b442404             mov eax, dword ptr [esp + 4]
// 004016f4  83f850               cmp eax, 0x50
// 004016f7  7713                 ja 0x40170c
// 004016f9  0fb68824174000       movzx ecx, byte ptr [eax + 0x401724]
// 00401700  ff248d14174000       jmp dword ptr [ecx*4 + 0x401714]
// 00401707  e9f0c92100           jmp 0x61e0fc
// 0040170c  e99dcc2100           jmp 0x61e3ae
// 00401711  c3                   ret 
// 00401712  8bff                 mov edi, edi
// 00401714  1117                 adc dword ptr [edi], edx
// 00401716  40                   inc eax
// 00401717  0007                 add byte ptr [edi], al
// 00401719  17                   pop ss
// 0040171a  40                   inc eax
// 0040171b  000c17               add byte ptr [edi + edx], cl
// 0040171e  40                   inc eax
// 0040171f  000c17               add byte ptr [edi + edx], cl
// 00401722  40                   inc eax
// 00401723  0000                 add byte ptr [eax], al
// 00401725  0303                 add eax, dword ptr [ebx]
// 00401727  0303                 add eax, dword ptr [ebx]
// 00401729  0303                 add eax, dword ptr [ebx]
// 0040172b  0303                 add eax, dword ptr [ebx]
// 0040172d  0303                 add eax, dword ptr [ebx]
// 0040172f  0301                 add eax, dword ptr [ecx]
// 00401731  0303                 add eax, dword ptr [ebx]
// 00401733  0303                 add eax, dword ptr [ebx]
// 00401735  0303                 add eax, dword ptr [ebx]
// 00401737  0303                 add eax, dword ptr [ebx]
// 00401739  0302                 add eax, dword ptr [edx]
// 0040173b  0303                 add eax, dword ptr [ebx]
// 0040173d  0303                 add eax, dword ptr [ebx]
// 0040173f  0303                 add eax, dword ptr [ebx]
// 00401741  0303                 add eax, dword ptr [ebx]
// 00401743  0303                 add eax, dword ptr [ebx]
// 00401745  0302                 add eax, dword ptr [edx]
// 00401747  0303                 add eax, dword ptr [ebx]
// 00401749  0303                 add eax, dword ptr [ebx]
// 0040174b  0303                 add eax, dword ptr [ebx]
// 0040174d  0303                 add eax, dword ptr [ebx]
// 0040174f  0303                 add eax, dword ptr [ebx]
// 00401751  0303                 add eax, dword ptr [ebx]
// 00401753  0303                 add eax, dword ptr [ebx]
// 00401755  0303                 add eax, dword ptr [ebx]
// 00401757  0303                 add eax, dword ptr [ebx]
// 00401759  0303                 add eax, dword ptr [ebx]
// 0040175b  0303                 add eax, dword ptr [ebx]
// 0040175d  0303                 add eax, dword ptr [ebx]
// 0040175f  0303                 add eax, dword ptr [ebx]
// 00401761  0303                 add eax, dword ptr [ebx]
// 00401763  0303                 add eax, dword ptr [ebx]
// 00401765  0303                 add eax, dword ptr [ebx]
// 00401767  0303                 add eax, dword ptr [ebx]
// 00401769  0303                 add eax, dword ptr [ebx]
// 0040176b  0303                 add eax, dword ptr [ebx]
// 0040176d  0303                 add eax, dword ptr [ebx]
// 0040176f  0303                 add eax, dword ptr [ebx]
// 00401771  0303                 add eax, dword ptr [ebx]
// 00401773  0300                 add eax, dword ptr [eax]
// library mfc-8.0/atlmfc\src\mfc\afxabort.cpp (function ?AfxCrtErrorCheck@@YAHH@Z)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-8.0 atlmfc/src/mfc/afxabort.cpp
