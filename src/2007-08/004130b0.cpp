// from server: 100% by auto
// roc 2007-08 004130b0  unit: std::runtime_error  size: 55 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 004130b0
//
// 004130b0  8b542404             mov edx, dword ptr [esp + 4]
// 004130b4  56                   push esi
// 004130b5  8bf1                 mov esi, ecx
// 004130b7  8b06                 mov eax, dword ptr [esi]
// 004130b9  8b48f0               mov ecx, dword ptr [eax - 0x10]
// 004130bc  83e810               sub eax, 0x10
// 004130bf  395008               cmp dword ptr [eax + 8], edx
// 004130c2  7d15                 jge 0x4130d9
// 004130c4  85d2                 test edx, edx
// 004130c6  7e11                 jle 0x4130d9
// 004130c8  57                   push edi
// 004130c9  8b39                 mov edi, dword ptr [ecx]
// 004130cb  6a01                 push 1
// 004130cd  52                   push edx
// 004130ce  50                   push eax
// 004130cf  8b4708               mov eax, dword ptr [edi + 8]
// 004130d2  ffd0                 call eax
// 004130d4  85c0                 test eax, eax
// 004130d6  5f                   pop edi
// 004130d7  7505                 jne 0x4130de
// 004130d9  e842feffff           call 0x412f20
// 004130de  83c010               add eax, 0x10
// 004130e1  8906                 mov dword ptr [esi], eax
// 004130e3  5e                   pop esi
// 004130e4  c20400               ret 4
// library mfc-8.0/atlmfc\src\mfc\afxstate.cpp (function ?Reallocate@?$CSimpleStringT@D$0A@@ATL@@AAEXH@Z)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-8.0 atlmfc/src/mfc/afxstate.cpp
