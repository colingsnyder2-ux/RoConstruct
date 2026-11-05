// from server: 100% by auto
// roc 2010-06 007f1200  unit: CXTPControlButtonColor  size: 75 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 007f1200
//
// 007f1200  56                   push esi
// 007f1201  8bf1                 mov esi, ecx
// 007f1203  e8788efbff           call 0x7aa080
// 007f1208  8bc8                 mov ecx, eax
// 007f120a  e881c0fbff           call 0x7ad290
// 007f120f  83f817               cmp eax, 0x17
// 007f1212  7d16                 jge 0x7f122a
// 007f1214  8b442408             mov eax, dword ptr [esp + 8]
// 007f1218  b917000000           mov ecx, 0x17
// 007f121d  c70094000000         mov dword ptr [eax], 0x94
// 007f1223  894804               mov dword ptr [eax + 4], ecx
// 007f1226  5e                   pop esi
// 007f1227  c20800               ret 8
// 007f122a  8bce                 mov ecx, esi
// 007f122c  e84f8efbff           call 0x7aa080
// 007f1231  8bc8                 mov ecx, eax
// 007f1233  e858c0fbff           call 0x7ad290
// 007f1238  8bc8                 mov ecx, eax
// 007f123a  8b442408             mov eax, dword ptr [esp + 8]
// 007f123e  c70094000000         mov dword ptr [eax], 0x94
// 007f1244  894804               mov dword ptr [eax + 4], ecx
// 007f1247  5e                   pop esi
// 007f1248  c20800               ret 8
// library xtp-13.2.1/Source\CommandBars\XTPControlPopupColor.cpp (function ?GetSize@CXTPControlButtonColor@@MAE?AVCSize@@PAVCDC@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/CommandBars/XTPControlPopupColor.cpp
