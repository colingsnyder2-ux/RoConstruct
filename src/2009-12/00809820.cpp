// from server: 100% by auto
// roc 2009-12 00809820  unit: CXTPCommandBar  size: 137 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00809820
//
// 00809820  53                   push ebx
// 00809821  8b5904               mov ebx, dword ptr [ecx + 4]
// 00809824  85db                 test ebx, ebx
// 00809826  7505                 jne 0x80982d
// 00809828  e8dfa2feff           call 0x7f3b0c
// 0080982d  55                   push ebp
// 0080982e  8b6c240c             mov ebp, dword ptr [esp + 0xc]
// 00809832  56                   push esi
// 00809833  8b7500               mov esi, dword ptr [ebp]
// 00809836  85f6                 test esi, esi
// 00809838  7505                 jne 0x80983f
// 0080983a  e8cda2feff           call 0x7f3b0c
// 0080983f  57                   push edi
// 00809840  83feff               cmp esi, -1
// 00809843  751e                 jne 0x809863
// 00809845  8b7908               mov edi, dword ptr [ecx + 8]
// 00809848  33c0                 xor eax, eax
// 0080984a  85ff                 test edi, edi
// 0080984c  7615                 jbe 0x809863
// 0080984e  8bd3                 mov edx, ebx
// 00809850  8b32                 mov esi, dword ptr [edx]
// 00809852  85f6                 test esi, esi
// 00809854  750d                 jne 0x809863
// 00809856  40                   inc eax
// 00809857  83c204               add edx, 4
// 0080985a  3bc7                 cmp eax, edi
// 0080985c  72f2                 jb 0x809850
// 0080985e  e8a9a2feff           call 0x7f3b0c
// 00809863  8b7e08               mov edi, dword ptr [esi + 8]
// 00809866  85ff                 test edi, edi
// 00809868  7524                 jne 0x80988e
// 0080986a  8b4908               mov ecx, dword ptr [ecx + 8]
// 0080986d  8b460c               mov eax, dword ptr [esi + 0xc]
// 00809870  33d2                 xor edx, edx
// 00809872  f7f1                 div ecx
// 00809874  42                   inc edx
// 00809875  3bd1                 cmp edx, ecx
// 00809877  7315                 jae 0x80988e
// 00809879  8d0493               lea eax, [ebx + edx*4]
// 0080987c  8d642400             lea esp, [esp]
// 00809880  8b38                 mov edi, dword ptr [eax]
// 00809882  85ff                 test edi, edi
// 00809884  7508                 jne 0x80988e
// 00809886  42                   inc edx
// 00809887  83c004               add eax, 4
// 0080988a  3bd1                 cmp edx, ecx
// 0080988c  72f2                 jb 0x809880
// 0080988e  8b4c2418             mov ecx, dword ptr [esp + 0x18]
// 00809892  897d00               mov dword ptr [ebp], edi
// 00809895  8b06                 mov eax, dword ptr [esi]
// 00809897  8901                 mov dword ptr [ecx], eax
// 00809899  8b5604               mov edx, dword ptr [esi + 4]
// 0080989c  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 008098a0  5f                   pop edi
// 008098a1  5e                   pop esi
// 008098a2  5d                   pop ebp
// 008098a3  8910                 mov dword ptr [eax], edx
// 008098a5  5b                   pop ebx
// 008098a6  c20c00               ret 0xc
// library mfc-9.0/atlmfc\src\mfc\afxcontextmenumanager.cpp (function ?GetNextAssoc@?$CMap@IIPAUHMENU__@@PAU1@@@QBEXAAPAU__POSITION@@AAIAAPAUHMENU__@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/afxcontextmenumanager.cpp
