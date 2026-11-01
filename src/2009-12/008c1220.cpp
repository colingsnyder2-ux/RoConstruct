// from server: 100% by auto
// roc 2009-12 008c1220  unit: CXTPShadowsManager::CShadowWnd  size: 101 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 008c1220
//
// 008c1220  8b4c2404             mov ecx, dword ptr [esp + 4]
// 008c1224  85c9                 test ecx, ecx
// 008c1226  745a                 je 0x8c1282
// 008c1228  8b442408             mov eax, dword ptr [esp + 8]
// 008c122c  85c0                 test eax, eax
// 008c122e  7652                 jbe 0x8c1282
// 008c1230  56                   push esi
// 008c1231  57                   push edi
// 008c1232  41                   inc ecx
// 008c1233  8bf8                 mov edi, eax
// 008c1235  8379ff00             cmp dword ptr [ecx - 1], 0
// 008c1239  7507                 jne 0x8c1242
// 008c123b  c741fffffeff00       mov dword ptr [ecx - 1], 0xfffeff
// 008c1242  0fb67102             movzx esi, byte ptr [ecx + 2]
// 008c1246  85f6                 test esi, esi
// 008c1248  742e                 je 0x8c1278
// 008c124a  0fb641ff             movzx eax, byte ptr [ecx - 1]
// 008c124e  69c0ff000000         imul eax, eax, 0xff
// 008c1254  99                   cdq 
// 008c1255  f7fe                 idiv esi
// 008c1257  8841ff               mov byte ptr [ecx - 1], al
// 008c125a  0fb601               movzx eax, byte ptr [ecx]
// 008c125d  69c0ff000000         imul eax, eax, 0xff
// 008c1263  99                   cdq 
// 008c1264  f7fe                 idiv esi
// 008c1266  8801                 mov byte ptr [ecx], al
// 008c1268  0fb64101             movzx eax, byte ptr [ecx + 1]
// 008c126c  69c0ff000000         imul eax, eax, 0xff
// 008c1272  99                   cdq 
// 008c1273  f7fe                 idiv esi
// 008c1275  884101               mov byte ptr [ecx + 1], al
// 008c1278  83c104               add ecx, 4
// 008c127b  83ef01               sub edi, 1
// 008c127e  75b5                 jne 0x8c1235
// 008c1280  5f                   pop edi
// 008c1281  5e                   pop esi
// 008c1282  c20800               ret 8
// library xtp-15.2.1/Source\CommandBars\XTPImageEditor.cpp (function ?FixAlphaLayer@CXTPImageEditorDlg@@AAEXPAEI@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/CommandBars/XTPImageEditor.cpp
