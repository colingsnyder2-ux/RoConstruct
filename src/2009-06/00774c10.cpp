// from server: 100% by auto
// roc 2009-06 00774c10  unit: CXTPPropertyGrid  size: 47 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00774c10
//
// 00774c10  51                   push ecx
// 00774c11  8d442408             lea eax, [esp + 8]
// 00774c15  50                   push eax
// 00774c16  8b44240c             mov eax, dword ptr [esp + 0xc]
// 00774c1a  8d542404             lea edx, [esp + 4]
// 00774c1e  52                   push edx
// 00774c1f  50                   push eax
// 00774c20  e87bd6cbff           call 0x4322a0
// 00774c25  85c0                 test eax, eax
// 00774c27  7504                 jne 0x774c2d
// 00774c29  59                   pop ecx
// 00774c2a  c20800               ret 8
// 00774c2d  8b4804               mov ecx, dword ptr [eax + 4]
// 00774c30  8b54240c             mov edx, dword ptr [esp + 0xc]
// 00774c34  890a                 mov dword ptr [edx], ecx
// 00774c36  b801000000           mov eax, 1
// 00774c3b  59                   pop ecx
// 00774c3c  c20800               ret 8
// library mfc-9.0/atlmfc\src\mfc\afxcmdusagecount.cpp (function ?Lookup@?$CMap@IIII@@QBEHIAAI@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/afxcmdusagecount.cpp
