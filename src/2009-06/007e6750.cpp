// from server: 100% by auto
// roc 2009-06 007e6750  unit: CXTPShadowsManager::CShadowWnd  size: 101 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 007e6750
//
// 007e6750  8b4c2404             mov ecx, dword ptr [esp + 4]
// 007e6754  85c9                 test ecx, ecx
// 007e6756  745a                 je 0x7e67b2
// 007e6758  8b442408             mov eax, dword ptr [esp + 8]
// 007e675c  85c0                 test eax, eax
// 007e675e  7652                 jbe 0x7e67b2
// 007e6760  56                   push esi
// 007e6761  57                   push edi
// 007e6762  41                   inc ecx
// 007e6763  8bf8                 mov edi, eax
// 007e6765  8379ff00             cmp dword ptr [ecx - 1], 0
// 007e6769  7507                 jne 0x7e6772
// 007e676b  c741fffffeff00       mov dword ptr [ecx - 1], 0xfffeff
// 007e6772  0fb67102             movzx esi, byte ptr [ecx + 2]
// 007e6776  85f6                 test esi, esi
// 007e6778  742e                 je 0x7e67a8
// 007e677a  0fb641ff             movzx eax, byte ptr [ecx - 1]
// 007e677e  69c0ff000000         imul eax, eax, 0xff
// 007e6784  99                   cdq 
// 007e6785  f7fe                 idiv esi
// 007e6787  8841ff               mov byte ptr [ecx - 1], al
// 007e678a  0fb601               movzx eax, byte ptr [ecx]
// 007e678d  69c0ff000000         imul eax, eax, 0xff
// 007e6793  99                   cdq 
// 007e6794  f7fe                 idiv esi
// 007e6796  8801                 mov byte ptr [ecx], al
// 007e6798  0fb64101             movzx eax, byte ptr [ecx + 1]
// 007e679c  69c0ff000000         imul eax, eax, 0xff
// 007e67a2  99                   cdq 
// 007e67a3  f7fe                 idiv esi
// 007e67a5  884101               mov byte ptr [ecx + 1], al
// 007e67a8  83c104               add ecx, 4
// 007e67ab  83ef01               sub edi, 1
// 007e67ae  75b5                 jne 0x7e6765
// 007e67b0  5f                   pop edi
// 007e67b1  5e                   pop esi
// 007e67b2  c20800               ret 8
// library xtp-15.2.1/Source\CommandBars\XTPImageEditor.cpp (function ?FixAlphaLayer@CXTPImageEditorDlg@@AAEXPAEI@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/CommandBars/XTPImageEditor.cpp
