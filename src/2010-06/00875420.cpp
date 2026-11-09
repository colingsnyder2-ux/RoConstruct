// from server: 100% by auto
// roc 2010-06 00875420  unit: CXTPShadowsManager::CShadowWnd  size: 101 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00875420
//
// 00875420  8b4c2404             mov ecx, dword ptr [esp + 4]
// 00875424  85c9                 test ecx, ecx
// 00875426  745a                 je 0x875482
// 00875428  8b442408             mov eax, dword ptr [esp + 8]
// 0087542c  85c0                 test eax, eax
// 0087542e  7652                 jbe 0x875482
// 00875430  56                   push esi
// 00875431  57                   push edi
// 00875432  41                   inc ecx
// 00875433  8bf8                 mov edi, eax
// 00875435  8379ff00             cmp dword ptr [ecx - 1], 0
// 00875439  7507                 jne 0x875442
// 0087543b  c741fffffeff00       mov dword ptr [ecx - 1], 0xfffeff
// 00875442  0fb67102             movzx esi, byte ptr [ecx + 2]
// 00875446  85f6                 test esi, esi
// 00875448  742e                 je 0x875478
// 0087544a  0fb641ff             movzx eax, byte ptr [ecx - 1]
// 0087544e  69c0ff000000         imul eax, eax, 0xff
// 00875454  99                   cdq 
// 00875455  f7fe                 idiv esi
// 00875457  8841ff               mov byte ptr [ecx - 1], al
// 0087545a  0fb601               movzx eax, byte ptr [ecx]
// 0087545d  69c0ff000000         imul eax, eax, 0xff
// 00875463  99                   cdq 
// 00875464  f7fe                 idiv esi
// 00875466  8801                 mov byte ptr [ecx], al
// 00875468  0fb64101             movzx eax, byte ptr [ecx + 1]
// 0087546c  69c0ff000000         imul eax, eax, 0xff
// 00875472  99                   cdq 
// 00875473  f7fe                 idiv esi
// 00875475  884101               mov byte ptr [ecx + 1], al
// 00875478  83c104               add ecx, 4
// 0087547b  83ef01               sub edi, 1
// 0087547e  75b5                 jne 0x875435
// 00875480  5f                   pop edi
// 00875481  5e                   pop esi
// 00875482  c20800               ret 8
// library xtp-13.2.1/Source\CommandBars\XTPImageEditor.cpp (function ?FixAlphaLayer@CXTPImageEditorDlg@@AAEXPAEI@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/CommandBars/XTPImageEditor.cpp
