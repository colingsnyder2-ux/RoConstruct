// from server: 100% by auto
// roc 2011-06 00404cc0  unit: ATL::CRegObject  size: 55 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 00404cc0
//
// 00404cc0  8b542404             mov edx, dword ptr [esp + 4]
// 00404cc4  56                   push esi
// 00404cc5  8bf1                 mov esi, ecx
// 00404cc7  8b06                 mov eax, dword ptr [esi]
// 00404cc9  8b48f0               mov ecx, dword ptr [eax - 0x10]
// 00404ccc  83e810               sub eax, 0x10
// 00404ccf  395008               cmp dword ptr [eax + 8], edx
// 00404cd2  7d15                 jge 0x404ce9
// 00404cd4  85d2                 test edx, edx
// 00404cd6  7e11                 jle 0x404ce9
// 00404cd8  57                   push edi
// 00404cd9  8b39                 mov edi, dword ptr [ecx]
// 00404cdb  6a01                 push 1
// 00404cdd  52                   push edx
// 00404cde  50                   push eax
// 00404cdf  8b4708               mov eax, dword ptr [edi + 8]
// 00404ce2  ffd0                 call eax
// 00404ce4  5f                   pop edi
// 00404ce5  85c0                 test eax, eax
// 00404ce7  7505                 jne 0x404cee
// 00404ce9  e882f6ffff           call 0x404370
// 00404cee  83c010               add eax, 0x10
// 00404cf1  8906                 mov dword ptr [esi], eax
// 00404cf3  5e                   pop esi
// 00404cf4  c20400               ret 4
// library mfc-9.0/atlmfc\src\mfc\afxacceleratorkey.cpp (function ?Reallocate@?$CSimpleStringT@D$0A@@ATL@@AAEXH@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/afxacceleratorkey.cpp
