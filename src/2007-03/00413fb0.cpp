// from server: 100% by auto
// roc 2007-03 00413fb0  unit: seg_00410000  size: 55 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 00413fb0
//
// 00413fb0  8b542404             mov edx, dword ptr [esp + 4]
// 00413fb4  56                   push esi
// 00413fb5  8bf1                 mov esi, ecx
// 00413fb7  8b06                 mov eax, dword ptr [esi]
// 00413fb9  8b48f0               mov ecx, dword ptr [eax - 0x10]
// 00413fbc  83e810               sub eax, 0x10
// 00413fbf  395008               cmp dword ptr [eax + 8], edx
// 00413fc2  7d15                 jge 0x413fd9
// 00413fc4  85d2                 test edx, edx
// 00413fc6  7e11                 jle 0x413fd9
// 00413fc8  57                   push edi
// 00413fc9  8b39                 mov edi, dword ptr [ecx]
// 00413fcb  6a01                 push 1
// 00413fcd  52                   push edx
// 00413fce  50                   push eax
// 00413fcf  8b4708               mov eax, dword ptr [edi + 8]
// 00413fd2  ffd0                 call eax
// 00413fd4  85c0                 test eax, eax
// 00413fd6  5f                   pop edi
// 00413fd7  7505                 jne 0x413fde
// 00413fd9  e862feffff           call 0x413e40
// 00413fde  83c010               add eax, 0x10
// 00413fe1  8906                 mov dword ptr [esi], eax
// 00413fe3  5e                   pop esi
// 00413fe4  c20400               ret 4
// library mfc-8.0/atlmfc\src\mfc\afxstate.cpp (function ?Reallocate@?$CSimpleStringT@D$0A@@ATL@@AAEXH@Z)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-8.0 atlmfc/src/mfc/afxstate.cpp
