// from server: 100% by auto
// roc 2011-06 008cd6e0  unit: XTPDockingPanePaintThemes::CXTPDockingPaneNativeXPTheme  size: 137 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 008cd6e0
//
// 008cd6e0  53                   push ebx
// 008cd6e1  8b5904               mov ebx, dword ptr [ecx + 4]
// 008cd6e4  85db                 test ebx, ebx
// 008cd6e6  7505                 jne 0x8cd6ed
// 008cd6e8  e81dccf3ff           call 0x80a30a
// 008cd6ed  55                   push ebp
// 008cd6ee  8b6c240c             mov ebp, dword ptr [esp + 0xc]
// 008cd6f2  56                   push esi
// 008cd6f3  8b7500               mov esi, dword ptr [ebp]
// 008cd6f6  85f6                 test esi, esi
// 008cd6f8  7505                 jne 0x8cd6ff
// 008cd6fa  e80bccf3ff           call 0x80a30a
// 008cd6ff  57                   push edi
// 008cd700  83feff               cmp esi, -1
// 008cd703  751e                 jne 0x8cd723
// 008cd705  8b7908               mov edi, dword ptr [ecx + 8]
// 008cd708  33c0                 xor eax, eax
// 008cd70a  85ff                 test edi, edi
// 008cd70c  7615                 jbe 0x8cd723
// 008cd70e  8bd3                 mov edx, ebx
// 008cd710  8b32                 mov esi, dword ptr [edx]
// 008cd712  85f6                 test esi, esi
// 008cd714  750d                 jne 0x8cd723
// 008cd716  40                   inc eax
// 008cd717  83c204               add edx, 4
// 008cd71a  3bc7                 cmp eax, edi
// 008cd71c  72f2                 jb 0x8cd710
// 008cd71e  e8e7cbf3ff           call 0x80a30a
// 008cd723  8b7e08               mov edi, dword ptr [esi + 8]
// 008cd726  85ff                 test edi, edi
// 008cd728  7524                 jne 0x8cd74e
// 008cd72a  8b4908               mov ecx, dword ptr [ecx + 8]
// 008cd72d  8b460c               mov eax, dword ptr [esi + 0xc]
// 008cd730  33d2                 xor edx, edx
// 008cd732  f7f1                 div ecx
// 008cd734  42                   inc edx
// 008cd735  3bd1                 cmp edx, ecx
// 008cd737  7315                 jae 0x8cd74e
// 008cd739  8d0493               lea eax, [ebx + edx*4]
// 008cd73c  8d642400             lea esp, [esp]
// 008cd740  8b38                 mov edi, dword ptr [eax]
// 008cd742  85ff                 test edi, edi
// 008cd744  7508                 jne 0x8cd74e
// 008cd746  42                   inc edx
// 008cd747  83c004               add eax, 4
// 008cd74a  3bd1                 cmp edx, ecx
// 008cd74c  72f2                 jb 0x8cd740
// 008cd74e  8b4c2418             mov ecx, dword ptr [esp + 0x18]
// 008cd752  897d00               mov dword ptr [ebp], edi
// 008cd755  8b06                 mov eax, dword ptr [esi]
// 008cd757  8901                 mov dword ptr [ecx], eax
// 008cd759  8b5604               mov edx, dword ptr [esi + 4]
// 008cd75c  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 008cd760  5f                   pop edi
// 008cd761  5e                   pop esi
// 008cd762  5d                   pop ebp
// 008cd763  8910                 mov dword ptr [eax], edx
// 008cd765  5b                   pop ebx
// 008cd766  c20c00               ret 0xc
// library mfc-9.0/atlmfc\src\mfc\afxcontextmenumanager.cpp (function ?GetNextAssoc@?$CMap@IIPAUHMENU__@@PAU1@@@QBEXAAPAU__POSITION@@AAIAAPAUHMENU__@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/afxcontextmenumanager.cpp
