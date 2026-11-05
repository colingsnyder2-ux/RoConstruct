// from server: 100% by auto
// roc 2009-12 004041b0  unit: ATL::CRegObject  size: 55 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 004041b0
//
// 004041b0  8b542404             mov edx, dword ptr [esp + 4]
// 004041b4  56                   push esi
// 004041b5  8bf1                 mov esi, ecx
// 004041b7  8b06                 mov eax, dword ptr [esi]
// 004041b9  8b48f0               mov ecx, dword ptr [eax - 0x10]
// 004041bc  83e810               sub eax, 0x10
// 004041bf  395008               cmp dword ptr [eax + 8], edx
// 004041c2  7d15                 jge 0x4041d9
// 004041c4  85d2                 test edx, edx
// 004041c6  7e11                 jle 0x4041d9
// 004041c8  57                   push edi
// 004041c9  8b39                 mov edi, dword ptr [ecx]
// 004041cb  6a01                 push 1
// 004041cd  52                   push edx
// 004041ce  50                   push eax
// 004041cf  8b4708               mov eax, dword ptr [edi + 8]
// 004041d2  ffd0                 call eax
// 004041d4  5f                   pop edi
// 004041d5  85c0                 test eax, eax
// 004041d7  7505                 jne 0x4041de
// 004041d9  e892f8ffff           call 0x403a70
// 004041de  83c010               add eax, 0x10
// 004041e1  8906                 mov dword ptr [esi], eax
// 004041e3  5e                   pop esi
// 004041e4  c20400               ret 4
// library mfc-9.0/atlmfc\src\mfc\afxacceleratorkey.cpp (function ?Reallocate@?$CSimpleStringT@D$0A@@ATL@@AAEXH@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/afxacceleratorkey.cpp
