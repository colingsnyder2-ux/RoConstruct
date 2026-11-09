// from server: 100% by auto
// roc 2007-08 004016e0  unit: CAboutRobloxDialog  size: 133 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 004016e0
//
// 004016e0  8b442404             mov eax, dword ptr [esp + 4]
// 004016e4  83f850               cmp eax, 0x50
// 004016e7  7713                 ja 0x4016fc
// 004016e9  0fb68814174000       movzx ecx, byte ptr [eax + 0x401714]
// 004016f0  ff248d04174000       jmp dword ptr [ecx*4 + 0x401704]
// 004016f7  e972e52200           jmp 0x62fc6e
// 004016fc  e91fe82200           jmp 0x62ff20
// 00401701  c3                   ret 
// 00401702  8bff                 mov edi, edi
// 00401704  0117                 add dword ptr [edi], edx
// 00401706  40                   inc eax
// 00401707  00f7                 add bh, dh
// 00401709  16                   push ss
// 0040170a  40                   inc eax
// 0040170b  00fc                 add ah, bh
// 0040170d  16                   push ss
// 0040170e  40                   inc eax
// 0040170f  00fc                 add ah, bh
// 00401711  16                   push ss
// 00401712  40                   inc eax
// 00401713  0000                 add byte ptr [eax], al
// 00401715  0303                 add eax, dword ptr [ebx]
// 00401717  0303                 add eax, dword ptr [ebx]
// 00401719  0303                 add eax, dword ptr [ebx]
// 0040171b  0303                 add eax, dword ptr [ebx]
// 0040171d  0303                 add eax, dword ptr [ebx]
// 0040171f  0301                 add eax, dword ptr [ecx]
// 00401721  0303                 add eax, dword ptr [ebx]
// 00401723  0303                 add eax, dword ptr [ebx]
// 00401725  0303                 add eax, dword ptr [ebx]
// 00401727  0303                 add eax, dword ptr [ebx]
// 00401729  0302                 add eax, dword ptr [edx]
// 0040172b  0303                 add eax, dword ptr [ebx]
// 0040172d  0303                 add eax, dword ptr [ebx]
// 0040172f  0303                 add eax, dword ptr [ebx]
// 00401731  0303                 add eax, dword ptr [ebx]
// 00401733  0303                 add eax, dword ptr [ebx]
// 00401735  0302                 add eax, dword ptr [edx]
// 00401737  0303                 add eax, dword ptr [ebx]
// 00401739  0303                 add eax, dword ptr [ebx]
// 0040173b  0303                 add eax, dword ptr [ebx]
// 0040173d  0303                 add eax, dword ptr [ebx]
// 0040173f  0303                 add eax, dword ptr [ebx]
// 00401741  0303                 add eax, dword ptr [ebx]
// 00401743  0303                 add eax, dword ptr [ebx]
// 00401745  0303                 add eax, dword ptr [ebx]
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
// 00401763  0300                 add eax, dword ptr [eax]
// library mfc-8.0/atlmfc\src\mfc\afxabort.cpp (function ?AfxCrtErrorCheck@@YAHH@Z)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-8.0 atlmfc/src/mfc/afxabort.cpp
