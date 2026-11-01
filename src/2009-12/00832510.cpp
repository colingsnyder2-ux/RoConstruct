// from server: 100% by auto
// roc 2009-12 00832510  unit: CRobloxTreeCtrl  size: 79 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00832510
//
// 00832510  8b442404             mov eax, dword ptr [esp + 4]
// 00832514  56                   push esi
// 00832515  57                   push edi
// 00832516  33ff                 xor edi, edi
// 00832518  8bf1                 mov esi, ecx
// 0083251a  85c0                 test eax, eax
// 0083251c  740f                 je 0x83252d
// 0083251e  6a01                 push 1
// 00832520  6a01                 push 1
// 00832522  50                   push eax
// 00832523  e828fcffff           call 0x832150
// 00832528  5f                   pop edi
// 00832529  5e                   pop esi
// 0083252a  c20400               ret 4
// 0083252d  8b4634               mov eax, dword ptr [esi + 0x34]
// 00832530  8b4020               mov eax, dword ptr [eax + 0x20]
// 00832533  6a00                 push 0
// 00832535  6a09                 push 9
// 00832537  680a110000           push 0x110a
// 0083253c  50                   push eax
// 0083253d  ff15c4cb9800         call dword ptr [0x98cbc4]
// 00832543  85c0                 test eax, eax
// 00832545  7411                 je 0x832558
// 00832547  6a01                 push 1
// 00832549  6a00                 push 0
// 0083254b  50                   push eax
// 0083254c  8bce                 mov ecx, esi
// 0083254e  e8fdfbffff           call 0x832150
// 00832553  5f                   pop edi
// 00832554  5e                   pop esi
// 00832555  c20400               ret 4
// 00832558  8bc7                 mov eax, edi
// 0083255a  5f                   pop edi
// 0083255b  5e                   pop esi
// 0083255c  c20400               ret 4
// library xtp-15.2.1/Source\Controls\Tree\XTPTreeBase.cpp (function ?FocusItem@CXTPTreeBase@@QAEHPAU_TREEITEM@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/Controls/Tree/XTPTreeBase.cpp
