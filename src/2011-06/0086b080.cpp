// from server: 100% by auto
// roc 2011-06 0086b080  unit: CXTPPropertyGrid  size: 47 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 0086b080
//
// 0086b080  51                   push ecx
// 0086b081  8d442408             lea eax, [esp + 8]
// 0086b085  50                   push eax
// 0086b086  8b44240c             mov eax, dword ptr [esp + 0xc]
// 0086b08a  8d542404             lea edx, [esp + 4]
// 0086b08e  52                   push edx
// 0086b08f  50                   push eax
// 0086b090  e81b96bdff           call 0x4446b0
// 0086b095  85c0                 test eax, eax
// 0086b097  7504                 jne 0x86b09d
// 0086b099  59                   pop ecx
// 0086b09a  c20800               ret 8
// 0086b09d  8b4804               mov ecx, dword ptr [eax + 4]
// 0086b0a0  8b54240c             mov edx, dword ptr [esp + 0xc]
// 0086b0a4  890a                 mov dword ptr [edx], ecx
// 0086b0a6  b801000000           mov eax, 1
// 0086b0ab  59                   pop ecx
// 0086b0ac  c20800               ret 8
// library mfc-9.0/atlmfc\src\mfc\afxcmdusagecount.cpp (function ?Lookup@?$CMap@IIII@@QBEHIAAI@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/afxcmdusagecount.cpp
