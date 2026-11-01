// from server: 100% by auto
// roc 2009-06 00762320  unit: CXTPControlButtonColor  size: 75 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00762320
//
// 00762320  56                   push esi
// 00762321  8bf1                 mov esi, ecx
// 00762323  e8f8d5fbff           call 0x71f920
// 00762328  8bc8                 mov ecx, eax
// 0076232a  e8d105fcff           call 0x722900
// 0076232f  83f817               cmp eax, 0x17
// 00762332  7d16                 jge 0x76234a
// 00762334  8b442408             mov eax, dword ptr [esp + 8]
// 00762338  b917000000           mov ecx, 0x17
// 0076233d  c70094000000         mov dword ptr [eax], 0x94
// 00762343  894804               mov dword ptr [eax + 4], ecx
// 00762346  5e                   pop esi
// 00762347  c20800               ret 8
// 0076234a  8bce                 mov ecx, esi
// 0076234c  e8cfd5fbff           call 0x71f920
// 00762351  8bc8                 mov ecx, eax
// 00762353  e8a805fcff           call 0x722900
// 00762358  8bc8                 mov ecx, eax
// 0076235a  8b442408             mov eax, dword ptr [esp + 8]
// 0076235e  c70094000000         mov dword ptr [eax], 0x94
// 00762364  894804               mov dword ptr [eax + 4], ecx
// 00762367  5e                   pop esi
// 00762368  c20800               ret 8
// library xtp-15.2.1/Source\CommandBars\XTPControlPopupColor.cpp (function ?GetSize@CXTPControlButtonColor@@MAE?AVCSize@@PAVCDC@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/CommandBars/XTPControlPopupColor.cpp
