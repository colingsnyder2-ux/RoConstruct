// from server: 100% by auto
// roc 2010-06 00404200  unit: ATL::CRegObject  size: 55 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00404200
//
// 00404200  8b542404             mov edx, dword ptr [esp + 4]
// 00404204  56                   push esi
// 00404205  8bf1                 mov esi, ecx
// 00404207  8b06                 mov eax, dword ptr [esi]
// 00404209  8b48f0               mov ecx, dword ptr [eax - 0x10]
// 0040420c  83e810               sub eax, 0x10
// 0040420f  395008               cmp dword ptr [eax + 8], edx
// 00404212  7d15                 jge 0x404229
// 00404214  85d2                 test edx, edx
// 00404216  7e11                 jle 0x404229
// 00404218  57                   push edi
// 00404219  8b39                 mov edi, dword ptr [ecx]
// 0040421b  6a01                 push 1
// 0040421d  52                   push edx
// 0040421e  50                   push eax
// 0040421f  8b4708               mov eax, dword ptr [edi + 8]
// 00404222  ffd0                 call eax
// 00404224  5f                   pop edi
// 00404225  85c0                 test eax, eax
// 00404227  7505                 jne 0x40422e
// 00404229  e8a2f8ffff           call 0x403ad0
// 0040422e  83c010               add eax, 0x10
// 00404231  8906                 mov dword ptr [esi], eax
// 00404233  5e                   pop esi
// 00404234  c20400               ret 4
// library mfc-9.0/atlmfc\src\mfc\afxacceleratorkey.cpp (function ?Reallocate@?$CSimpleStringT@D$0A@@ATL@@AAEXH@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/afxacceleratorkey.cpp
