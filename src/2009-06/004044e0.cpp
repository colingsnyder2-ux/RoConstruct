// from server: 100% by auto
// roc 2009-06 004044e0  unit: ATL::CRegObject  size: 55 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 004044e0
//
// 004044e0  8b542404             mov edx, dword ptr [esp + 4]
// 004044e4  56                   push esi
// 004044e5  8bf1                 mov esi, ecx
// 004044e7  8b06                 mov eax, dword ptr [esi]
// 004044e9  8b48f0               mov ecx, dword ptr [eax - 0x10]
// 004044ec  83e810               sub eax, 0x10
// 004044ef  395008               cmp dword ptr [eax + 8], edx
// 004044f2  7d15                 jge 0x404509
// 004044f4  85d2                 test edx, edx
// 004044f6  7e11                 jle 0x404509
// 004044f8  57                   push edi
// 004044f9  8b39                 mov edi, dword ptr [ecx]
// 004044fb  6a01                 push 1
// 004044fd  52                   push edx
// 004044fe  50                   push eax
// 004044ff  8b4708               mov eax, dword ptr [edi + 8]
// 00404502  ffd0                 call eax
// 00404504  5f                   pop edi
// 00404505  85c0                 test eax, eax
// 00404507  7505                 jne 0x40450e
// 00404509  e852f7ffff           call 0x403c60
// 0040450e  83c010               add eax, 0x10
// 00404511  8906                 mov dword ptr [esi], eax
// 00404513  5e                   pop esi
// 00404514  c20400               ret 4
// library mfc-9.0/atlmfc\src\mfc\afxacceleratorkey.cpp (function ?Reallocate@?$CSimpleStringT@D$0A@@ATL@@AAEXH@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/afxacceleratorkey.cpp
