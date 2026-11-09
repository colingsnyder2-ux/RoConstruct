// from server: 100% by auto
// roc 2008-06 00768e50  unit: XTPDockingPanePaintThemes::CXTPDockingPaneNativeXPTheme  size: 137 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 00768e50
//
// 00768e50  53                   push ebx
// 00768e51  8b5904               mov ebx, dword ptr [ecx + 4]
// 00768e54  85db                 test ebx, ebx
// 00768e56  7505                 jne 0x768e5d
// 00768e58  e8e77af3ff           call 0x6a0944
// 00768e5d  55                   push ebp
// 00768e5e  8b6c240c             mov ebp, dword ptr [esp + 0xc]
// 00768e62  56                   push esi
// 00768e63  8b7500               mov esi, dword ptr [ebp]
// 00768e66  85f6                 test esi, esi
// 00768e68  7505                 jne 0x768e6f
// 00768e6a  e8d57af3ff           call 0x6a0944
// 00768e6f  57                   push edi
// 00768e70  83feff               cmp esi, -1
// 00768e73  751e                 jne 0x768e93
// 00768e75  8b7908               mov edi, dword ptr [ecx + 8]
// 00768e78  33c0                 xor eax, eax
// 00768e7a  85ff                 test edi, edi
// 00768e7c  7615                 jbe 0x768e93
// 00768e7e  8bd3                 mov edx, ebx
// 00768e80  8b32                 mov esi, dword ptr [edx]
// 00768e82  85f6                 test esi, esi
// 00768e84  750d                 jne 0x768e93
// 00768e86  40                   inc eax
// 00768e87  83c204               add edx, 4
// 00768e8a  3bc7                 cmp eax, edi
// 00768e8c  72f2                 jb 0x768e80
// 00768e8e  e8b17af3ff           call 0x6a0944
// 00768e93  8b7e08               mov edi, dword ptr [esi + 8]
// 00768e96  85ff                 test edi, edi
// 00768e98  7524                 jne 0x768ebe
// 00768e9a  8b4908               mov ecx, dword ptr [ecx + 8]
// 00768e9d  8b460c               mov eax, dword ptr [esi + 0xc]
// 00768ea0  33d2                 xor edx, edx
// 00768ea2  f7f1                 div ecx
// 00768ea4  42                   inc edx
// 00768ea5  3bd1                 cmp edx, ecx
// 00768ea7  7315                 jae 0x768ebe
// 00768ea9  8d0493               lea eax, [ebx + edx*4]
// 00768eac  8d642400             lea esp, [esp]
// 00768eb0  8b38                 mov edi, dword ptr [eax]
// 00768eb2  85ff                 test edi, edi
// 00768eb4  7508                 jne 0x768ebe
// 00768eb6  42                   inc edx
// 00768eb7  83c004               add eax, 4
// 00768eba  3bd1                 cmp edx, ecx
// 00768ebc  72f2                 jb 0x768eb0
// 00768ebe  8b4c2418             mov ecx, dword ptr [esp + 0x18]
// 00768ec2  897d00               mov dword ptr [ebp], edi
// 00768ec5  8b06                 mov eax, dword ptr [esi]
// 00768ec7  8901                 mov dword ptr [ecx], eax
// 00768ec9  8b5604               mov edx, dword ptr [esi + 4]
// 00768ecc  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 00768ed0  5f                   pop edi
// 00768ed1  5e                   pop esi
// 00768ed2  5d                   pop ebp
// 00768ed3  8910                 mov dword ptr [eax], edx
// 00768ed5  5b                   pop ebx
// 00768ed6  c20c00               ret 0xc
// library mfc-9.0/atlmfc\src\mfc\afxcontextmenumanager.cpp (function ?GetNextAssoc@?$CMap@IIPAUHMENU__@@PAU1@@@QBEXAAPAU__POSITION@@AAIAAPAUHMENU__@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/afxcontextmenumanager.cpp
