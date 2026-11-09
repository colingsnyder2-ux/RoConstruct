// from server: 100% by auto
// roc 2009-06 00793070  unit: CXTPReportColumns  size: 137 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00793070
//
// 00793070  53                   push ebx
// 00793071  8b5904               mov ebx, dword ptr [ecx + 4]
// 00793074  85db                 test ebx, ebx
// 00793076  7505                 jne 0x79307d
// 00793078  e8675cf8ff           call 0x718ce4
// 0079307d  55                   push ebp
// 0079307e  8b6c240c             mov ebp, dword ptr [esp + 0xc]
// 00793082  56                   push esi
// 00793083  8b7500               mov esi, dword ptr [ebp]
// 00793086  85f6                 test esi, esi
// 00793088  7505                 jne 0x79308f
// 0079308a  e8555cf8ff           call 0x718ce4
// 0079308f  57                   push edi
// 00793090  83feff               cmp esi, -1
// 00793093  751e                 jne 0x7930b3
// 00793095  8b7908               mov edi, dword ptr [ecx + 8]
// 00793098  33c0                 xor eax, eax
// 0079309a  85ff                 test edi, edi
// 0079309c  7615                 jbe 0x7930b3
// 0079309e  8bd3                 mov edx, ebx
// 007930a0  8b32                 mov esi, dword ptr [edx]
// 007930a2  85f6                 test esi, esi
// 007930a4  750d                 jne 0x7930b3
// 007930a6  40                   inc eax
// 007930a7  83c204               add edx, 4
// 007930aa  3bc7                 cmp eax, edi
// 007930ac  72f2                 jb 0x7930a0
// 007930ae  e8315cf8ff           call 0x718ce4
// 007930b3  8b7e08               mov edi, dword ptr [esi + 8]
// 007930b6  85ff                 test edi, edi
// 007930b8  7524                 jne 0x7930de
// 007930ba  8b4908               mov ecx, dword ptr [ecx + 8]
// 007930bd  8b460c               mov eax, dword ptr [esi + 0xc]
// 007930c0  33d2                 xor edx, edx
// 007930c2  f7f1                 div ecx
// 007930c4  42                   inc edx
// 007930c5  3bd1                 cmp edx, ecx
// 007930c7  7315                 jae 0x7930de
// 007930c9  8d0493               lea eax, [ebx + edx*4]
// 007930cc  8d642400             lea esp, [esp]
// 007930d0  8b38                 mov edi, dword ptr [eax]
// 007930d2  85ff                 test edi, edi
// 007930d4  7508                 jne 0x7930de
// 007930d6  42                   inc edx
// 007930d7  83c004               add eax, 4
// 007930da  3bd1                 cmp edx, ecx
// 007930dc  72f2                 jb 0x7930d0
// 007930de  8b4c2418             mov ecx, dword ptr [esp + 0x18]
// 007930e2  897d00               mov dword ptr [ebp], edi
// 007930e5  8b06                 mov eax, dword ptr [esi]
// 007930e7  8901                 mov dword ptr [ecx], eax
// 007930e9  8b5604               mov edx, dword ptr [esi + 4]
// 007930ec  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 007930f0  5f                   pop edi
// 007930f1  5e                   pop esi
// 007930f2  5d                   pop ebp
// 007930f3  8910                 mov dword ptr [eax], edx
// 007930f5  5b                   pop ebx
// 007930f6  c20c00               ret 0xc
// library mfc-9.0/atlmfc\src\mfc\afxcontextmenumanager.cpp (function ?GetNextAssoc@?$CMap@IIPAUHMENU__@@PAU1@@@QBEXAAPAU__POSITION@@AAIAAPAUHMENU__@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/afxcontextmenumanager.cpp
